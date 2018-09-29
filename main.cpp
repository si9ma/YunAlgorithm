#include <cstring>
#include <iostream>
#include <sort.h>
#include <algorithm>
#include <min_sum.h>
#include "util.h"
#include "nether_lands_flag.h"
#include "heap.h"

// test param
const int TEST_TIME = 100000;
const int MAX_LEN = 10;
const int MAX_VAL = 100;

// two test array
int *arr;
int *arr_copy;

// test array length
int arr_len = 0;

// test result
bool is_success = true;

using si9ma::util;
using si9ma::sort;
using si9ma::min_sum;
using si9ma::heap;
using si9ma::nether_lands_flag;
using std::cout;
using std::endl;

typedef void (*sort_func)(int *arr,int len);

/* test */
void test_sort(sort_func func); // sort test
void test_heap();
/* test */

// prepare or clean
void prepare(); // prepare data
void clean(); // clean data

int main() {

    srand(time(0));

    // test
    for (int i = 0; i < TEST_TIME; ++i) {
        prepare();
        test_sort(sort::heap_sort);
//        test_heap();
        clean();
    }

    // test result
    std::cout << (is_success ? "Nice\n" : "Fuck\n");
}

void test_sort(sort_func func){
    /* sort test */
    // system library sort
    std::sort(arr,arr + arr_len);

    // tested sort
    func(arr_copy,arr_len);

    // compare result
    if (!util::is_equal(arr,arr_copy,arr_len)){
        is_success = false;

        util::print_array(arr,arr_len," ");
        util::print_array(arr_copy,arr_len," ");
        cout << endl;
    }
    /* sort test */
}

void prepare(){
    /* prepare two array */
    arr = util::generate_random_array(MAX_LEN,MAX_VAL,arr_len);
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

    // build heap
    for (int i = 0; i < arr_len; ++i) {
        heap::heap_insert(arr,i);
    }

    util::print_array(arr,arr_len," ");
    util::print_array(arr_copy,arr_len," ");
    cout << endl;
}