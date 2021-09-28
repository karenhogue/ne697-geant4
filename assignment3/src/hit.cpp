#include "hit.hpp"
#include "argparser.hpp"
#include "particle.hpp"
#include <iostream>
#include <vector>
using namespace std;

namespace mc1d {
    Hit::Hit(int particle_location, Particle particle):
        m_hit_locations()
    {
        m_hit_locations.push_back(particle.get_particle_location);
        return;
    }
}
