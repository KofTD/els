#pragma once

#include <map>
#include <string>

std::map<std::string, std::string> parse_arguments(int argc,
                                                   char *argv[]);
