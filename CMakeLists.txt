cmake_minimum_required (VERSION 3.10)
project(allocate)

add_library(allocate INTERFACE)
add_library(steinwurf::allocate ALIAS allocate)

target_include_directories(allocate INTERFACE src/)
