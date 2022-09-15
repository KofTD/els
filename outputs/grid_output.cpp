#include "colors.hpp"
#include "files_work.hpp"
#include "icons.hpp"
#include <iostream>
#include <map>
#include <numeric>
#include <string>
using std::cout;
using std::endl;

size_t get_largest_divisor(size_t size)
{
    auto divisor = std::gcd(size, 8);
    if (divisor != 1)
        return divisor;

    if (size > 8)
        return 2;
    else
        return size;
}

size_t get_width(const std::vector<std::filesystem::path>& files)
{
    size_t max_length = 0;

    for (auto &file : files)
    {
        if (auto filename_length = file.filename().string().length();
            filename_length > max_length)
            max_length = filename_length;
    }

    return max_length;
}

void grid(const std::vector<std::filesystem::path>& files)
{
    if (files.empty())
    {
        cout << color_string("EMPTY", Colors::red) << endl;
        cout << endl;
        return;
    }

    cout.setf(std::ios_base::left);

    auto width = get_width(files) + 16;
    size_t files_per_line;

    if (width >= 60)
        files_per_line = 1;
    else if (width >= 30)
        files_per_line = 2;
    else
        files_per_line = get_largest_divisor(files.size());

    short files_counter = 0;

    for (auto &file : files)
    {
        auto icon = get_icon(file);
        auto color = get_color(file);

        cout.width(width);

        if (files.size() / files_per_line != 1)
            cout << color_string(icon + " " + file.filename().string(), color);
        else
            cout << color_string(icon + " " + file.filename().string(), color) << "  ";

        files_counter++;

        if (files_counter == files_per_line)
        {
            cout << endl;
            files_counter = 0;
        }
    }

    cout << endl;

    if (files_counter != 0)
        cout << endl;
}

void grid_output(std::map<std::string, std::string> &arguments)
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

                grid(get_all_files(dir));
            }
        }
        else if (arguments.count("dirs"))
        {
            for (auto &dir : dirs)
            {
                cout << dir.string() << ":" << endl;

                grid(get_non_hidden_dirs(dir));
            }
        }
        else if (arguments.count("links"))
        {
            for (auto &dir : dirs)
            {
                cout << dir.string() << ":" << endl;

                grid(get_non_hidden_links(dir));
            }
        }
        else
        {
            for (auto &dir : dirs)
            {
                cout << dir.string() << ":" << endl;

                grid(get_non_hidden_files(dir));
            }
        }
    }
    else
    {
        if (arguments.count("all"))
            grid(get_all_files(arguments["path"]));
        else if (arguments.count("dirs"))
            grid(get_non_hidden_dirs(arguments["path"]));
        else if (arguments.count("links"))
            grid(get_non_hidden_links(arguments["path"]));
        else
            grid(get_non_hidden_files(arguments["path"]));
    }

    }