#ifndef RUNMANAGER_HPP
#define RUNMANAGER_HPP
#include <vector>
using namespace std;

namespace mc1d{
    class RunManager {
        public:
            RunManager(int track_length, float absorption);

            void run(int n_particles);
            void write_outputs(string filename, vector<int> vals);

        private:
            int m_trackLength;
            int m_absorption;
 
    };
}

#endif