#ifndef DETECTOR_CONSTRUCTION_HPP
#define DETECTOR_CONSTRUCTION_HPP
#include "G4VUserDetectorConstruction.hh"
#include "G4PVPlacement.hh"
#include "G4LogicalVolume.hh"

namespace msrfeed {
  // Forward declaration, to resolve circular dependency with GeometryMessenger
  // You still need to #include "geometrymessenger.hpp" in
  // detectorconstruction.cpp
  class GeometryMessenger;
  class MaterialMessenger;

  class DetectorConstruction: public G4VUserDetectorConstruction {
    public:
      DetectorConstruction();
      ~DetectorConstruction();

      // Geant4 overrides
      // Solids, Logical Volumes, and Placements
      G4PVPlacement* Construct() override final;
      // SensitiveDetectors (and fields, which we aren't using)
      void ConstructSDandField() override final;

      // Code-facing part of the UI - storing and modifying the variables used
      // when doing Geant4 things (building objects, defining materials,
      // generating particles, etc, depending on the Target)
      void set_det_thickness(G4double const& detthickness);
      G4double const& get_det_thickness() const;
      void set_det_size(G4double const& detsize);
      G4double const& get_det_size() const;
      void set_det_standoff(G4double const& detstandoff);
      G4double const& get_det_standoff() const;
      void set_det_material(G4String const& detmaterial);
      G4String const& get_det_material() const;   
      void set_salt_material(G4String const& saltmaterial);
      G4String const& get_salt_material() const;   
      G4double const& get_U_enrichment() const;
      void set_U_enrichment(G4double const& Uenrichment);  

    private:
      void build_materials();
      // List of G4LogicalVolumes we want to connect to the SensitiveDetector
      std::vector<G4LogicalVolume*> m_trackingVols;

      GeometryMessenger* m_geom_messenger;
      MaterialMessenger* m_mat_messenger;

      // Variables we will be modifying from the UI, so we want them to be
      // attached to DetectorConstruction. Then, when Construct() is called,
      // these variables hold whatever value the user set
      G4double m_detSize;
      G4double m_detThickness;
      G4double m_detStandoff;
      G4String m_detMaterial;
      G4double m_UEnrichment;
      G4String m_saltMaterial;
      G4double m_innerDiam;
      G4double m_outerDiam;
  };
}

#endif