#include "../../parse_arguments/parse_arguments.hpp"

int main(int argc, const char *argv[])
{
    auto a = parse_arguments(argc, argv);
    std::map<std::string, std::string> b;

    return (a == b ? 0 : 1);
}