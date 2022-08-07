#include "parse_arguments/parse_arguments.hpp"
#include <filesystem>
#include <iostream>
#include <vector>
namespace fs = std::filesystem;
using std::cout, std::endl;

int main(int argc, char const *argv[])
{
    auto arguments = parse_arguments(argc, argv);

    if (arguments.count("help") == 1)
    {
        cout << "-H --help => produce help message" << endl;
        cout << endl;
        cout << "-------------------Outputs-------------------" << endl;
        cout << "-L --long => display additional info about files" << endl;
        cout << "-G --grid => display files as a grid (default output)" << endl;
        cout << "-O --oneline => display one file per line" << endl;
        cout << "-T --tree => display files as tree" << endl;
        cout << "---------------------------------------------" << endl;
        cout << endl;
        cout << "-------------------Filters-------------------" << endl;
        cout << "---------------------------------------------" << endl;
        cout << endl;
        cout << "-----------------Long options----------------" << endl;
        cout << "---------------------------------------------" << endl;
    }

    return 0;
}
