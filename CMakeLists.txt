cmake_minimum_required(VERSION 3.12)
project(algorithm)

include_directories(include)
set(CMAKE_CXX_STANDARD 11)

add_executable(algorithm main.cpp main.cpp min_sum.cpp heap.cpp nether_lands_flag.cpp sort.cpp util.cpp max_gap.cpp array_stack.cpp include/array_stack.h array_queue.cpp include/array_queue.h new_stack.cpp include/new_stack.h two_stack_queue.cpp include/two_stack_queue.h two_queue_stack.cpp include/two_queue_stack.h)