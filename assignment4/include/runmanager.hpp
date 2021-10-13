#ifndef RUNMANAGER_HPP
#define RUNMANAGER_HPP
#include <vector>
#include <iostream>
using namespace std;

namespace mc1d{
    class RunManager {
        public:
            RunManager(int track_length, int start_pos, float absorption, float skip);

            void run(int n_particles);
            void write_outputs(string filename, vector<int> vals, vector<string> vals2);

        private:
            int m_trackLength;
            int m_startPos;
            float m_absorption;
            float m_skip;
            int m_step;
            string m_hit_type;
    };
}

#endif