cmake_minimum_required(VERSION 3.12)
project(algorithm)

include_directories(include)
set(CMAKE_CXX_STANDARD 11)

add_executable(algorithm main.cpp main.cpp min_sum.cpp heap.cpp nether_lands_flag.cpp sort.cpp util.cpp max_gap.cpp array_stack.cpp include/array_stack.h array_queue.cpp include/array_queue.h new_stack.cpp include/new_stack.h two_stack_queue.cpp include/two_stack_queue.h two_queue_stack.cpp include/two_queue_stack.h matrix.cpp include/matrix.h test.cpp include/test.h singly_linked_list.cpp include/singly_linked_list.h singly_node.cpp include/singly_node.h doubly_node.cpp include/doubly_node.h doubly_linked_list.cpp include/doubly_linked_list.h binary_search.cpp include/binary_search.h scratches.cpp include/scratches.h tree_node.cpp include/tree_node.h binary_tree.cpp binary_tree.h random_pool.cpp include/random_pool.h union_find_set.cpp union_find_set.h trie.cpp include/trie.h lowest_lexicography.cpp lowest_lexicography.h dp.cpp include/dp.h)