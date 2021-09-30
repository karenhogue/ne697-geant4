#ifndef HIT_HPP
#define HIT_HPP
#include <vector>
using namespace std;

namespace mc1d
{
    struct Hit {
    public:
        Hit(int n_particles);
        vector<int> hitLocations;
        void add_hit_location(int const& location);            
    };
}

#endif