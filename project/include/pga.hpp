#ifndef PGA_HPP
#define PGA_HPP

#include "G4GeneralParticleSource.hh"
#include "G4VUserPrimaryGeneratorAction.hh"

namespace msrfeed {
  class PGA: public G4VUserPrimaryGeneratorAction {
    public:
      PGA();
      ~PGA();

      void GeneratePrimaries(G4Event* event) override final;

    private:

      G4GeneralParticleSource* m_gun;
  };
}

#endif