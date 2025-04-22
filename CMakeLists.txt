cmake_minimum_required(VERSION 3.10)
project(CXX_modules
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -g3")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fdiagnostics-color=always")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(module00)
add_subdirectory(module01)
add_subdirectory(module02)
add_subdirectory(module03)
add_subdirectory(module04)
