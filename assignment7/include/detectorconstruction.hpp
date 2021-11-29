#ifndef DETECTOR_CONSTRUCTION_HPP
#define DETECTOR_CONSTRUCTION_HPP
#include "G4VUserDetectorConstruction.hh"
#include "G4PVPlacement.hh"
#include "G4LogicalVolume.hh"

namespace ne697 {
  // Forward declaration, to resolve circular dependency with GeometryMessenger
  // You still need to #include "geometrymessenger.hpp" in
  // detectorconstruction.cpp
  class GeometryMessenger;

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

    private:
      // Only called once in the constructor. Once we build them, they insert
      // themselves into Geant4's global database of G4Material objects, then
      // we can ask for them anywhere in the code by name
      void build_materials();

      // List of G4LogicalVolumes we want to connect to the SensitiveDetector
      std::vector<G4LogicalVolume*> m_trackingVols;

      GeometryMessenger* m_messenger;

      // Variables we will be modifying from the UI, so we want them to be
      // attached to DetectorConstruction. Then, when Construct() is called,
      // m_detSize holds whatever value the user set
      G4double m_detSize;
      G4double m_detThickness;
  };
}

#endif