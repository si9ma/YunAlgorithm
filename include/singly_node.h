//
// Created by si9ma on 10/1/18.
//

#ifndef ALGORITHM_NODE_H
#define ALGORITHM_NODE_H


namespace si9ma {
    class SinglyNodeWithRand {
    public:
        SinglyNodeWithRand * next;
        SinglyNodeWithRand * rand;
        int value;

        SinglyNodeWithRand(int val);
        SinglyNodeWithRand() = default;
        void set_rand(SinglyNodeWithRand *val);
        ~SinglyNodeWithRand();
    };
}


#endif //ALGORITHM_NODE_H
