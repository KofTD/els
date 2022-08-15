#include "parse_arguments/parse_arguments.hpp"
#include "outputs/grid_output.hpp"
#include <iostream>
using std::cout, std::endl;

int main(int argc, char const *argv[])
{
    auto arguments = parse_arguments(argc, argv);

    if (arguments.count("help"))
    {
        cout << "-H --help => produce help message"                     << endl;
        cout                                                            << endl;
        cout << "-------------------Outputs-------------------"         << endl;
        cout << "-L --long => display additional info about files"      << endl;
        cout << "-G --grid => display files as a grid (default output)" << endl;
        cout << "-O --oneline => display one file per line"             << endl;
        cout << "-T --tree => display files as tree"                    << endl;
        cout << "-R --recure => recurse into directories"               << endl;
        cout << "--level=[int] => limit the depth of recursion"         << endl;
        cout << "---------------------------------------------"         << endl;
        cout                                                            << endl;
        cout << "-------------------Filters-------------------"         << endl;
        cout << "-a --all => display hidden files and dot files"        << endl;
        cout << "-D --dirs => display only directories"                 << endl;
        cout << "-l --links => display only links"                      << endl;
        cout << "---------------------------------------------"         << endl;
        cout                                                            << endl;
        cout << "-----------------Long options----------------"         << endl;
        cout << "---------------------------------------------"         << endl;

        return 0;
    }

    try
    {
        if (arguments.count("grid"))
        {
            grid_output(arguments);
        }
        else if (arguments.count("oneline"))
        {
            // oneline output
        }
        else if (arguments.count("tree") && arguments.count("long"))
        {
            // tree-long output
        }
        else if (arguments.count("tree"))
        {
            // tree output
        }
        else if (arguments.count("long"))
        {
            // long output
        }
        else
        {
            grid_output(arguments);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}
