cmake_minimum_required(VERSION 3.8)

set(TESTING "ON")

project(els VERSION 0.1.0.0 LANGUAGES CXX)

add_executable(${PROJECT_NAME} main.cpp)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)

if(TESTING STREQUAL "ON")
    add_subdirectory(tests)
endif()

add_subdirectory(parse_arguments)

target_link_libraries(${PROJECT_NAME} PRIVATE ParseArguments)