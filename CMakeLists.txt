cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_CXX_COMPILER                  "C:/Program Files/LLVM/bin/clang++.exe")
set(CMAKE_CXX_FLAGS_INIT                "-Wall -std=c++17")
set(CMAKE_CXX_FLAGS_DEBUG_INIT          "-g")
set(CMAKE_CXX_FLAGS_MINSIZEREL_INIT     "-Os -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE_INIT        "-O3 -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO_INIT "-O2 -g")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(els VERSION 0.0.0.1 LANGUAGES CXX)

add_executable(${PROJECT_NAME} main.cpp files.cpp make_strings.cpp grid.cpp parse_arguments.cpp)
