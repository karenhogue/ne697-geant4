#include "detectorconstruction.hpp"
#include "globals.hh"
#include "G4Box.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh"
#include "sensitivedetector.hpp"
#include "G4SDManager.hh"
#include "geometrymessenger.hpp"
#include "materialmessenger.hpp"

namespace ne697 {
  DetectorConstruction::DetectorConstruction():
    G4VUserDetectorConstruction(),
    m_trackingVols(),
    m_detSize(50.*cm),
    m_detThickness(5.*cm),
    m_detMaterial("G4_SODIUM_IODIDE")
  {
    G4cout << "Creating DetectorConstruction" << G4endl;
    m_geom_messenger = new GeometryMessenger(this);
    m_mat_messenger = new MaterialMessenger(this);
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
    // Commented since we don't want to record Hits in the world's air volume
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

    // ***** T of tungsten: center pillar
    auto T_pillar_solid = new G4Box("T_solid", 5.*cm, 1.*cm, 20.*cm);
    auto T_pillar_mat = nist->FindOrBuildMaterial("G4_W");
    auto T_pillar_log = new G4LogicalVolume(
        T_pillar_solid, 
        T_pillar_mat, 
        "T_pillar_log"
    );
    new G4PVPlacement(
      nullptr,
      G4ThreeVector(0., 0., 0.),
      T_pillar_log,
      "T_pillar_phys",
      world_log,
      false,
      0,
      true
    );
    // ***** T of tungsten: wings
    auto T_wing_solid = new G4Box("T_wing_solid", 5.*cm, 1.*cm, 5.*cm);
    auto T_wing_mat = nist->FindOrBuildMaterial("G4_W");
    auto T_wing_log = new G4LogicalVolume(
        T_wing_solid, 
        T_wing_mat, 
        "T_wing_log"
    );
    new G4PVPlacement(
      nullptr,
      G4ThreeVector(10.*cm, 0., 15.*cm),
      T_wing_log,
      "T_wing_phys",
      world_log,
      false,
      0,
      true
    );
    new G4PVPlacement(
      nullptr,
      G4ThreeVector(-10.*cm, 0., 15.*cm),
      T_wing_log,
      "T_wing_phys",
      world_log,
      false,
      0,
      true
    );

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
      G4ThreeVector(0, -30.*cm, 0),
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

  void DetectorConstruction::set_det_material(G4String const& detmaterial) {
    m_detMaterial = detmaterial;
    return;
  }

  G4String const& DetectorConstruction::get_det_material() const {
    return m_detMaterial;
  }
}