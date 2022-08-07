add_library(Output STATIC outputs.hpp outputs.cpp)

set_target_properties(Output PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)