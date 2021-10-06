#include "particle.hpp"
#include <iostream>
using namespace std;

namespace mc1d {
    Particle::Particle(int particle_ID):
        
        m_particleID(particle_ID),
        m_particleLocation(0),
        m_alive(true)
        
    {
     return; 
    }

int Particle::get_particle_ID() const {
    return m_particleID;
}
int Particle::get_particle_location() const {
    return m_particleLocation;
}
bool Particle::get_alive() const {
    return m_alive;
}     
void Particle::set_particle_location (int const& particle_location) {
    m_particleLocation = particle_location; return;
}
void Particle::set_alive(bool const& alive) {
    m_alive = alive; return;
}
}
