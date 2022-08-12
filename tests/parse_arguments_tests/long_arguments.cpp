#include "../../parse_arguments/parse_arguments.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
    auto a = parse_arguments(argc, argv);

    std::map<std::string, std::string> b;
    b["oneline"] = "ON";
    b["level"] = "1";
    b["dirs"] = "ON";

    return (a == b ? 0 : 1);
}
