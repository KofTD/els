#include "../../parse_arguments/parse_arguments.hpp"

int main(int argc, char const *argv[])
{
    auto a = parse_arguments(argc, argv);
    std::map<std::string, std::string> b;
    b["oneline"] = "ON";
    b["all"] = "ON";
    b["dirs"] = "ON";
    b["created"] = "ON";

    return (a == b ? 0 : 1);
}
