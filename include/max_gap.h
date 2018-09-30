//
// Created by si9ma on 9/30/18.
//

#ifndef ALGORITHM_MAX_GAP_H
#define ALGORITHM_MAX_GAP_H


namespace si9ma {
    class MaxGap {
    public:
        MaxGap();

        static int max_gap(int *arr,int len);

        static int bucket(int num,int len,int max,int min);
    };
}


#endif //ALGORITHM_MAX_GAP_H
