cmake_minimum_required(VERSION 3.22)

project(mlp LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE BOOL "Enable compile database for clangd usage" FORCE)
set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_subdirectory(catp1)
add_subdirectory(catp2)