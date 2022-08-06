#include "../../parse_arguments/parse_arguments.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
    auto a = parse_arguments(argc, argv);

    std::map<std::string, std::string> b;
    b["oneline"] = "ON";
    b["level"] = "1";
    b["dirs"] = "ON";

    for (auto &i : a)
        std::cout << i.first << '\t' << i.second << std::endl;

    std::cout << std::endl;

    for (auto &i : b)
        std::cout << i.first << '\t' << i.second << std::endl;

    return (a == b ? 0 : 1);
}
