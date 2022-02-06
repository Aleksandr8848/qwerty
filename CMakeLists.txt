cmake_minimum_required(VERSION 3.20)
project(course C)

set(CMAKE_C_STANDARD 11)

add_executable(course main.c libs/algorithms/algorithms.c libs/algorithms/algorithms.h libs/data_structures/bitset/bitset.c libs/data_structures/bitset/bitset.h libs/algorithms/array/array.c libs/algorithms/array/array.h)

add_subdirectory(libs)
target_link_libraries(course algorithms)
target_link_libraries(course data_structures)