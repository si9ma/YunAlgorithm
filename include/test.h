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
/* test */

#endif //ALGORITHM_TEST_H
