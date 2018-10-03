//
// Created by si9ma on 10/2/18.
//

#include "binary_search.h"

namespace si9ma{

    // find local min,not global min
    // return index
    int BinarySearch::find_local_min(int *arr, int L,int R) {
        if(R < L)
            throw "invalid length";

        if(L == R)
            return L;

        if(arr[L] < arr[L + 1])
            return L;

        if(arr[R] < arr[R - 1])
            return R;

        while (L <= R){
            int mid = L + (R - L)/2;

            if(arr[mid] < arr[mid - 1] && arr[mid] < arr[mid + 1])
                return mid;

            if(arr[mid] > arr[mid - 1]){
                R = mid - 1;
                continue;
            }

            L = mid + 1;
        }
    }
}
