#ifndef HIT_HPP
#define HIT_HPP
#include "particle.hpp"
#include<vector>
using namespace std;

namespace mc1d {
    struct Hit {
        public:
            Hit (int particle_location, Particle particle);
            //make m_hit_locations getter
            vector<int> get_locations() const;
        private:
            vector<int> m_hit_locations;

    };
}

#endif