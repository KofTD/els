#include "oneline.hpp"
#include "files_work.hpp"
#include <iostream>
#include "icons.hpp"
#include "colors.hpp"
using std::cout;
using std::endl;

void oneline(std::vector<std::filesystem::path> files)
{
    if (files.size() == 0)
    {
        cout << color_string("EMPTY", Colors::red) << endl;
        cout << endl;
        return;
    }

    cout.setf(std::ios_base::left);

    for (auto &file : files)
    {
        auto icon = get_icon(file);
        auto color = get_color(file);

        cout << color_string(icon + " " + file.filename().string(), color) << endl;
    }

    cout << endl;
}

void oneline_output(std::map<std::string, std::string> &arguments)
{
    arguments["path"] = check_path(arguments["path"]);

    if (arguments.count("all") && arguments.count("dirs") &&
        arguments.count("links"))
        throw std::invalid_argument("all, dirs and links flags can't be used at the same time");

    if (arguments.count("recurse"))
    {
        std::vector<std::filesystem::path> dirs;
        get_non_hidden_dirs_recursive(arguments["path"], &dirs);

        if (arguments.count("all"))
        {
            for (auto &dir : dirs)
            {
                cout << dir.string() << ":" << endl;

                oneline(get_all_files(dir));
            }
        }
        else if (arguments.count("dirs"))
        {
            for (auto &dir : dirs)
            {
                cout << dir.string() << ":" << endl;

                oneline(get_non_hidden_dirs(dir));
            }
        }
        else if (arguments.count("links"))
        {
            for (auto &dir : dirs)
            {
                cout << dir.string() << ":" << endl;

                oneline(get_non_hidden_links(dir));
            }
        }
        else
        {
            for (auto &dir : dirs)
            {
                cout << dir.string() << ":" << endl;

                oneline(get_non_hidden_files(dir));
            }
        }
    }
    else
    {
        if (arguments.count("all"))
            oneline(get_all_files(arguments["path"]));
        else if (arguments.count("dirs"))
            oneline(get_non_hidden_dirs(arguments["path"]));
        else if (arguments.count("links"))
            oneline(get_non_hidden_links(arguments["path"]));
        else
            oneline(get_non_hidden_files(arguments["path"]));
    }

    return;
}