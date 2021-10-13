#include "argparser.hpp"
#include <stdexcept>

namespace mc1d {
    ArgParser::ArgParser(int argc, char* argv[]):
        //initialize variables to be read in on command line
        m_trackLength(0),
        m_startPos(0),
        m_absorption(0.0),
        m_skip(0.0),
        m_nParticles(0)
    {
        if (argc !=6) {
            throw std::invalid_argument("Incorrect number of arguments.");
        }
        m_trackLength = std::atoi(argv[1]);
        if ((m_trackLength < 1) || (m_trackLength > MAX_TRACK_LENGTH)) {
            throw std::invalid_argument("Track length invalid.");
        }
        m_startPos = std::atoi(argv[2]);
        if ((m_startPos < 0) || (m_startPos > m_trackLength)) {
            throw std::invalid_argument("Starting position must be between 0 and the track length.");
        }
        m_absorption = std::atof(argv[3]);
        if ((m_absorption <= 0.0) || (m_absorption > 1.0)) {
            throw std::invalid_argument("Absorption value invalid.");
        }
        m_skip = std::atof(argv[4]);
        if ((m_skip <= 0.0) || (m_skip > (1-m_absorption))) {
            throw std::invalid_argument("Skip value invalid - must be between 0 and the total probability of absorption and skipping cannot be greater than 1.0.");
        }
        m_nParticles = atoi(argv[5]);
        if (m_nParticles < 1) {
            throw std::invalid_argument("Not enough particles.");
        }
    }

int ArgParser::get_track_length() const {
    return m_trackLength;
}
int ArgParser::get_start_pos() const {
    return m_startPos;
}
float ArgParser::get_absorption() const {
    return m_absorption;
}
float ArgParser::get_skip() const {
    return m_skip;
}
int ArgParser::get_nParticles() const {
    return m_nParticles;
}
}