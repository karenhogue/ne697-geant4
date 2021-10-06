#include "runmanager.hpp"
#include "particle.hpp"
#include "hit.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <random>
using namespace std;
//set up RNG
random_device rd;
mt19937 gen(rd());
uniform_real_distribution<float> rng(0,1.0);

namespace mc1d {
    RunManager::RunManager(int track_length, float absorption):
        m_trackLength(track_length),
        m_absorption(absorption)
    {
        cout << "Creating RunManager with track_length = " << m_trackLength << 
        " and absorption = " << m_absorption << endl;
    }   
    void RunManager::run(int n_particles) {
        cout << "Running simulation with " << n_particles << " particles" << endl;
        Hit hit(n_particles);

        for (int i = 0; i < n_particles; i++) {
            Particle particle(i); //create a particle object, with an ID = the counter
            //transport the particle +1 unit length until it is absorbed
            while (particle.get_alive()==true && particle.get_particle_location() < m_trackLength) {
                particle.set_particle_location(particle.get_particle_location() + 1); //transport the particle forward one step
                float random_num = rng(gen);
                //for testing: cout << "random_num = " << random_num << endl;
                if (random_num < m_absorption) {
                    //for testing: cout << "Particle is absorbed at " << particle.get_particle_location() << endl;
                    particle.set_alive(false);
                    hit.add_hit_location(particle.get_particle_location());// send particle location to Hit
                }
                else {
                    //for testing: cout << "Particle lives and moves to " << particle.get_particle_location() << endl;
                    //re-run with current location
                }
            }
        }
        cout << "The number of particles that was absorbed is: " << hit.hitLocations.size() << endl;
         
        write_outputs("hits.csv", hit.hitLocations);
        return;
    }

    void RunManager::write_outputs(string filename, vector<int> vals){
        //make a .csv output file
        ofstream myFile(filename); //create an output filestream object

        for(int i = 0; i < vals.size(); ++i) {
            myFile << vals.at(i) << ",\n";
        }

        myFile.close();
        return;
    }
}
