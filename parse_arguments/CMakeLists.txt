add_library(ParseArguments STATIC parse_arguments.hpp parse_arguments.cpp)

set_property(TARGET ParseArguments PROPERTY CXX_STANDARD 17)
set_property(TARGET ParseArguments PROPERTY CXX_STANDARD_REQUIRED ON)