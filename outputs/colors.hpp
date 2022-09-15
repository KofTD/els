#pragma once
#include <filesystem>
//#include <string>
//#include <iostream>

enum class Colors
{
    black,
    red,
    green,
    yellow,
    blue,
    purple,
    cyan,
    white
};

class color_string
{
private:
    std::string text;
    short color;

public:
    color_string();
    explicit color_string(const char *t);
    color_string(const char *t, Colors c);
    color_string(std::string t, Colors c);
    ~color_string();

    friend std::ostream &operator<<(std::ostream &os, const color_string &str);
};

Colors get_color(const std::filesystem::path& file);