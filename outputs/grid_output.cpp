#include "grid_output.hpp"
#include "files_work.hpp"
#include <iostream>
#include <map>
#include <string>
using std::cout;
using std::endl;

void grid_output(std::map<std::string, std::string> &arguments)
{
    arguments["path"] = check_path(arguments["path"]);

    if (arguments.count("all") && arguments.count("dirs") &&
        arguments.count("links"))
        throw std::invalid_argument("all, dirs and links flags can't be used at the same time");

    if (arguments.count("recurse"))
    {
        if (arguments.count("all"))
        {
            auto dirs = get_dirs_recursive(arguments["path"]);

            for (auto &dir : dirs)
            {
                auto dir_name = dir.parent_path().string();

                cout << dir_name << ":" << endl;

                auto all_files_in_dir = get_all_files(dir);

                short files_counter = 0;
                for (auto &file : all_files_in_dir)
                {
                    cout << file.filename().string() << "  ";
                    files_counter++;
                    if (files_counter == 4)
                    {
                        cout << endl;
                        files_counter = 0;
                    }
                }
            }
        }
        else if (arguments.count("dirs"))
        {
            auto dirs = get_dirs_recursive(arguments["path"]);

            for (auto &dir : dirs)
            {
                auto dir_name = dir.parent_path().string();

                cout << dir_name << ":" << endl;

                auto inner_dirs = get_dirs(dir);

                short files_counter = 0;
                for (auto &file : inner_dirs)
                {
                    cout << file.filename().string() << "  ";
                    files_counter++;
                    if (files_counter == 4)
                    {
                        cout << endl;
                        files_counter = 0;
                    }
                }
            }
        }
        else if (arguments.count("links"))
        {
            auto dirs = get_dirs_recursive(arguments["path"]);

            for (auto &dir : dirs)
            {
                auto dir_name = dir.parent_path().string();

                cout << dir_name << ":" << endl;

                auto links_in_dir = get_links(dir);

                short files_counter = 0;
                for (auto &file : links_in_dir)
                {
                    cout << file.filename().string() << "  ";
                    files_counter++;
                    if (files_counter == 4)
                    {
                        cout << endl;
                        files_counter = 0;
                    }
                }
            }
        }
        else
        {
            auto dirs = get_dirs_recursive(arguments["path"]);

            for (auto &dir : dirs)
            {
                auto dir_name = dir.parent_path().string();

                cout << dir_name << ":" << endl;

                auto regular_files_in_dir = get_regular_files(dir);

                short files_counter = 0;
                for (auto &file : regular_files_in_dir)
                {
                    cout << file.filename().string() << "  ";
                    files_counter++;
                    if (files_counter == 4)
                    {
                        cout << endl;
                        files_counter = 0;
                    }
                }
            }
        }
    }
    else
    {
        if (arguments.count("all"))
        {
            auto all_files = get_all_files(arguments["path"]);

            short files_counter = 0;
            for (auto &file : all_files)
            {
                cout << file.filename().string() << "  ";
                files_counter++;
                if (files_counter == 4)
                {
                    cout << endl;
                    files_counter = 0;
                }
            }
        }
        else if (arguments.count("dirs"))
        {
            auto dirs = get_dirs(arguments["path"]);

            short files_counter = 0;
            for (auto &dir : dirs)
            {
                cout << dir.filename().string() << "  ";
                files_counter++;
                if (files_counter == 4)
                {
                    cout << endl;
                    files_counter = 0;
                }
            }
        }
        else if (arguments.count("links"))
        {
            auto links = get_links(arguments["path"]);
            short files_counter = 0;
            for (auto &link : links)
            {
                cout << link.filename().string() << "  ";
                files_counter++;
                if (files_counter == 4)
                {
                    cout << endl;
                    files_counter = 0;
                }
            }
        }
        else
        {
            auto regular_files = get_regular_files(arguments["path"]);

            short files_counter = 0;
            for (auto &file : regular_files)
            {
                cout << file.filename().string() << "  ";
                files_counter++;
                if (files_counter == 4)
                {
                    cout << endl;
                    files_counter = 0;
                }
            }
        }
    }

    return;
}