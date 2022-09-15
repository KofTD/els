#pragma once
#include <filesystem>
#include <string>
#include <vector>

std::vector<std::filesystem::path> get_all_files(const std::filesystem::path& path);

std::vector<std::filesystem::path> get_non_hidden_files(const std::filesystem::path& path);

void get_non_hidden_dirs_recursive(const std::filesystem::path&, std::vector<std::filesystem::path>*);

std::vector<std::filesystem::path> get_non_hidden_dirs(const std::filesystem::path& path);

std::vector<std::filesystem::path> get_non_hidden_links(const std::filesystem::path& path);

std::string check_path(std::string path);