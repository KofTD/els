cmake_minimum_required(VERSION 3.8)

# ON => build additional exe files to tests
# OFF => only els files will be build
set(TESTING OFF)

project(els VERSION 0.1.0.0 LANGUAGES CXX)

add_executable(${PROJECT_NAME} main.cpp)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)

if(TESTING)
    add_subdirectory(tests)
endif()

add_subdirectory(parse_arguments)

target_link_libraries(${PROJECT_NAME} PRIVATE ParseArguments)

add_subdirectory(outputs)

target_link_libraries(${PROJECT_NAME} PRIVATE Outputs)