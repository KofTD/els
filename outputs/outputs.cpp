#include "outputs.hpp"
#include <filesystem>
#include <map>
#include <queue>
#include <string>
#include <vector>
namespace fs = std::filesystem;
using std::map;
using std::string;
using std::vector;

vector<fs::path> get_files(fs::path path)
{
    vector<fs::path> files;

    for (auto &i : fs::directory_iterator(path))
        files.push_back(i);

    return files;
}

vector<fs::path> get_all_dirs(fs::path path)
{
    vector<fs::path> dirs;

    for (auto &i : fs::recursive_directory_iterator(path))
        if (fs::is_directory(i))
            dirs.push_back(i);

    return dirs;
}

string grid_output(map<string, string> &arguments)
{
    if (arguments["path"].empty())
        arguments["path"] = fs::current_path().string();

    if (!fs::exists(arguments["path"]))
        throw std::invalid_argument("Path doesn't exist");

    string output;

    if (arguments.count("recurse"))
    {
        std::queue<vector<fs::path>> files;

        auto dirs = get_all_dirs(arguments["path"]);

        for (auto &dir : dirs)
            files.push(get_files(dir));

        while (!files.empty())
        {
            output.push_back('\n');

            auto current_catalog = files.front();

            if (current_catalog.empty())
            {
                files.pop();
                continue;
            }

            auto catalog_name = current_catalog.front().parent_path().string();

            output.append(catalog_name + ":\n");

            short j = 0;
            for (auto &i : current_catalog)
            {
                output.append(i.filename().string());
                output.append("  ");
                j++;
                if (j == 4)
                {
                    output.push_back('\n');
                    j = 0;
                }
            }

            output.push_back('\n');
            files.pop();
        }
    }
    else
    {
        auto files = get_files(arguments["path"]);
        short j = 0;
        for (auto &i : files)
        {
            output.append(i.filename().string());
            output.append("  ");
            j++;
            if (j == 4)
            {
                output.push_back('\n');
                j = 0;
            }
        }
    }

    return output;
}