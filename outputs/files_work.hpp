#pragma once
#include <filesystem>
#include <string>
#include <vector>

std::vector<std::filesystem::path> get_all_files(std::filesystem::path path);

std::vector<std::filesystem::path> get_non_hidden_files(std::filesystem::path path);

void get_non_hidden_dirs_recursive(std::filesystem::path, std::vector<std::filesystem::path>*);

std::vector<std::filesystem::path> get_non_hidden_dirs(std::filesystem::path path);

std::vector<std::filesystem::path> get_non_hidden_links(std::filesystem::path path);

std::string check_path(std::string path);