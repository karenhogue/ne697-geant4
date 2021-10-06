#include "hit.hpp"
#include "argparser.hpp"
#include <iostream>
#include <vector>
using namespace std;

namespace mc1d {
    Hit::Hit(int n_particles):

        hitLocations()
    {
        return;
    }

void Hit::add_hit_location(int const& location) {
    hitLocations.push_back(location); 
    //hitLocations[particle_index] = location;
    return;
}
}
