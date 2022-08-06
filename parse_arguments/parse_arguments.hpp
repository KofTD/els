#pragma once
#include <map>
#include <string>

/**
 * @brief Parse cmd arguments
 *
 * @param argc arguments counter
 * @param argv array of arguments
 * @return map of arguments (full names) with status "ON" or anything else
 */
std::map<std::string, std::string> parse_arguments(int argc, char const *argv[]);