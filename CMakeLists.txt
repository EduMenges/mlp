cmake_minimum_required(VERSION 3.22)

project(mlp LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE BOOL "Enable compile database for clangd usage")

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_subdirectory(exercicio1)