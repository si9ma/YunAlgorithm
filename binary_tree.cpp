//
// Created by si9ma on 10/3/18.
//

#include <iostream>
#include "binary_tree.h"
#include <stack>

namespace si9ma {
    void BinaryTree::print_tree(const TreeNode *head) {
        cout << "Binary Tree" << endl;
        print_in_order(head,0,17,"H");
        cout << endl;
    }

    void BinaryTree::print_in_order(const TreeNode *head, int height, int len, string to) {
        if (head == nullptr)
            return;

        print_in_order(head->right,height + 1,len,"v");
        string val = to + to_string(head->value) + to;
        long len_m = val.length();
        long len_l = (len - len_m) / 2;
        long len_r = len - len_m - len_l;
        val = get_space(len_l) + val + get_space(len_r);
        cout << get_space(height * len) + val << endl;
        print_in_order(head->left,height + 1,len,"^");
    }

    string BinaryTree::get_space(int num) {
        string res;

        for (int i = 0; i < num; ++i) {
            res += " ";
        }

        return res;
    }

    void BinaryTree::recursive_pre_order(const TreeNode *head) {
        if (head == nullptr)
            return;

        cout << head->value << " ";
        recursive_pre_order(head->left);
        recursive_pre_order(head->right);
    }

    void BinaryTree::recursive_in_order(const TreeNode *head) {
        if (head == nullptr)
            return;

        recursive_in_order(head->left);
        cout << head->value << " ";
        recursive_in_order(head->right);
    }

    void BinaryTree::recursive_pos_order(const TreeNode *head) {
        if (head == nullptr)
            return;

        recursive_pos_order(head->left);
        recursive_pos_order(head->right);
        cout << head->value << " ";
    }

    void BinaryTree::destroy_tree(TreeNode *head) {
        if (head == nullptr)
            return;

        destroy_tree(head->left);
        destroy_tree(head->right);
        delete head;
    }

    void BinaryTree::iterative_pre_order(const TreeNode *head) {
        if (head == nullptr)
            return;

        stack<const TreeNode *> s_stack;
        s_stack.push(head);
        while (!s_stack.empty()){
            head = s_stack.top();
            cout << head->value << " ";
            s_stack.pop();

            if (head->right != nullptr)
                s_stack.push(head->right);

            if (head->left != nullptr)
                s_stack.push(head->left);
        }
    }

    void BinaryTree::iterative_in_order(const TreeNode *head) {
        if (head == nullptr)
            return;

        stack<const TreeNode *> s_stack;
        while (!s_stack.empty() || head != nullptr){
            if (head != nullptr){
                s_stack.push(head);
                head = head->left;
            } else{
                head = s_stack.top()->right;
                cout << s_stack.top()->value << " ";
                s_stack.pop();
            }
        }
    }

    void BinaryTree::iterative_pos_order(const TreeNode *head) {
        if (head == nullptr)
            return;
        stack<const TreeNode *> s_stack1;
        stack<const TreeNode *> s_stack2;

        s_stack1.push(head);
        while (!s_stack1.empty()){
            head = s_stack1.top();
            s_stack2.push(head);
            s_stack1.pop();

            if (head->left != nullptr)
                s_stack1.push(head->left);

            if (head->right != nullptr)
                s_stack1.push(head->right);
        }

        while (!s_stack2.empty()){
            head = s_stack2.top();
            cout << head->value << " ";
            s_stack2.pop();
        }
    }

    BalanceInfo BinaryTree::is_balance_tree(const TreeNode *head) {
        if (head == nullptr)
            return BalanceInfo{true,0};

        BalanceInfo res;
        auto left_info = is_balance_tree(head->left);
        auto right_info = is_balance_tree(head->right);

        res.height = max(left_info.height,right_info.height) + 1;
        res.is_balance = left_info.is_balance && right_info.is_balance && (abs(left_info.height - right_info.height) < 2);

        return res;
    }
}
