#include "runmanager.hpp"
#include "particle.hpp"
#include "hit.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

namespace mc1d {
    RunManager::RunManager(int track_length, float absorption):
        m_trackLength(track_length),
        m_absorption(absorption)
    {
        cout << "Creating RunManager with track_length = " << m_trackLength << 
        " and absorption = " << m_absorption << endl;
    }   
    void RunManager::run(int n_particles) {
        cout << "Running simulation with " << n_particles << "particles" << endl;

        for (int i = 0; i < n_particles; i++) {
            Particle particle(i); //create a particle object, with an ID = the counter

            while (particle.get_alive=true && particle.get_particle_location < m_trackLength) {//second loop while particle_location < track_length;
                particle.set_particle_location(particle.get_particle_location + 1); //transport the particle forward one step
                float random_num = static_cast <float> (rand ()) / (static_cast <float> (RAND_MAX));
                cout << "random_num = " << random_num << endl;
                if (random_num <= m_absorption) {
                    cout << "Particle is absorbed at " << particle.get_particle_location << endl;
                    particle.set_alive(false);
                    Hit hit(particle.get_particle_location);// send to Hit
                }
                else {
                    cout << "Particle lives and moves to " << particle.get_particle_location << endl;
                    //re-run with current location
                }
            }
        }          
        write_outputs("hits.csv", hit.get_locations);
        return;
    }

    void RunManager::write_outputs(string filename, vector<int> vals){
        //make a .csv output file
        ofstream myFile(filename); //create an output filestream object

        for(int i = 0; i < vals.size(); ++i) {
            myFile << vals.at(i) << ",";
        }

        myFile.close();
        return;
    }
}
