#pragma once

#include <string>
#include <vector>
#include <filesystem>

enum class colors {
    red,
    green,
    blue,
    yellow,
    violet,
    cyan,
    white,
    black
};

std::vector<std::string> process_strings(const std::vector<std::filesystem::path>& files);
