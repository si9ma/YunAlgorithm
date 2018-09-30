//
// Created by si9ma on 9/29/18.
//

#include "min_sum.h"

namespace si9ma{
    MinSum::MinSum() {

    }

    int MinSum::min_sum_bad(int *arr, int len) {
        int min_sum = 0;

        for (int i = 1; i < len; ++i) {
            for (int j = i - 1; j >= 0; j--) {
                if(arr[j] < arr[i])
                    min_sum += arr[j];
            }
        }

        return min_sum;
    }

    int MinSum::min_sum_good(int *arr, int len) {
        return process(arr,0,len - 1);
    }

    int MinSum::process(int *arr, int L, int R) {
        if (L == R)
            return 0;

        int M = ( L + R ) / 2;

        return process(arr,L,M) +
                process(arr,M + 1,R) +
                merge(arr,L,M,R); // 复杂度 -->T(N)
    }

    int MinSum::merge(int *arr, int L, int M, int R) {
        int left_ptr = L,right_ptr = M + 1,tmp_ptr = 0,tmp_arr_len = R - L + 1,res = 0;
        int tmp_arr[tmp_arr_len];

        while (left_ptr <= M && right_ptr <= R){
            res += arr[left_ptr] < arr[right_ptr] ? arr[left_ptr] * (R - right_ptr + 1) : 0;
            tmp_arr[tmp_ptr++] = arr[left_ptr] < arr[right_ptr] ? arr[left_ptr ++] : arr[right_ptr++];
        }

        while (left_ptr <= M)
            tmp_arr[tmp_ptr ++] = arr[left_ptr++];

        while (right_ptr <= R)
            tmp_arr[tmp_ptr++] = arr[right_ptr++];

        for (int i = 0; i < tmp_arr_len; ++i) {
            arr[L + i] = tmp_arr[i];
        }

        return res;
    }
}
