#include "geometrymessenger.hpp"
#include "detectorconstruction.hpp"
#include "G4UnitsTable.hh"

namespace ne697 {
  GeometryMessenger::GeometryMessenger(DetectorConstruction* dc):
    m_dc(dc)
  {
    // Directory: /ne697/geometry
    m_directory = new G4UIdirectory("/ne697/geometry/");
    m_directory->SetGuidance("Change thickness and size of the detector geometry.");

    // Set detector thickness: /ne697/geometry/det_thickness
    m_detThicknessCmd = new G4UIcmdWithADoubleAndUnit("/ne697/geometry/det_thickness", this);
    m_detThicknessCmd->SetGuidance("Set the full thickness of the detector panel.");
    m_detThicknessCmd->SetParameterName("thickness", true);
    m_detThicknessCmd->SetDefaultValue(m_dc->get_det_thickness()); //TODO - set to 5cm 
    m_detThicknessCmd->AvailableForStates(G4State_PreInit);

    // Set detector size: /ne697/geometry/det_size
    m_detSizeCmd = new G4UIcmdWithADoubleAndUnit("/ne697/geometry/det_size", this);
    m_detSizeCmd->SetGuidance("Set the full x and z extents of the square detector panel.");
    m_detSizeCmd->SetParameterName("x", true);
    m_detSizeCmd->SetDefaultValue(m_dc->get_det_size()); //TODO - set to 50cm
    m_detSizeCmd->AvailableForStates(G4State_PreInit);
  }

  GeometryMessenger::~GeometryMessenger() {
    delete m_directory;
    delete m_detSizeCmd;
  }

  void GeometryMessenger::SetNewValue(G4UIcommand* cmd, G4String val) {
    if (cmd == m_detThicknessCmd) {
      auto parsed_val = m_detThicknessCmd->GetNewDoubleValue(val);
      m_dc->set_det_thickness(parsed_val);
      G4cout << "Detector thickness set to " << G4BestUnit(parsed_val, "Length")
        << G4endl;
    }

    if (cmd == m_detSizeCmd) {
      auto parsed_val = m_detSizeCmd->GetNewDoubleValue(val);
      m_dc->set_det_size(parsed_val);
      G4cout << "Detector size set to " << G4BestUnit(parsed_val, "Length")
        << G4endl;
    }
    // Command didn't match
    return;
  }
}
