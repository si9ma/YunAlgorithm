//
// Created by si9ma on 10/1/18.
//

#include <iostream>
#include "singly_node.h"

namespace si9ma{
    SinglyNodeWithRand::SinglyNodeWithRand(int val) {
        this->value = val;
        next = nullptr;
    }

    SinglyNodeWithRand::~SinglyNodeWithRand() {
        std::cout << "destroy SinglyNode(" << value << ")" << std::endl;
    }

    void SinglyNodeWithRand::set_rand(SinglyNodeWithRand *val) {
        rand = val;
    }
}
