#include "argparser.hpp"
#include <stdexcept>

namespace mc1d {
    ArgParser::ArgParser(int argc, char* argv[]):
        //initialize variables to be read in on command line
        m_trackLength(0),
        m_absorption(0.0),
        m_nParticles(0)
    {
        if (argc !=4) {
            throw std::invalid_argument("Incorrect number of arguments.");
        }
        m_trackLength = std::atoi(argv[1]);
        if ((m_trackLength < 1) || (m_trackLength > MAX_TRACK_LENGTH)) {
            throw std::invalid_argument("Track length invalid.");
        }
        m_absorption = std::atof(argv[2]);
        if ((m_absorption <= 0.0) || (m_absorption > 1.0)) {
            throw std::invalid_argument("Absorption value invalid.");
        }
        m_nParticles = atoi(argv[3]);
        if (m_nParticles < 1) {
            throw std::invalid_argument("Not enough particles.");
        }
    }

int ArgParser::get_track_length() const {
    return m_trackLength;
}
float ArgParser::get_absorption() const {
    return m_absorption;
}
int ArgParser::get_nParticles() const {
    return m_nParticles;
}
}