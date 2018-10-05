//
// Created by si9ma on 10/5/18.
//

#include "union_find_set.h"
#include <stack>

namespace si9ma{
    UnionFindSet::UnionFindSet(int *list, int len) {
        for (int i = 0; i < len; ++i) {
            father_map[list[i]] = list[i];
            rank_map[list[i]] = 1;
        }
    }

    int UnionFindSet::find_header(int val) {
        stack<int> s_stack;
        while (val != father_map[val]){
            s_stack.push(val);
            val = father_map[val];
        }

        while (!s_stack.empty()){
            father_map[s_stack.top()] = val;
            s_stack.pop();
        }

        return val;
    }

    bool UnionFindSet::is_same_set(int first_val, int second_val) {
        return find_header(first_val) == find_header(second_val);
    }

    void UnionFindSet::union_set(int val1, int val2) {
        int head1 = find_header(val1);
        int head2 = find_header(val2);

        int num1 = rank_map[head1];
        int num2 = rank_map[head2];

        if (num2 > num1){
            father_map[head1] = head2;
            rank_map[head2] = rank_map[head1] + rank_map[head2];
            rank_map.erase(head1);
        } else{
            father_map[head2] = head1;
            rank_map[head1] = rank_map[head1] + rank_map[head2];
            rank_map.erase(head2);
        }
    }
}
