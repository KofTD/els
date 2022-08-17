#include "grid_output.hpp"
#include "files_work.hpp"
#include <iostream>
#include <map>
#include <string>
using std::cout;
using std::endl;

void output(std::vector<std::filesystem::path> files)
{
    short files_counter = 0;
    for (auto &file : files)
    {
        cout << file.filename().string() << ' ';
        files_counter++;
        if (files_counter == 4)
        {
            cout << endl;
            files_counter = 0;
        }
    }
}

void grid_output(std::map<std::string, std::string> &arguments)
{
    arguments["path"] = check_path(arguments["path"]);

    if (arguments.count("all") && arguments.count("dirs") &&
        arguments.count("links"))
        throw std::invalid_argument("all, dirs and links flags can't be used at the same time");

    if (arguments.count("recurse"))
    {
        auto dirs = get_dirs_recursive(arguments["path"]);
        if (arguments.count("all"))
        {
            for (auto &dir : dirs)
            {
                cout << dir.string() << ":" << endl;

                output(get_all_files(dir));
            }
        }
        else if (arguments.count("dirs"))
        {
            for (auto &dir : dirs)
            {
                cout << dir.string() << ":" << endl;

                output(get_dirs(dir));
            }
        }
        else if (arguments.count("links"))
        {
            for (auto &dir : dirs)
            {
                cout << dir.string() << ":" << endl;

                output(get_links(dir));
            }
        }
        else
        {
            for (auto &dir : dirs)
            {
                cout << dir.string() << ":" << endl;

                output(get_regular_files(dir));
            }
        }
    }
    else
    {
        if (arguments.count("all"))
            output(get_all_files(arguments["path"]));
        else if (arguments.count("dirs"))
            output(get_dirs(arguments["path"]));
        else if (arguments.count("links"))
            output(get_links(arguments["path"]));
        else
            output(get_regular_files(arguments["path"]));
    }

    return;
}