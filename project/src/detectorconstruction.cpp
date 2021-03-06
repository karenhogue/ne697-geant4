#include "detectorconstruction.hpp"
#include "globals.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh"
#include "sensitivedetector.hpp"
#include "G4SDManager.hh"
#include "geometrymessenger.hpp"
#include "materialmessenger.hpp"

namespace msrfeed {
  DetectorConstruction::DetectorConstruction():
    G4VUserDetectorConstruction(),
    m_trackingVols(),
    m_detSize(50.*cm),
    m_detThickness(5.*cm),
    m_detStandoff(2.*cm),
    m_detMaterial("G4_SODIUM_IODIDE"),
    m_UEnrichment(19.75*perCent),
    m_saltMaterial("FLiBe"),
    m_innerDiam(15.024*cm),
    m_outerDiam(m_innerDiam+2.54)
  {
    G4cout << "Creating DetectorConstruction" << G4endl;
    m_geom_messenger = new GeometryMessenger(this);
    m_mat_messenger = new MaterialMessenger(this);
    build_materials();
  }

  DetectorConstruction::~DetectorConstruction() {
    G4cout << "Deleting DetectorConstruction" << G4endl;
    delete m_geom_messenger;
    delete m_mat_messenger;
  }

  G4PVPlacement* DetectorConstruction::Construct() {
    auto world_solid = new G4Box("world_solid", 1.*m, 1.*m, 1.*m);
    auto nist = G4NistManager::Instance();
    auto world_mat = nist->FindOrBuildMaterial("G4_AIR");
    auto world_log = new G4LogicalVolume(
        world_solid,
        world_mat,
        "world_log"
    );

    auto world_phys = new G4PVPlacement(
        nullptr,
        G4ThreeVector(0, 0, 0),
        world_log,
        "world_phys",
        nullptr,
        false,
        0,
        true
    );

    // ***** pipe
    auto pipe_solid = new G4Tubs("pipe_solid", m_innerDiam, m_outerDiam, 40.*cm, 0.*deg, 360.*deg);
    auto pipe_mat = nist->FindOrBuildMaterial("hastelloy"); 
    auto pipe_log = new G4LogicalVolume(
        pipe_solid, 
        pipe_mat, 
        "pipe_log"
    );
    new G4PVPlacement(
      nullptr,
      G4ThreeVector(0., 0., 0.),
      pipe_log,
      "pipe_phys",
      world_log,
      false,
      0,
      true
    );
    // ***** salt inside pipe
    auto salt_solid = new G4Tubs("salt_solid", 0.*cm, 20.*cm, 40.*cm, 0.*deg, 360.*deg);
    auto salt_mat = nist->FindOrBuildMaterial(m_saltMaterial);
    auto salt_log = new G4LogicalVolume(
        salt_solid, 
        salt_mat, 
        "salt_log"
    );
    new G4PVPlacement(
      nullptr,
      G4ThreeVector(0.*cm, 0., 0.*cm),
      salt_log,
      "salt_phys",
      world_log,
      false,
      0,
      true
    );
    // Detector
    auto det_solid = new G4Box("det_solid",
      m_detSize * 0.5,
      m_detThickness * 0.5,
      m_detSize * 0.5);
    auto det_mat = nist->FindOrBuildMaterial(m_detMaterial);
    auto det_log = new G4LogicalVolume(det_solid, det_mat, "det_log");
    // Tracking Hits in this volume
    m_trackingVols.push_back(det_log);
    new G4PVPlacement(
      nullptr,
      G4ThreeVector(0., (m_outerDiam + m_detStandoff + 0.5*m_detThickness), 0.), 
      det_log,
      "det_phys",
      world_log,
      false,
      0,
      true
    );
    return world_phys;
  }

  void DetectorConstruction::ConstructSDandField() {
    // We will ask for "world_sd_hits" later in Run::RecordEvent()
    auto sd = new SensitiveDetector("world_sd");
    G4SDManager::GetSDMpointer()->AddNewDetector(sd);
    // Connect the sensitive detector to all of the logical volumes on the list
    for (auto& log : m_trackingVols) {
      SetSensitiveDetector(log, sd);
    }
    return;
  }

