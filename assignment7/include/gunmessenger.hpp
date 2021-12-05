#ifndef GUN_MESSENGER_HPP
#define GUN_MESSENGER_HPP
#include "G4UImessenger.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"

namespace ne697 {
  // Forward declaration, to resolve circular dependency with DetectorConstruction
  class PGA;

  // User-facing part of the UI: just for the user
  class GunMessenger: public G4UImessenger {
  public:
    GunMessenger(PGA* pga_gun);
    ~GunMessenger();

    void SetNewValue(G4UIcommand* cmd, G4String val) override final;

  private:
    PGA* m_pga_gun;
    G4UIdirectory* m_directory;
    G4UIcmdWithADoubleAndUnit* m_gunOffsetCmd;
  };  
}

#endif