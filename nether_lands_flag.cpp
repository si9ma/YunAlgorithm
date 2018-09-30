//
// Created by si9ma on 9/29/18.
//

#include "util.h"
#include "nether_lands_flag.h"

namespace si9ma{
    NetherLandsFlag::NetherLandsFlag() {

    }

    void NetherLandsFlag::partition(int *arr, int *equal_arr, int L, int R, int p) {
        int less = L - 1;
        int more = R + 1;
        int index = L;

        while (index < more){
            if(arr[index] < p)
                Util::swap(arr,++less,index ++);
            else if(arr[index] > p)
                Util::swap(arr,--more,index);
            else
                index++;
        }

        equal_arr[0] = less + 1;
        equal_arr[1] = more - 1;
    }
}
