//
// Created by si9ma on 9/29/18.
//

#ifndef ALGORITHM_NETHER_LANDS_FLAG_H
#define ALGORITHM_NETHER_LANDS_FLAG_H

namespace si9ma {
    class NetherLandsFlag {
    public:
        NetherLandsFlag();

        static void partition(int *arr, int *equal_arr, int L, int R, int p);
    };
}


#endif //ALGORITHM_NETHER_LANDS_FLAG_H
