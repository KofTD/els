#include "files_work.hpp"
#include <filesystem>
#include <vector>
#include <algorithm>
using std::vector;
namespace fs = std::filesystem;

vector<fs::path> get_all_files(fs::path path)
{
    if (!fs::is_directory(path))
        throw std::invalid_argument("Given path isn't directory");

    vector<fs::path> files;

    for (auto &file : fs::directory_iterator(path))
        files.push_back(fs::path(file));

    std::sort(files.begin(), files.end());

    return files;
}

vector<fs::path> get_regular_files(fs::path path)
{
    if (!fs::is_directory(path))
        throw std::invalid_argument("Given path isn't directory");

    vector<fs::path> files;

    for (auto &file : fs::directory_iterator(path))
    {
        if (auto path_to_file = fs::path(file); path_to_file.has_extension() ||
           (fs::is_directory(path_to_file) && path_to_file.filename().string()[0] != '.'))
            files.push_back(file);
    }

    std::sort(files.begin(), files.end());

    return files;
}

vector<fs::path> get_dirs_recursive(fs::path path)
{
    if (!fs::is_directory(path))
        throw std::invalid_argument("Given path isn't directory");

    vector<fs::path> dirs;

    for (auto &file : fs::recursive_directory_iterator(path))
        if (auto path_to_file = fs::path(file); fs::is_directory(path_to_file))
            dirs.push_back(path_to_file);

    return dirs;
}

vector<fs::path> get_dirs(fs::path path)
{
    if (!fs::is_directory(path))
        throw std::invalid_argument("Given path isn't directory");

    vector<fs::path> dirs;

    for (auto &file : fs::directory_iterator(path))
        if (auto path_to_file = fs::path(file); fs::is_directory(path_to_file))
            dirs.push_back(path_to_file);

    std::sort(dirs.begin(), dirs.end());

    return dirs;
}

std::vector<std::filesystem::path> get_links(std::filesystem::path path)
{
    if (!fs::is_directory(path))
        throw std::invalid_argument("Given path isn't directory");

    vector<fs::path> links;
    for (auto &file : fs::directory_iterator(path))
        if (auto path_to_file = fs::path(file); fs::is_symlink(path_to_file))
            links.push_back(path_to_file);

    std::sort(links.begin(), links.end());

    return links;
}

std::string check_path(std::string path)
{
    if (path.empty())
        path = fs::current_path().string();

    if (!fs::exists(path))
        throw std::invalid_argument("Path doesn't exist");

    return path;
}