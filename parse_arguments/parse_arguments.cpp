#include "parse_arguments.hpp"
#include <cctype>
#include <vector>
using std::string;
using namespace std::string_literals;
using std::map;

[[maybe_unused]] string string_to_lowercase(string str)
{
    for (auto &i : str)
        i = char(tolower(int(i)));
    return str;
}

// @brief Parse string like -aDR
std::vector<char> parse_dash_string(const const string&& str)
{
    std::vector<char> arguments;

    for (char & i : str)
        arguments.push_back(i);

    return arguments;
}

inline void set_full_names_of_arguments(map<string, string> &arguments)
{
    map<string, string> full_names;
    full_names["H"] = "help";
    full_names["L"] = "long";
    full_names["G"] = "grid";
    full_names["O"] = "oneline";
    full_names["T"] = "tree";
    full_names["R"] = "recurse";
    full_names["D"] = "dirs";
    full_names["a"] = "all";
    full_names["s"] = "size";
    full_names["l"] = "links";
    full_names["C"] = "created";
    full_names["m"] = "modified";

    std::vector<string> short_names;
    for (const auto& i : arguments)
    {
        if (auto full_name = full_names.find(i.first); full_name != full_names.end())
        {
            auto status = i.second;
            arguments[full_name->second] = status;
            short_names.push_back(i.first);
        }
    }

    for (auto &i : short_names)
        arguments.erase(i);
}

map<string, string> parse_arguments(int argc, const char *argv[])
{
    map<string, string> arguments;

    for (int i = 1; i < argc; i++)
    {
        if (string argument = argv[i]; argument.substr(0, 2) == "--")
        {
            auto lowercase_argument = argument.substr(2);
            string status = "ON";
            size_t index = lowercase_argument.find('=');
            status = lowercase_argument.substr(index + 1);
            lowercase_argument = lowercase_argument.erase(index);

            arguments.insert(std::make_pair(lowercase_argument, status));
        }
        else if (argument[0] == '-')
        {
            if (argument.length() > 2)
            {
                auto dash_arguments = parse_dash_string(argument.substr(1));
                for (char dash_argument : dash_arguments)
                {
                    string arg;
                    arg.push_back(dash_argument);
                    arguments.insert(std::make_pair(arg, "ON"));
                }
            }
            else
            {
                string arg;
                arg.push_back(argument[1]);
                arguments.insert(std::make_pair(arg, "ON"));
            }
        }
        else
            arguments.insert(std::make_pair("path"s, argument));
    }

    set_full_names_of_arguments(arguments);

    return arguments;
}