  void DetectorConstruction::build_materials() {
    G4double z, a, fractionmass, density;
    G4String name, symbol;
    G4int ncomponents, natoms;

    //****************build FLiBe-U salt
    a = 6.941*g/mole; //ASSUMPTION: this assumes natural Li, not enriched
    auto elLi = new G4Element(name="Lithium", symbol="Li", z=3., a);
    a = 18.9984032*g/mole;
    auto elF = new G4Element(name="Fluorine", symbol="F", z=9., a);
    a = 9.012182*g/mole;
    auto elBe = new G4Element(name="Beryllium", symbol="Be", z=4., a);
    a = (m_UEnrichment*235 + (1-m_UEnrichment)*238)*g/mole;
    G4cout << "a of U = " << a << G4endl;
    auto elU = new G4Element(name="Uranium", symbol="U", z=92., a);
    a = 91.224*g/mole;
    auto elZr = new G4Element(name="Zirconium", symbol="Zr", z=40., a);

    //define compounds as materials
    density = 2.2409*g/cm3; // this is density of the FLiBe salt at 973K -- this may need to be T dependent and looked up for each compound to be more accurate
    
    auto LiF = new G4Material(name="LiF", density, ncomponents=2);
    LiF->AddElement(elLi, natoms=1);
    LiF->AddElement(elF, natoms=1);

    auto BeF2 = new G4Material(name="BeF2", density, ncomponents=2);
    BeF2->AddElement(elBe, natoms=1);
    BeF2->AddElement(elF, natoms=2);

    auto UF4 = new G4Material(name="UF4", density, ncomponents=2);
    UF4->AddElement(elU, natoms=1);
    UF4->AddElement(elF, natoms=4);

    auto ZrF4 = new G4Material(name="ZrF4", density, ncomponents=2);
    ZrF4->AddElement(elZr, natoms=1);
    ZrF4->AddElement(elF, natoms=4);

    //define FLiBe built out of compounds
    density = 2.2409*g/cm3; // this is density of the FLiBe salt at 973K -- could incorporate T dependence (2.575-0.000513*T)
    auto FLiBe = new G4Material("FLiBe", density, ncomponents=4);
    FLiBe->AddMaterial(LiF, fractionmass=3.042352114*perCent); 
    FLiBe->AddMaterial(BeF2, fractionmass=2.598514162*perCent); 
    FLiBe->AddMaterial(UF4, fractionmass=0.465490661*perCent); 
    FLiBe->AddMaterial(ZrF4, fractionmass=1.466739176*perCent); 
  
    //********************build chloride salt - based on molarity of MCRE salt
    a = 35.453*g/mole; //ASSUMPTION: this assumes natural Cl, not enriched
    auto elCl= new G4Element(name="Chlorine", symbol="Cl", z=17., a);
    a = 22.989770*g/mole;
    auto elNa = new G4Element(name="Sodium", symbol="Na", z=11., a);

    //define compounds as materials
    density = 2.340*g/cm3; // this is an assumed density (based on a UCl3-NaCl - PuCl3)
    
    auto NaCl = new G4Material(name="NaCl", density, ncomponents=2);
    NaCl->AddElement(elNa, natoms=1);
    NaCl->AddElement(elCl, natoms=1);

    auto UCl3 = new G4Material(name="UCl3", density, ncomponents=2);
    UCl3->AddElement(elU, natoms=1);
    UCl3->AddElement(elCl, natoms=3);

    //define chloride salt
    density = 2.340*g/cm3; // this is incorrect - based on assumption for UCl3-NaCl-PuCl3
    auto Clsalt = new G4Material("Clsalt", density, ncomponents=2);
    Clsalt->AddMaterial(NaCl, fractionmass=9.720172782*perCent); 
    Clsalt->AddMaterial(UCl3, fractionmass=28.21245221*perCent); 

    //***************build hastelloy for piping
    
    a = 58.6934*g/mole; 
    auto elNi= new G4Element(name="Nickel", symbol="Ni", z=28., a);
    a = 51.99616*g/mole;
    auto elCr = new G4Element(name="Chromium", symbol="Cr", z=11., a);
    a = 95.942*g/mole; 
    auto elMo = new G4Element(name="Molybdenum", symbol="Mo", z=42., a);
    a = 55.8452*g/mole;
    auto elFe = new G4Element(name="Iron", symbol="Fe", z=26., a);
    a = 28.08553*g/mole; 
    auto elSi= new G4Element(name="Silicon", symbol="Si", z=14., a);
    a = 54.9380499*g/mole;
    auto elMn = new G4Element(name="Manganese", symbol="Mn", z=25., a);
    a = 12.01078*g/mole; 
    auto elC= new G4Element(name="Carbon", symbol="C", z=6., a);
        
    density = 8.86*g/cm3; // this is at room temperature (22C)
    auto hastelloy = new G4Material("hastelloy", density, ncomponents=7);
    hastelloy->AddElement(elNi, fractionmass=70.12*perCent);
    hastelloy->AddElement(elCr, fractionmass=7.*perCent);
    hastelloy->AddElement(elMo, fractionmass=16.*perCent);
    hastelloy->AddElement(elFe, fractionmass=5.*perCent);
    hastelloy->AddElement(elSi, fractionmass=1.*perCent);
    hastelloy->AddElement(elMn, fractionmass=0.80*perCent);
    hastelloy->AddElement(elC, fractionmass=0.08*perCent);
  }

  void DetectorConstruction::set_det_size(G4double const& detsize) {
    m_detSize = detsize;
    return;
  }

  G4double const& DetectorConstruction::get_det_size() const {
    return m_detSize;
  }
  
  void DetectorConstruction::set_det_thickness(G4double const& detthickness) {
    m_detThickness = detthickness;
    return;
  }

  G4double const& DetectorConstruction::get_det_thickness() const {
    return m_detThickness;
  }

  void DetectorConstruction::set_det_standoff(G4double const& detstandoff) {
    m_detStandoff = detstandoff;
    return;
  }

  G4double const& DetectorConstruction::get_det_standoff() const {
    return m_detStandoff;
  }

  void DetectorConstruction::set_det_material(G4String const& detmaterial) { 
    m_detMaterial = detmaterial;
    return;
  }

  G4String const& DetectorConstruction::get_det_material() const {
    return m_detMaterial;
  }

  void DetectorConstruction::set_salt_material(G4String const& saltmaterial) { 
    m_saltMaterial = saltmaterial;
    return;
  }

  G4String const& DetectorConstruction::get_salt_material() const {
    return m_saltMaterial;
  }

  void DetectorConstruction::set_U_enrichment(G4double const& Uenrichment) { 
    m_UEnrichment = Uenrichment;
    return;
  }

  G4double const& DetectorConstruction::get_U_enrichment() const {
    return m_UEnrichment;
  }
}