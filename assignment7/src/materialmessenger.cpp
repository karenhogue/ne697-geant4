#include "materialmessenger.hpp"
#include "detectorconstruction.hpp"
#include "G4UnitsTable.hh"

namespace ne697 {
  MaterialMessenger::MaterialMessenger(DetectorConstruction* dc):
    m_dc(dc)
  {
    // Directory: /ne697/geometry
    m_directory = new G4UIdirectory("/ne697/material/");
    m_directory->SetGuidance("Change material.");

    // Set detector material: /ne697/geometry/det_thickness
    m_detMaterialCmd = new G4UIcmdWithAString("/ne697/geometry/det_material", this);
    m_detMaterialCmd->SetGuidance("Set the detector material.");
    m_detMaterialCmd->SetParameterName("material", true);
    m_detMaterialCmd->SetDefaultValue(m_dc->get_det_material());
    m_detMaterialCmd->AvailableForStates(G4State_PreInit);

  }

  MaterialMessenger::~MaterialMessenger() {
    delete m_directory;
    delete m_detMaterialCmd;
  }

  void MaterialMessenger::SetNewValue(G4UIcommand* cmd, G4String val) {
    if (cmd == m_detMaterialCmd) {
      m_dc->set_det_material(val);
      G4cout << "Detector material set to " << val << G4endl;
    }
    // Command didn't match
    return;
  }
}