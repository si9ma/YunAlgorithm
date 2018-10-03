//
// Created by si9ma on 9/30/18.
//

#ifndef ALGORITHM_TEST_H
#define ALGORITHM_TEST_H

typedef void (*sort_func)(int *arr,int len);

/* test */
bool test_sort(sort_func func); // Sort test
bool test_heap();
bool test_max_gap();
bool test_stack();
bool test_queue();
bool test_new_stack();
bool test_two_stack_queue();
bool test_two_queue_stack();
bool test_matrix();
bool test_singly_linked_list();
bool test_doubly_linked_list();
bool test_binary_search();
bool test_scratches();
bool test_binary_tree();
/* test */

#endif //ALGORITHM_TEST_H
