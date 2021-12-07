#include "materialmessenger.hpp"
#include "detectorconstruction.hpp"
#include "G4UnitsTable.hh"

namespace msrfeed {
  MaterialMessenger::MaterialMessenger(DetectorConstruction* dc):
    m_dc(dc)
  {
    // Directory: /ne697/material
    m_directory = new G4UIdirectory("/ne697/material/");
    m_directory->SetGuidance("Change material.");

    // Set detector material: /ne697/material/det_material
    m_detMaterialCmd = new G4UIcmdWithAString("/ne697/material/det_material", this);
    m_detMaterialCmd->SetGuidance("Set the detector material.");
    m_detMaterialCmd->SetParameterName("detector_material", true);
    m_detMaterialCmd->SetDefaultValue(m_dc->get_det_material());
    m_detMaterialCmd->AvailableForStates(G4State_PreInit);

    // Set salt material: /ne697/material/salt_material
    m_saltMaterialCmd = new G4UIcmdWithAString("/ne697/material/salt_material", this);
    m_saltMaterialCmd->SetGuidance("Set the salt material.");
    m_saltMaterialCmd->SetParameterName("salt_material", true);
    m_saltMaterialCmd->SetDefaultValue(m_dc->get_salt_material());
    m_saltMaterialCmd->AvailableForStates(G4State_PreInit);

    // Set U enrichment: /ne697/material/Uenrichment
    m_UEnrichmentCmd = new G4UIcmdWithADoubleAndUnit("/ne697/material/U_enrichment", this);
    m_UEnrichmentCmd->SetGuidance("Set the U enrichment in the salt.");
    m_UEnrichmentCmd->SetParameterName("U_enrichment", true);
    m_UEnrichmentCmd->SetDefaultValue(m_dc->get_U_enrichment());
    m_UEnrichmentCmd->AvailableForStates(G4State_PreInit, G4State_Idle);
  }

  MaterialMessenger::~MaterialMessenger() {
    delete m_directory;
    delete m_detMaterialCmd;
    delete m_saltMaterialCmd;
    delete m_UEnrichmentCmd;
  }

  void MaterialMessenger::SetNewValue(G4UIcommand* cmd, G4String val) {
    if (cmd == m_detMaterialCmd) {
      m_dc->set_det_material(val);
      G4cout << "Detector material set to " << val << G4endl;
    }
    if (cmd == m_saltMaterialCmd) {
      m_dc->set_salt_material(val);
      G4cout << "Salt material set to " << val << G4endl;
    }
    if (cmd == m_UEnrichmentCmd) {
      auto parsed_val = m_UEnrichmentCmd->GetNewDoubleValue(val);
      m_dc->set_U_enrichment(parsed_val);
      G4cout << "U enrichment in salt set to " << val << G4endl;
    }
    // Command didn't match
    return;
  }
}