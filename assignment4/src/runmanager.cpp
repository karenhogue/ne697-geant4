#include "runmanager.hpp"
#include "particle.hpp"
#include "hit.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
using namespace std;
//set up RNG
random_device rd;
mt19937 gen(rd());
uniform_real_distribution<float> rng(0,1.0);

namespace mc1d {
    RunManager::RunManager(int track_length, int start_pos, float absorption, float skip):
        m_trackLength(track_length),
        m_startPos(start_pos),
        m_absorption(absorption),
        m_skip(skip),
        m_hit_type("no collision"),
        m_step(0)
    {
        cout << "Creating RunManager with track_length = " << m_trackLength << 
        ", starting position = " << m_startPos << ", absorption = " << m_absorption <<
        ", and skip = " << m_skip << endl;
    }   
    void RunManager::run(int n_particles) {
        cout << "Running simulation with " << n_particles << " particles" << endl;
        Hit hit(n_particles);

        for (int i = 0; i < n_particles; i++) {
            Particle particle(i, m_startPos); //create a particle object, with an ID = the counter
            //determine if the particle travels in the + or - direction
            float random_num = rng(gen);
            //cout << "random_num direction = " << random_num << endl;
            if (random_num < 0.5) { 
                m_step = 1;
                }
            if (random_num >= 0.5) {
                m_step = -1;
                }
            //transport the particle step by step until absorbed or exits material
            while (particle.get_alive()==true && 
                    particle.get_particle_location() < m_trackLength &&
                    particle.get_particle_location() > 0) {
                float random_num = rng(gen);
                //cout << "random_num = " << random_num << endl;
                if (random_num < m_absorption) {
                    particle.set_particle_location(particle.get_particle_location() + m_step);
                    //cout << "Particle is absorbed at " << particle.get_particle_location() << endl;
                    particle.set_alive(false);
                    m_hit_type = "a";
                    hit.add_hit_location(particle.get_particle_location(), m_hit_type);
                }
                else if (random_num < (m_absorption + m_skip)) {
                    particle.set_particle_location(particle.get_particle_location() + m_step);
                    //cout << "Particle skips at " << particle.get_particle_location() << endl;
                    m_hit_type = "s";
                    hit.add_hit_location(particle.get_particle_location(), m_hit_type);
                }
                if (particle.get_particle_location() > 0 || particle.get_particle_location() < m_trackLength){
                    particle.set_particle_location(particle.get_particle_location() + m_step);
                }
                
                //if the particle is at the end of the track_length, record the value in hit
                if (particle.get_particle_location() <= 0 || particle.get_particle_location() >= m_trackLength) {
                    m_hit_type = "e";
                    hit.add_hit_location(particle.get_particle_location(), m_hit_type);
                    
                }
            }
        }
        cout << "The number of interactions is: " << hit.hitLocations.size() << endl;
         
        write_outputs("hits.csv", hit.hitLocations, hit.hitTypes);
        return;
    }

    void RunManager::write_outputs(string filename, vector<int> vals, vector<string> vals2){
        //make a .csv output file
        ofstream myFile(filename); //create an output filestream object

        for(int i = 0; i < int(vals.size()); ++i) {
            myFile << vals.at(i) << " " << vals2.at(i) << ",\n";
        }

        myFile.close();
        return;
    }
}
