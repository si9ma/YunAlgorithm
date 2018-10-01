//
// Created by si9ma on 10/1/18.
//

#include <iostream>
#include "singly_node.h"

namespace si9ma{
    SinglyNode::SinglyNode(int val) {
        this->value = val;
        next = nullptr;
    }

    SinglyNode::~SinglyNode() {
        std::cout << "destroy SinglyNode(" << value << ")" << std::endl;
    }
}
