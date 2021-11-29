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
    m_detThicknessCmd = new G4UIcmdWithADoubleAndUnit("/ne697/geometry/det_material", this);
    m_detThicknessCmd->SetGuidance("Set the detector material.");
    m_detThicknessCmd->SetParameterName("material", true);
    m_detThicknessCmd->SetDefaultValue(m_dc->get_det_material());
    m_detThicknessCmd->AvailableForStates(G4State_PreInit);

  }

  MaterialMessenger::~MaterialMessenger() {
    delete m_directory;
    delete m_detMaterialCmd;
  }

  void MaterialMessenger::SetNewValue(G4UIcommand* cmd, G4String val) {
    if (cmd == m_detMaterialCmd) {
      auto parsed_val = m_detMaterialCmd->GetNewStringValue(val);
      m_dc->set_det_material(parsed_val);
      G4cout << "Detector material set to " << G4endl;
    }
    // Command didn't match
    return;
  }
}