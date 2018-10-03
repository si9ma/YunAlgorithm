//
// Created by si9ma on 10/3/18.
//

#ifndef ALGORITHM_TREE_NODE_H
#define ALGORITHM_TREE_NODE_H

namespace si9ma {
    class TreeNode {
    public:
        int value;
        TreeNode *left;
        TreeNode *right;
        TreeNode *parent;

        TreeNode(int value);
        ~TreeNode();
    };
}

#endif //ALGORITHM_TREE_NODE_H
