//
// Created by si9ma on 10/3/18.
//

#include <iostream>
#include "tree_node.h"

using namespace std;

namespace si9ma{
    TreeNode::TreeNode(int value) {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }

    TreeNode::~TreeNode() {
        cout << "destroy TreeNode(" << value << ")" << endl;
    }
}
