#ifndef ARGPARSER_HPP
#define ARGPARSER_HPP

namespace mc1d {
    class ArgParser {
        public:
            ArgParser (int argc, char* argv[]);

            //getters for the command line arguments
            int get_track_length() const;
            int get_start_pos() const;
            float get_absorption() const;
            float get_skip() const;
            int get_nParticles() const;

            static int const MAX_TRACK_LENGTH = 100;

        private:
            int m_trackLength;
            int m_startPos;
            float m_absorption;
            float m_skip;
            int m_nParticles;
    };
}

#endif