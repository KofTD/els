add_library(Outputs STATIC files_work.cpp files_work.hpp
                          grid_output.cpp grid_output.hpp
                          icons.cpp icons.hpp)


set_target_properties(Outputs PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)   