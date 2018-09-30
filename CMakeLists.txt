cmake_minimum_required(VERSION 3.12)
project(algorithm)

include_directories(include)
set(CMAKE_CXX_STANDARD 11)

add_executable(algorithm main.cpp main.cpp min_sum.cpp heap.cpp nether_lands_flag.cpp sort.cpp util.cpp max_gap.cpp)