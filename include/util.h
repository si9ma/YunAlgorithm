//
// Created by si9ma on 9/28/18.
//

#ifndef ALGORITHM_UTIL_H
#define ALGORITHM_UTIL_H

#include <string>

namespace si9ma{
    class Util {
    public:
        Util();

        template <int len> static void swap(int (&arr)[len], int idx1, int idx2);

        // swap two value in array use xor,idx1 must not equal to idx2
        template <int len> static void swap_xor(int (&arr)[len], int idx1, int idx2);

       static void swap(int *arr, int idx1, int idx2);

        // swap two value in array use xor,idx1 must not equal to idx2
       static void swap_xor(int *arr, int idx1, int idx2);

        // generate a random array with random length and random value
        // return a pointer to array,change final_len as array length
        // can't generate really max_val,max value is max_val - 1
        static int * generate_random_array(int max_len,int max_val,int &final_len);

        template <int len> static void print_array(const int (&arr)[len],std::string separator);

        static void print_array(const int * arr, const int len,std::string separator);

        template <int len> static bool is_equal(const int(&arr1)[len],const int(&arr2)[len]);

        static bool is_equal(const int * arr1,const int * arr2,int len);
    };
}

#endif //ALGORITHM_UTIL_H
