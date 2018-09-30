//
// Created by si9ma on 9/29/18.
//

#ifndef ALGORITHM_MIN_SUM_H
#define ALGORITHM_MIN_SUM_H


namespace si9ma {
    class MinSum {

    public:
        MinSum();

        static int min_sum_bad(int *arr, int len);

        static int min_sum_good(int *arr, int len);

        static int process(int *arr, int L, int R);

        static int merge(int *arr, int L, int M, int R);
    };
}


#endif //ALGORITHM_MIN_SUM_H
