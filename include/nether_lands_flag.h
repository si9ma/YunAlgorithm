//
// Created by si9ma on 9/29/18.
//

#ifndef ALGORITHM_NETHER_LANDS_FLAG_H
#define ALGORITHM_NETHER_LANDS_FLAG_H

namespace si9ma {
    class nether_lands_flag {
    public:
        nether_lands_flag();

        template<int len, int len1>
        static void partition(int (&arr)[len], int (&equal_arr)[len1], int L, int R, int p);

        static void partition(int *arr, int *equal_arr, int L, int R, int p);
    };
}


#endif //ALGORITHM_NETHER_LANDS_FLAG_H
