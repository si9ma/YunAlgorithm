//
// Created by si9ma on 10/5/18.
//

#ifndef ALGORITHM_UNION_FIND_SET_H
#define ALGORITHM_UNION_FIND_SET_H

#include <unordered_map>

using namespace std;

namespace si9ma {
    class UnionFindSet {

    private:
        unordered_map<int,int> father_map;
        unordered_map<int,int> rank_map;

    public:
        UnionFindSet(int list[],int len);
        bool is_same_set(int first_val,int second_val);
        int find_header(int val);
        void union_set(int val1,int val2);
        ~UnionFindSet() = default;
    };
}


#endif //ALGORITHM_UNION_FIND_SET_H
