//
// Created by si9ma on 10/1/18.
//

#ifndef ALGORITHM_NODE_H
#define ALGORITHM_NODE_H


namespace si9ma {
    class SinglyNode {
    public:
        SinglyNode * next;
        int value;

        SinglyNode(int val);
        SinglyNode() = default;
        ~SinglyNode();
    };
}


#endif //ALGORITHM_NODE_H
