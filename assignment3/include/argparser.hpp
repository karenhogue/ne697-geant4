#ifndef ARGPARSER_HPP
#define ARGPARSER_HPP

namespace mc1d {
    class ArgParser {
        public:
            ArgParser (int argc, char* argv[]);

            //getters for the command line arguments
            int get_track_length() const;
            float get_absorption() const;
            int get_nParticles() const;

            static int const MAX_TRACK_LENGTH = 100;

        private:
            int m_trackLength;
            float m_absorption;
            int m_nParticles;
    };
}

#endif