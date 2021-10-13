#include "argparser.hpp"
#include "runmanager.hpp"
#include <iostream>
using namespace std;
using namespace mc1d;

int main(int argc, char* argv[]) {
    try {
        ArgParser arg_parser(argc, argv);

        RunManager run_manager(arg_parser.get_track_length(), arg_parser.get_start_pos(),
            arg_parser.get_absorption(), arg_parser.get_skip()
        );
        run_manager.run(arg_parser.get_nParticles());
    } catch (invalid_argument const& ex) {
        cout << "Usage: ./mc1d [track length] [absorption] [n particles]" << endl;
        cout << "Maximum [track length]:" << ArgParser::MAX_TRACK_LENGTH << endl;
        cout << "Error: " << ex.what() <<endl;
    }
    return 0;
}