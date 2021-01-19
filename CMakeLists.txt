cmake_minimum_required (VERSION 3.10)
project(allocate)

file(GLOB allocate_headers ./src/allocate/*.hpp)

add_library(allocate INTERFACE)
add_library(steinwurf::allocate ALIAS allocate)

target_include_directories(allocate INTERFACE src/)

install(FILES ${allocate_headers} DESTINATION ${CMAKE_INSTALL_PREFIX}/include/allocate)
