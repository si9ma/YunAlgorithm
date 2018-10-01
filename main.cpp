#include <ctime>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include "sort.h"
#include "test.h"
#include "util.h"

using si9ma::Util;
using si9ma::Sort;

typedef bool (*test_func_type)();

// test param
const int TEST_TIME = 100;
const int MAX_LEN = 10;
const int MAX_VAL = 100;

// two test array
int *arr;
int *arr_copy;

// test array length
int arr_len = 0;

// test result
bool is_success = true;
// just test once
bool is_once = false;
// allow negative value
bool allow_negative = false;

// test function pointer
test_func_type test_fun_ptr;

// prepare or clean
void prepare(); // prepare data
void clean(); // clean data

int main() {

    srand(time(0));

    // test
    for (int i = 0; i < TEST_TIME; ++i) {
        prepare();
        is_success = test_sort(Sort::radix_sort);
//        test_fun_ptr = test_matrix;
//        is_success = test_fun_ptr();
        clean();

        if (is_once || !is_success)
            break;
    }

    // test result
    std::cout << (is_success ? "\nNice\n" : "\nFuck\n");
}

void prepare(){
    /* prepare two array */
    arr = Util::generate_random_array(MAX_LEN,MAX_VAL,arr_len,allow_negative);
    arr_copy = new int[arr_len];
    memcpy(arr_copy,arr, sizeof(int) * arr_len);
    /* prepare two array */
}

void clean(){
    // delete two array
    delete [] arr;
    delete [] arr_copy;
}

