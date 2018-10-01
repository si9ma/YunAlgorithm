#include "test.h"
#include <cstring>
#include <iostream>
#include "sort.h"
#include <algorithm>
#include "min_sum.h"
#include "util.h"
#include "nether_lands_flag.h"
#include "max_gap.h"
#include "heap.h"
#include "array_stack.h"
#include "array_queue.h"
#include <string>
#include "new_stack.h"
#include "two_stack_queue.h"
#include "two_queue_stack.h"
#include "matrix.h"
#include "singly_linked_list.h"
#include "doubly_linked_list.h"

using namespace si9ma;
using namespace std;

extern int arr_len;
extern int *arr, *arr_copy;

bool test_heap(){
    int heap_size = 0;

    // build Heap
    for (int i = 0; i < arr_len; ++i) {
        Heap::heap_insert(arr,i);
    }

    Util::print_array(arr,arr_len," ");
    Util::print_array(arr_copy,arr_len," ");
    cout << endl;

    return true;
}

bool test_max_gap(){
    Util::print_array(arr,arr_len," ");
    std::sort(arr_copy,arr_copy + arr_len);
    Util::print_array(arr_copy,arr_len," ");
    cout << MaxGap::max_gap(arr,arr_len) << "\n" << endl;
    return true;
}

bool test_stack(){
    ArrayStack stack(100);
    try {
        stack.push(100);
        stack.push(50);
        stack.push(30);

        cout << stack.peek() << endl;
        cout << stack.peek() << endl;
        cout << stack.pop() << endl;
        cout << stack.pop() << endl;
        cout << stack.pop() << endl;
        return true;
    }catch (char const* str){
        cout << str << endl;
        return false;
    }
}

bool test_queue(){
    ArrayQueue queue(3);
    try {
        queue.push(100);
        queue.push(30);
        cout << queue.poll() << endl;
        cout << queue.poll() << endl;
        queue.push(50);
        queue.push(80);
        queue.push(80);
        queue.push(80);
        queue.push(80);
        cout << queue.poll() << endl;
        cout << queue.poll() << endl;
        return true;
    }catch (char const* str){
        cout << str << endl;
        return false;
    }
}

bool test_new_stack(){
    try {
        NewStack newStack(100);
        newStack.push(100);
        cout << newStack.get_min() << endl;
        newStack.push(80);
        cout << newStack.get_min() << endl;
        newStack.push(107);
        cout << newStack.get_min() << endl;
        newStack.push(23);
        cout << newStack.get_min() << endl;
        newStack.push(78);
        cout << newStack.get_min() << endl;

        cout << "begin pop" << endl;

        newStack.pop();
        cout << newStack.get_min() << endl;
        newStack.pop();
        cout << newStack.get_min() << endl;
        newStack.pop();
        cout << newStack.get_min() << endl;
        newStack.pop();
        cout << newStack.get_min() << endl;
        newStack.pop();
        cout << newStack.get_min() << endl;
        newStack.pop();
        cout << newStack.get_min() << endl;
        return true;
    }catch (const char* str){
        cout << str << endl;
        return false;
    }
}

bool test_two_stack_queue(){
    TwoStackQueue queue(3);
    try {
        queue.push(100);
        queue.push(30);
        cout << queue.poll() << endl;
        cout << queue.poll() << endl;
        queue.push(50);
        queue.push(80);
        cout << queue.poll() << endl;
        cout << queue.poll() << endl;
        cout << queue.peek() << endl;
        return true;
    }catch (char const* str){
        cout << str << endl;
        return false;
    }
}

bool test_two_queue_stack(){
    TwoQueueStack stack(3);
    try {
        stack.push(100);
        stack.push(50);
        stack.push(30);

        cout << stack.peek() << endl;
        cout << stack.peek() << endl;
        cout << stack.pop() << endl;
        cout << stack.pop() << endl;
        cout << stack.pop() << endl;
        return true;
    }catch (char const* str){
        cout << str << endl;
        return false;
    }
}

bool test_sort(sort_func func){
    /* Sort test */
    // system library Sort
    std::sort(arr,arr + arr_len);

    // tested Sort
    func(arr_copy,arr_len);

    // compare result
    if (!Util::is_equal(arr,arr_copy,arr_len)){
        Util::print_array(arr,arr_len," ");
        Util::print_array(arr_copy,arr_len," ");
        cout << endl;
        return false;
    }
    /* Sort test */

    return true;
}

bool test_matrix(){
    Matrix matrix(10,10,100,true,true);
    matrix.print_matrix();
//    matrix.print_matrix_rotate();
//    matrix.rotate_matrix();
//    matrix.print_matrix();
    matrix.print_matrix_round();

    cout << "---------------------------------"<< endl;

    return true;
}

bool test_singly_linked_list(){
    SinglyLinkedList linkedList;

    try {
        linkedList.insert(8);
        linkedList.print_list();
        linkedList.insert(9);
        linkedList.print_list();
        linkedList.insert(10);
        linkedList.print_list();
        linkedList.push_back(11);
        linkedList.print_list();
        linkedList.insert(12,1);
        linkedList.print_list();
        linkedList.reverse_list();
        linkedList.print_list();
        return true;
    }catch (const char * str){
        cout << str << endl;
    }
}

bool test_doubly_linked_list(){
    DoublyLinkedList linkedList;

    try {
        linkedList.insert(8);
        linkedList.print_list();
        linkedList.insert(9);
        linkedList.print_list();
        linkedList.insert(10);
        linkedList.print_list();
        linkedList.push_back(11);
        linkedList.print_list();
        linkedList.insert(12,1);
        linkedList.print_list();
        linkedList.reverse_list();
        linkedList.print_list();
        linkedList.print_list_reverse();

        return true;
    }catch (const char * str){
        cout << str << endl;
    }
}
