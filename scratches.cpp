//
// Created by si9ma on 10/2/18.
//

#include <iostream>
#include "scratches.h"
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool is_scratches_test = false;

bool test_scratches(){
    vector<int> nums{1,3,4,6,9,23,34,56};
    for(int last_nonzero_idx=0,cur=0;cur < nums.size();cur++){
        if(nums[cur] %2 == 0)
            swap(nums[last_nonzero_idx++],nums[cur]);
    }

    for (int item:nums){
        cout << item << " ";
    }
}
