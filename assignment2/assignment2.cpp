#include <iostream>
#include <tgmath.h>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
    double two_to_n = 0;
//    int n = 3;
    string str = argv[1];
    int n = stoi(str);
    two_to_n = pow(2.0, (1.0 * n));
    std::cout << two_to_n << std::endl;
}