//
// Created by si9ma on 9/29/18.
//

#ifndef ALGORITHM_MIN_SUM_H
#define ALGORITHM_MIN_SUM_H


namespace si9ma {
    class min_sum {

    public:
        min_sum();

        template<int len>
        static int min_sum_bad(int (&arr)[len]);

        template<int len>
        static int min_sum_good(int (&arr)[len]);

        template<int len>
        static int process(int (&arr)[len], int L, int R);

        template<int len>
        static int merge(int (&arr)[len], int L, int M, int R);

        static int min_sum_bad(int *arr, int len);

        static int min_sum_good(int *arr, int len);

        static int process(int *arr, int L, int R);

        static int merge(int *arr, int L, int M, int R);
    };
}


#endif //ALGORITHM_MIN_SUM_H
