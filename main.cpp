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

// test param
const int TEST_TIME = 1;
const int MAX_LEN = 10;
const int MAX_VAL = 100;

// two test array
int *arr;
int *arr_copy;

// test array length
int arr_len = 0;

// test result
bool is_success = true;

using namespace std;
using namespace si9ma;

typedef void (*sort_func)(int *arr,int len);

/* test */
void test_sort(sort_func func); // Sort test
void test_heap();
void test_max_gap();
void test_stack();
void test_queue();
void test_new_stack();
void test_two_stack_queue();
void test_two_queue_stack();
/* test */

// prepare or clean
void prepare(); // prepare data
void clean(); // clean data

template <int len>
int get_len(int (&arr)[len]){
    return len;
}

int main() {

    srand(time(0));

    // test
    for (int i = 0; i < TEST_TIME; ++i) {
        prepare();
//        test_sort(Sort::heap_sort);
//        test_heap();
//        test_max_gap();
//        test_stack();
//        test_queue();
//        test_new_stack();
//        test_two_stack_queue();
        test_two_queue_stack();
        clean();
    }

    // test result
    std::cout << (is_success ? "Nice\n" : "Fuck\n");
}

void test_sort(sort_func func){
    /* Sort test */
    // system library Sort
    std::sort(arr,arr + arr_len);

    // tested Sort
    func(arr_copy,arr_len);

    // compare result
    if (!Util::is_equal(arr,arr_copy,arr_len)){
        is_success = false;

        Util::print_array(arr,arr_len," ");
        Util::print_array(arr_copy,arr_len," ");
        cout << endl;
    }
    /* Sort test */
}

void prepare(){
    /* prepare two array */
    arr = Util::generate_random_array(MAX_LEN,MAX_VAL,arr_len);
    arr_copy = new int[arr_len];
    memcpy(arr_copy,arr, sizeof(int) * arr_len);
    /* prepare two array */
}

void clean(){
    // delete two array
    delete [] arr;
    delete [] arr_copy;
}

void test_heap(){
    int heap_size = 0;

    // build Heap
    for (int i = 0; i < arr_len; ++i) {
        Heap::heap_insert(arr,i);
    }

    Util::print_array(arr,arr_len," ");
    Util::print_array(arr_copy,arr_len," ");
    cout << endl;
}

void test_max_gap(){
    Util::print_array(arr,arr_len," ");
    std::sort(arr_copy,arr_copy + arr_len);
    Util::print_array(arr_copy,arr_len," ");
    cout << MaxGap::max_gap(arr,arr_len) << "\n" << endl;
}

void test_stack(){
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
    }catch (char const* str){
        cout << str << endl;
    }
}

void test_queue(){
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
    }catch (char const* str){
        cout << str << endl;
    }
}

void test_new_stack(){
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
    }catch (const char* str){
        cout << str << endl;
    }
}

void test_two_stack_queue(){
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
    }catch (char const* str){
        cout << str << endl;
    }
}

void test_two_queue_stack(){
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
    }catch (char const* str){
        cout << str << endl;
    }
}
