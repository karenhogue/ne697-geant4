#include "pga.hpp"
#include "G4Gamma.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"

namespace msrfeed {
  PGA::PGA():
    G4VUserPrimaryGeneratorAction(),
    m_gun(new G4GeneralParticleSource())
  {
    G4cout << "Creating PGA" << G4endl;
 
  }

  PGA::~PGA() {
    G4cout << "Deleting PGA" << G4endl;
    delete m_gun;
  }

  void PGA::GeneratePrimaries(G4Event* event) {
    
    m_gun->GeneratePrimaryVertex(event);
    return;
  }

}