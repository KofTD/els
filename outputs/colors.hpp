#pragma once
#include <filesystem>

enum class Colors
{
    white,
    red,
    aqua,
    green,
    purple,
    grey,
    yellow,
    blue,
    light_red
};

Colors get_color(std::filesystem::path file);