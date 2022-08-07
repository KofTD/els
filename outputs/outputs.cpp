#include "outputs.hpp"
#include <filesystem>
#include <map>
#include <string>
#include <vector>
namespace fs = std::filesystem;
using std::string, std::map;

std::vector<fs::path> get_files(fs::path path_to_files)
{
    if (path_to_files.empty())
        path_to_files = fs::current_path();

    if (!fs::exists(path_to_files))
        throw std::invalid_argument("Path doesn't exist");

    std::vector<fs::path> files;

    for (auto &i : fs::directory_iterator(path_to_files))
        files.push_back(i);

    return files;
}

string grid_output(map<string, string> &arguments)
{
    auto files = get_files(arguments["path"]);

    string output;

    short j = 0;
    for (auto &i : files)
    {
        output.append(i.filename().string());
        output.append("  ");
        j++;
        if (j == 4)
            output.push_back('\n');
    }

    return output;
}