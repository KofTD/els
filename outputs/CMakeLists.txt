add_library(Outputs STATIC files_work.cpp files_work.hpp
                          grid_output.cpp grid_output.hpp
                          icons.cpp icons.hpp
                          colors.cpp colors.hpp)


set_target_properties(Outputs PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)   

find_path(COLORCONSOLE_INCLUDE_DIRS "colorconsole.hpp")
target_include_directories(Outputs PRIVATE ${COLORCONSOLE_INCLUDE_DIRS})