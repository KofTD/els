#include "../../parse_arguments/parse_arguments.hpp"

int main(int argc, char const *argv[])
{
    auto a = parse_arguments(argc, argv);
    std::map<std::string, std::string> b;
    b["all"] = "ON";
    b["modified"] = "ON";
    b["size"] = "ON";
    b["level"] = "11";

    return (a == b ? 0 : 1);

    return 0;
}
