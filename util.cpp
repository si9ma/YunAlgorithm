//
// Created by si9ma on 9/28/18.
//

#include <ctime>
#include <cstdlib>
#include <iostream>
#include "util.h"

namespace si9ma{

    Util::Util() {

    }

    // swap two value in array use xor
    // idx1 must not equal to idx2
    template <int len>
    void Util::swap_xor(int (&arr)[len],int idx1,int idx2)
    {
        arr[idx1] = arr[idx1] ^ arr[idx2];
        arr[idx2] = arr[idx1] ^ arr[idx2];
        arr[idx1] = arr[idx1] ^ arr[idx2];
    }

    template <int len>
    void Util::swap(int (&arr)[len],int idx1,int idx2)
    {
        int tmp = arr[idx2];
        arr[idx2] = arr[idx1];
        arr[idx1] = tmp;
    }

    // swap two value in array use xor
    // idx1 must not equal to idx2
    void Util::swap_xor(int *arr,int idx1,int idx2)
    {
        arr[idx1] = arr[idx1] ^ arr[idx2];
        arr[idx2] = arr[idx1] ^ arr[idx2];
        arr[idx1] = arr[idx1] ^ arr[idx2];
    }

    void Util::swap(int *arr,int idx1,int idx2)
    {
        int tmp = arr[idx2];
        arr[idx2] = arr[idx1];
        arr[idx1] = tmp;
    }

    int* Util::generate_random_array(int max_len, int max_val, int &final_len)
    {
        final_len = rand() % max_len + 1; // 1 ~ max_len
        int *array = new int[final_len];
        for (int i = 0; i < final_len; ++i) {
            array[i] = (rand() % max_val) - (rand() % max_val); // -(max_val - 1) ~ max_val - 1
        }

        return array;
    }

    template <int len>
    void Util::print_array(const int (&arr)[len],std::string separator) {
        for(int item:arr){
            std::cout << item << separator;
        }

        std::cout << std::endl;
    }

    void Util::print_array(const int *arr, const int len,std::string separator){
        for (int i = 0; i < len; ++i) {
            std::cout << arr[i] << separator;
        }

        std::cout << std::endl;
    }

    template <int len>
    bool Util::is_equal(const int (&arr1)[len], const int (&arr2)[len]) {
        for (int i = 0; i < len; ++i) {
            if (arr1[i] != arr2[i])
                return false;
        }

        return true;
    }

    bool Util::is_equal(const int *arr1, const int *arr2, int len){
        for (int i = 0; i < len; ++i) {
            if (arr1[i] != arr2[i])
                return false;
        }

        return true;
    }
}

