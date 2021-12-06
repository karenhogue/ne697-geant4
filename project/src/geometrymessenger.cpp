#include "geometrymessenger.hpp"
#include "detectorconstruction.hpp"
#include "G4UnitsTable.hh"

namespace msrfeed {
  GeometryMessenger::GeometryMessenger(DetectorConstruction* dc):
    m_dc(dc)
  {
    // Directory: /ne697/geometry
    m_directory = new G4UIdirectory("/ne697/geometry/");
    m_directory->SetGuidance("Change thickness, size, and standoff distance of the detector.");

    // Set detector thickness: /ne697/geometry/det_thickness
    m_detThicknessCmd = new G4UIcmdWithADoubleAndUnit("/ne697/geometry/det_thickness", this);
    m_detThicknessCmd->SetGuidance("Set the full thickness of the detector panel.");
    m_detThicknessCmd->SetParameterName("thickness", true);
    m_detThicknessCmd->SetDefaultValue(m_dc->get_det_thickness());
    m_detThicknessCmd->AvailableForStates(G4State_PreInit);

    // Set detector size: /ne697/geometry/det_size
    m_detSizeCmd = new G4UIcmdWithADoubleAndUnit("/ne697/geometry/det_size", this);
    m_detSizeCmd->SetGuidance("Set the full x and z extents of the square detector panel.");
    m_detSizeCmd->SetParameterName("x", true);
    m_detSizeCmd->SetDefaultValue(m_dc->get_det_size());
    m_detSizeCmd->AvailableForStates(G4State_PreInit);

    // Set detector standoff distance: /ne697/geometry/det_standoff
    m_detStandoffCmd = new G4UIcmdWithADoubleAndUnit("/ne697/geometry/det_standoff", this);
    m_detStandoffCmd->SetGuidance("Set the standoff distance of the detector from the pipe.");
    m_detStandoffCmd->SetParameterName("standoff", true);
    m_detStandoffCmd->SetDefaultValue(m_dc->get_det_standoff());
    m_detStandoffCmd->AvailableForStates(G4State_PreInit);
  }

  GeometryMessenger::~GeometryMessenger() {
    delete m_directory;
    delete m_detThicknessCmd;
    delete m_detSizeCmd;
    delete m_detStandoffCmd;
  }

  void GeometryMessenger::SetNewValue(G4UIcommand* cmd, G4String val) {
    if (cmd == m_detThicknessCmd) {
      auto parsed_val = m_detThicknessCmd->GetNewDoubleValue(val);

      //error if negative thickness
      if (parsed_val < 0) {
      G4cerr << "Detector thickness cannot be negative! Given thickness not applied." << G4endl;
      return;
      }
      
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

    if (cmd == m_detStandoffCmd) {
      auto parsed_val = m_detStandoffCmd->GetNewDoubleValue(val);
      m_dc->set_det_standoff(parsed_val);
      G4cout << "Detector standoff distance set to " << G4BestUnit(parsed_val, "Length")
        << G4endl;
    }
    // Command didn't match
    return;
  }
}