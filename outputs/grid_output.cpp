#include "grid_output.hpp"
#include "colorconsole.hpp"
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

size_t get_width(std::vector<std::filesystem::path> files)
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

auto colorize(std::string str, Colors color)
{
    switch (color)
    {
    case Colors::red:
        return dye::red(str);
    case Colors::aqua:
        return dye::aqua(str);
    case Colors::blue:
        return dye::blue(str);
    case Colors::green:
        return dye::green(str);
    case Colors::grey:
        return dye::grey(str);
    case Colors::light_red:
        return dye::light_red(str);
    case Colors::purple:
        return dye::purple(str);
    case Colors::white:
        return dye::white(str);
    case Colors::yellow:
        return dye::yellow(str);
    }

    return dye::white(str);
}

void output(std::vector<std::filesystem::path> files)
{
    if (files.size() == 0)
    {
        cout << dye::red("EMPTY") << endl;
        cout << endl;
        return;
    }

    cout.setf(std::ios_base::left);

    auto width = get_width(files) + 5;
    size_t files_per_line = 0;

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
        {
            cout << colorize(icon + " " + file.filename().string(), color);
        }
        else
            cout << colorize(icon + " " + file.filename().string(), color) << "  ";

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

                output(get_rfiles_and_dirs(dir));
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
            output(get_rfiles_and_dirs(arguments["path"]));
    }

    return;
}