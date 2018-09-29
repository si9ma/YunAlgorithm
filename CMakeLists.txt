cmake_minimum_required(VERSION 3.12)
project(algorithm)

include_directories(include)
set(CMAKE_CXX_STANDARD 11)

add_executable(algorithm main.cpp sort.cpp include/sort.h util.cpp include/util.h min_sum.cpp include/min_sum.h)