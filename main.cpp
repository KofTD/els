#include "parse_arguments/parse_arguments.hpp"
#include <filesystem>
#include <iostream>
#include <vector>
namespace fs = std::filesystem;

int main(int argc, char const *argv[])
{
    auto a = parse_arguments(argc, argv);
    std::cout << a["level"] << std::endl;
    fs::path path_to_watch;
    if (argc == 1)
    {
        path_to_watch = fs::current_path();
    }
    else
    {
        path_to_watch = argv[1];
    }

    std::vector<fs::path> files_in_dir;
    for (auto &i : fs::directory_iterator(path_to_watch))
        files_in_dir.push_back(i);

    short j = 0;
    for (auto &i : files_in_dir)
    {
        std::cout << i.filename().string() << "  ";
        j++;
        if (j == 4)
        {
            std::cout << std::endl;
            j = 0;
        }
    }

    return 0;
}
