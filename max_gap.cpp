//
// Created by si9ma on 9/30/18.
//

#include <climits>
#include <algorithm>
#include "max_gap.h"

using namespace std;

namespace si9ma{
    MaxGap::MaxGap() {

    }

    int MaxGap::max_gap(int *arr, int len) {
        if(len < 2){
            return 0;
        }

        int min = INT_MAX;
        int max = INT_MIN;
        for (int i = 0; i < len; ++i) {
            min = arr[i] < min ? arr[i] : min;
            max = arr[i] > max ? arr[i] : max;
        }

        if (min == max)
            return 0;

        // len + 1 bucket
        bool has_num[len + 1];
        std::fill_n(has_num,len + 1,false);
        int maxs[len + 1];
        int mins[len + 1];

        for (int j = 0; j < len; ++j) {
            int bid = bucket(arr[j],len,max,min); // must be len , not len + 1
            maxs[bid] = has_num[bid] ? std::max(maxs[bid],arr[j]) : arr[j];
            mins[bid] = has_num[bid] ? std::min(mins[bid],arr[j]) : arr[j];
            has_num[bid] = true;
        }

        int last_max = maxs[0];
        int res = 0;

        for (int k = 1; k <= len; ++k) {
            if (has_num[k]){
                res = std::max(res,mins[k] - last_max);
                last_max = maxs[k];
            }
        }

        return res;
    }

    // get the index of num in bucket
    int MaxGap::bucket(int num, int len, int max, int min) {
        return (num - min) * len / (max - min);
    }
}