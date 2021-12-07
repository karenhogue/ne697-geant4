#include "pga.hpp"
#include "G4Gamma.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"

namespace msrfeed {
  PGA::PGA():
    G4VUserPrimaryGeneratorAction(),
    m_gun(new G4ParticleGun(1))
  {
    G4cout << "Creating PGA" << G4endl;
    m_gun->SetParticleDefinition(G4Gamma::Definition());
    m_gun->SetParticleEnergy(185.7*keV);
    m_gun->SetParticleMomentumDirection(G4ThreeVector(0., 1., 0.));
  }

  PGA::~PGA() {
    G4cout << "Deleting PGA" << G4endl;
    delete m_gun;
  }

  void PGA::GeneratePrimaries(G4Event* event) {
    G4double x0  = 0.*cm, z0  = 0.*cm;
    G4double dx0 = 50.*cm, dz0 = 50.*cm; 
    x0 += dx0*(G4UniformRand()-0.5);
    z0 += dz0*(G4UniformRand()-0.5);
    m_gun->SetParticlePosition(G4ThreeVector(x0,0.,z0));
    m_gun->GeneratePrimaryVertex(event);
    return;
  }

}