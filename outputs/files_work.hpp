#pragma once
#include <filesystem>
#include <string>
#include <vector>

/**
 * @brief Get all files from given directory
 *
 * @param path Path to directory
 * @return Vector of paths to files from a given directory
 */
std::vector<std::filesystem::path> get_all_files(std::filesystem::path path);

/**
 * @brief Get regular files and dirs from given directory
 *
 * @param path Path to directory
 * @return Vector of paths to regular files and dirs from given directory
 */
std::vector<std::filesystem::path> get_non_hidden_files(std::filesystem::path path);

/**
 * @brief Recursevly get directories from given one
 *
 * @param path Path to directory
 * @return Vector of all directories (includes inner dirs) from given one
 */
std::vector<std::filesystem::path> get_dirs_recursive(std::filesystem::path path);

/**
 * @brief Get directories from given one
 *
 * @param path Path to directory
 * @return Vector of directories from given one
 */
std::vector<std::filesystem::path> get_dirs(std::filesystem::path path);

/**
 * @brief Get links and shortcuts from given directory
 *
 * @param path Path to directory
 * @return Vector of links and shortcuts from given directory
 */
std::vector<std::filesystem::path> get_links(std::filesystem::path path);

std::string check_path(std::string path);