#include "gunmessenger.hpp"
#include "pga.hpp"
#include "G4UnitsTable.hh"

namespace msrfeed {
  GunMessenger::GunMessenger(PGA* pga_gun):
    m_pga_gun(pga_gun)
  {
    // Directory: /ne697/gun
    m_directory = new G4UIdirectory("/ne697/gun/");
    m_directory->SetGuidance("Change offset of the particle gun.");

    // Set gun offset: /ne697/gun/offset
    m_gunOffsetCmd = new G4UIcmdWithADoubleAndUnit("/ne697/gun/offset", this);
    m_gunOffsetCmd->SetGuidance("Set the offset of the particle gun from the 'T'.");
    m_gunOffsetCmd->SetParameterName("offset", true);
    m_gunOffsetCmd->SetDefaultValue(m_pga_gun->get_gun_offset());
    m_gunOffsetCmd->AvailableForStates(G4State_PreInit, G4State_Idle);
  }

  GunMessenger::~GunMessenger() {
    delete m_directory;
    delete m_gunOffsetCmd;
  }

  void GunMessenger::SetNewValue(G4UIcommand* cmd, G4String val) {
    if (cmd == m_gunOffsetCmd) {

      auto parsed_val = m_gunOffsetCmd->GetNewDoubleValue(val);
      
      //error if negative offset
      if (parsed_val < 0) {
      G4cerr << "Gun offset cannot be negative! Offset not applied." << G4endl;
      return;
      }
      
      m_pga_gun->set_gun_offset(parsed_val);
      G4cout << "Gun offset set to " << G4BestUnit(parsed_val, "Length")
        << G4endl;
    }

    // Command didn't match
    return;
  }
}