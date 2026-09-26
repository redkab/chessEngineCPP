cmake_minimum_required(VERSION 3.16)

project(ChessEngineCPP LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(chess
    src/main.cpp
    src/board.cpp
)

target_include_directories(chess PRIVATE include)

target_compile_options(chess PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)
