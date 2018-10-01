//
// Created by si9ma on 10/2/18.
//

#ifndef ALGORITHM_DOUBLY_NODE_H
#define ALGORITHM_DOUBLY_NODE_H

namespace si9ma {
    class DoublyNode {
    public:
        DoublyNode *prev;
        DoublyNode *next;
        int value;

        DoublyNode(int val);
        DoublyNode() = default;
        ~DoublyNode();
    };
}


#endif //ALGORITHM_DOUBLY_NODE_H
