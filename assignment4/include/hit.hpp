#ifndef HIT_HPP
#define HIT_HPP
#include <vector>
#include <string>
using namespace std;

namespace mc1d
{
    struct Hit {
    public:
        Hit(int n_particles);
        vector<int> hitLocations;
        vector<string> hitTypes;
        void add_hit_location(int const& location, string hit_type);            
    };
}

#endif