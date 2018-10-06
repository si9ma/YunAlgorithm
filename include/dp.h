//
// Created by si9ma on 10/6/18.
//

#ifndef ALGORITHM_DP_H
#define ALGORITHM_DP_H


namespace si9ma {
    class DP {

    public:
        static int find_way_recursive(const int *arr,int length,int start,int aim,int step);
        static int find_way_dp(int *arr,int length,int start,int aim,int step);
        static int save_money_recursive(int *arr,int length,int index,int target);
        static int save_money_dp(int *arr,int length,int index,int target);
    };
}


#endif //ALGORITHM_DP_H
