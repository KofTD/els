#include "files_work.hpp"
#include <Windows.h>
#include <algorithm>
#include <filesystem>
#include <vector>
using std::vector;
namespace fs = std::filesystem;

bool is_hiden(fs::path path)
{
    auto attributes = GetFileAttributesA(path.string().c_str());

    return (attributes & FILE_ATTRIBUTE_HIDDEN ? true : false);
}

vector<fs::path> get_all_files(fs::path path)
{
    if (!fs::is_directory(path))
        throw std::invalid_argument("Given path isn't directory");

    vector<fs::path> files;

    for (auto &file : fs::directory_iterator(path))
        files.push_back(file.path());

    std::sort(files.begin(), files.end());

    return files;
}

vector<fs::path> get_non_hidden_files(fs::path path)
{
    if (!fs::is_directory(path))
        throw std::invalid_argument("Given path isn't directory");

    vector<fs::path> files;

    for (auto &file : fs::directory_iterator(path))
    {
        if ((fs::is_regular_file(file) || fs::is_directory(file)) && !is_hiden(file))
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
    dirs.push_back(path);

    for (auto &file : fs::recursive_directory_iterator(path))
        if (fs::is_directory(file))
            dirs.push_back(file);

    return dirs;
}

vector<fs::path> get_dirs(fs::path path)
{
    if (!fs::is_directory(path))
        throw std::invalid_argument("Given path isn't directory");

    vector<fs::path> dirs;

    for (auto &file : fs::directory_iterator(path))
        if (fs::is_directory(file))
            dirs.push_back(file);

    std::sort(dirs.begin(), dirs.end());

    return dirs;
}

std::vector<std::filesystem::path> get_links(std::filesystem::path path)
{
    if (!fs::is_directory(path))
        throw std::invalid_argument("Given path isn't directory");

    vector<fs::path> links;
    for (auto &file : fs::directory_iterator(path))
        if (fs::is_symlink(file))
            links.push_back(file);

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