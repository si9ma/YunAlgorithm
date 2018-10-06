//
// Created by si9ma on 10/6/18.
//

#include <cstring>
#include "dp.h"

namespace si9ma{
    int DP::find_way_recursive(const int *arr, int length,int start, int aim, int step) {
        if(arr == nullptr || start < 0 || start >= length || aim < 0 || aim >= length)
            return 0;

        if(step == 0)
            return start == aim;

        if(start == 0)
            return find_way_recursive(arr,length,1,aim,step - 1);

        if(start == length - 1)
            return find_way_recursive(arr,length,length - 2,aim,step - 1);

        return find_way_recursive(arr,length,start + 1,aim,step - 1)
               + find_way_recursive(arr,length,start - 1,aim,step - 1);
    }

    int DP::find_way_dp(int *arr, int length, int start, int aim, int step) {
        if(arr == nullptr || start < 0 || start >= length || aim < 0 || aim >= length)
            return 0;

        int res_arr[length];
        int res_arr_tmp[length];
        memset(res_arr,0, length*sizeof(res_arr[0]));
        memset(res_arr_tmp,0, length*sizeof(res_arr_tmp[0]));

        res_arr[aim] = 1;
        bool tmp_is_main = true;
        for (int i = 1; i <= step ; ++i) {
            for (int j = 0; j < length ; ++j) {
                if (tmp_is_main)
                    res_arr_tmp[j] = j == 0 ? res_arr[j + 1]
                                            : (j == length - 1 ? res_arr[j - 1] : res_arr[j - 1] + res_arr[j + 1]);
                else
                    res_arr[j] = j == 0 ? res_arr_tmp[j + 1]
                                        : (j == length - 1 ? res_arr_tmp[j - 1] : res_arr_tmp[j - 1] + res_arr_tmp[j + 1]);
            }
            tmp_is_main = !tmp_is_main;
        }

        return tmp_is_main ? res_arr[start] : res_arr_tmp[start];
    }

    int DP::save_money_recursive(int *arr,int length,int index,int target) {
        if (arr == nullptr || target < 0)
            return 0;

        if (index == length)
            return target == 0;

        if (target == 0)
            return 1;

        int res = 0;
        for (int i = 0; i * arr[index] <= target; ++i) {
            res += save_money_recursive(arr,length,index + 1,target - i*arr[index]);
        }

        return res;
    }

    int DP::save_money_dp(int *arr, int length, int index, int target) {
        if (arr == nullptr || index < 0 || index >= length)
            return 0;

        int res_arr1[target + 1];
        int res_arr2[target + 1];
        memset(res_arr1,0, sizeof(res_arr1));
        memset(res_arr2,0, sizeof(res_arr2));
        bool is_first_main = false;
        res_arr1[0] = 1;

        for (int i = length - 1 ; i >= 0 ; --i) {
            for (int j = 0; j <= target; ++j) {
                if (is_first_main)
                    res_arr1[j] = res_arr2[j] + (j - arr[i] < 0 ? 0 : res_arr1[j - arr[i]]);
                else
                    res_arr2[j] = res_arr1[j] + (j - arr[i] < 0 ? 0:  res_arr2[j - arr[i]]);
            }

            is_first_main = !is_first_main;
        }

        return is_first_main ? res_arr2[target] : res_arr1[target];
    }
}
