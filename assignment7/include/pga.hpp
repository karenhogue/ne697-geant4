#ifndef PGA_HPP
#define PGA_HPP

#include "G4ParticleGun.hh"
#include "G4VUserPrimaryGeneratorAction.hh"

namespace ne697 {
  class GunMessenger;
  class PGA: public G4VUserPrimaryGeneratorAction {
    public:
      PGA();
      ~PGA();

      void GeneratePrimaries(G4Event* event) override final;

      void set_gun_offset(G4double const& gunOffset);
      G4double const& get_gun_offset() const;   

    private:

      GunMessenger* m_gun_messenger;
      G4ParticleGun* m_gun;
      G4double m_gunOffset;
  };
}

#endif