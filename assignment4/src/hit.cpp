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

void Hit::add_hit_location(int const& location, string hit_type) {
    hitLocations.push_back(location);
    hitTypes.push_back(hit_type);
    return;
}
}
