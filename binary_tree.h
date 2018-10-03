//
// Created by si9ma on 10/3/18.
//

#ifndef ALGORITHM_BINARY_TREE_H
#define ALGORITHM_BINARY_TREE_H

#include "tree_node.h"
#include <string>

using namespace std;

namespace si9ma {

    struct BalanceInfo{
        bool is_balance;
        int height;

        BalanceInfo(bool is_balance,int height){
            this->is_balance = is_balance;
            this->height = height;
        }

        BalanceInfo() = default;
    };

    class BinaryTree {
    private:
        static void print_in_order(const TreeNode *head,int height,int len,string to);
        static string get_space(int num);

    public:
        BinaryTree() = default;
        ~BinaryTree() = default;

        static void iterative_pre_order(const TreeNode *head);
        static void iterative_in_order(const TreeNode *head);
        static void iterative_pos_order(const TreeNode *head);

        static void recursive_pre_order(const TreeNode *head);
        static void recursive_in_order(const TreeNode *head);
        static void recursive_pos_order(const TreeNode *head);
        static BalanceInfo is_balance_tree(const TreeNode *head);

        static void destroy_tree(TreeNode *head);

        /* for print binary tree*/
        static void print_tree(const TreeNode *head);
        /* for print binary tree*/
    };
}


#endif //ALGORITHM_BINARY_TREE_H
