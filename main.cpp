#include <cstring>
#include <iostream>
#include <sort.h>
#include <algorithm>
#include <min_sum.h>
#include "util.h"

int main() {
    using si9ma::util;
    using si9ma::sort;
    using si9ma::min_sum;

    srand(time(0));
    int test_time = 100000;
    int max_len = 10;
    int max_val = 100;
    int arr_len = 0;
    int *arr;
    int *arr_copy;
    bool is_success = true;

    for (int i = 0; i < test_time; ++i) {
        arr = util::generate_random_array(max_len,max_val,arr_len);
        arr_copy = new int[arr_len];
        memcpy(arr_copy,arr, sizeof(int) * arr_len);

//        sort::merge_sort(arr,arr_len);
//        util::print_array(arr,arr_len," ");
        int bad = min_sum::min_sum_bad(arr,arr_len);
        int me = min_sum::min_sum_good(arr_copy,arr_len);
        if (bad != me){
            is_success = false;
            util::print_array(arr,arr_len," ");
            std::cout << "bad:" << bad << " me:" << me << std::endl;
            delete [] arr;
            delete [] arr_copy;
            break;
        }

//        std::sort(arr_copy,arr_copy + arr_len);
//        if (!util::is_equal(arr,arr_copy,arr_len)){
//            is_success = false;
//
//            std::cout << "me:";
//            util::print_array(arr,arr_len," ");
//            std::cout << "library:";
//            util::print_array(arr_copy,arr_len," ");
//            break;
//        }

        delete [] arr;
        delete [] arr_copy;
    }

    std::cout << (is_success ? "Nice\n" : "Fuck\n");
}