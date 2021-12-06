#ifndef GEOMETRY_MESSENGER_HPP
#define GEOMETRY_MESSENGER_HPP
#include "G4UImessenger.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"

namespace msrfeed {
  // Forward declaration, to resolve circular dependency with DetectorConstruction
  // You still need to #include "detectorconstruction.hpp" in
  // geometrymessenger.cpp
  class DetectorConstruction;

  // User-facing part of the UI: just for the user
  class GeometryMessenger: public G4UImessenger {
  public:
    GeometryMessenger(DetectorConstruction* dc);
    ~GeometryMessenger();

    void SetNewValue(G4UIcommand* cmd, G4String val) override final;

  private:
    DetectorConstruction* m_dc;
    G4UIdirectory* m_directory;
    G4UIcmdWithADoubleAndUnit* m_detThicknessCmd;
    G4UIcmdWithADoubleAndUnit* m_detSizeCmd;
    G4UIcmdWithADoubleAndUnit* m_detStandoffCmd;
  };  
}

#endif
