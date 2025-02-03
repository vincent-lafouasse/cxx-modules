cmake_minimum_required(VERSION 3.15)
project(Cpp_modules
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -g3")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(module00)
add_subdirectory(module02)
add_subdirectory(module03)
