//
// Created by si9ma on 10/2/18.
//

#include <iostream>
#include "doubly_node.h"

namespace si9ma{
    DoublyNode::DoublyNode(int val) {
        value = val;
        prev = next = nullptr;
    }

    DoublyNode::~DoublyNode() {
        std::cout << "destroy DoublyNode(" << value << ")" << std::endl;
    }
}
