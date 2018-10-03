//
// Created by si9ma on 10/3/18.
//

#include <iostream>
#include "binary_tree.h"
#include <stack>
#include "util.h"
#include <climits>

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

    MaxDistanceData BinaryTree::get_max_distance(const TreeNode *head) {
        if (head == nullptr)
            return MaxDistanceData{0,0};

        MaxDistanceData res;
        auto left_max = get_max_distance(head->left);
        auto right_max = get_max_distance(head->right);
        int max3 = left_max.height + right_max.height + 1;
        int tmp = max(left_max.max_distance,right_max.max_distance);

        res.max_distance = max(tmp,max3);
        res.height = max(left_max.height,right_max.height) + 1;

        return res;
    }

    bool BinaryTree::is_search_tree(const TreeNode *head) {
        if (head == nullptr)
            return true;

        stack<const TreeNode *> s_stack;
        int pre = INT_MIN;

        while (!s_stack.empty() || head != nullptr){
            if (head != nullptr){
                s_stack.push(head);
                head = head->left;
            } else{
                int val = s_stack.top()->value;
                if (val <= pre)
                    return false;

                pre = val;
                head = s_stack.top()->right;
                s_stack.pop();
            }
        }

        return true;
    }

    SearchTreeData BinaryTree::is_search_tree_recursive(const TreeNode *head) {
        if (head == nullptr)
            return SearchTreeData{true,INT_MIN,INT_MAX};

        auto left_info = is_search_tree_recursive(head->left);
        auto right_info = is_search_tree_recursive(head->right);
        int max_val = max(head->value,max(left_info.max,right_info.max));
        int min_val = min(head->value,min(left_info.min,right_info.min));
        bool is_search = left_info.is_search && right_info.is_search &&
                left_info.max < head->value && right_info.min > head->value;

        return SearchTreeData{is_search,max_val,min_val};
    }

    const TreeNode* BinaryTree::get_pre(const TreeNode *head) {
        if (head == nullptr)
            return head;

        if (head->left != nullptr)
            return get_right_most(head->left);
        else{
            auto *cur = head;
            auto *parent = head->parent;

            while (parent != nullptr && parent->right != cur){
                cur = parent;
                parent = parent->parent;
            }

            return parent;
        }
    }

    const TreeNode* BinaryTree::get_next(const TreeNode *head) {
        if (head == nullptr)
            return head;

        if (head->right != nullptr)
            return get_left_most(head->right);
        else{
            auto *cur = head;
            auto *parent = head->parent;

            while (parent != nullptr && parent->left != cur){
                cur = parent;
                parent = parent->parent;
            }

            return parent;
        }
    }

    const TreeNode* BinaryTree::get_left_most(const si9ma::TreeNode *head) {
        if (head == nullptr)
            return head;

        auto *ptr = head;
        while (ptr->left != nullptr)
            ptr = ptr->left;

        return ptr;
    }

    const TreeNode* BinaryTree::get_right_most(const si9ma::TreeNode *head) {
        if (head == nullptr)
            return head;

        auto *ptr = head;
        while (ptr->right != nullptr)
            ptr = ptr->right;

        return ptr;
    }

    string BinaryTree::in_order_serial(const TreeNode *head) {
        if (head == nullptr)
            return "#_";

        string res;
        res += to_string(head->value) + "_";
        res += in_order_serial(head->left);
        res += in_order_serial(head->right);

        return res;
    }

    TreeNode* BinaryTree::restory_tree_pre_order(const string str) {
        queue<string> q_queue;
        Util::split(str,'_',q_queue);
        return restore_process_pre_order(q_queue);
    }

    TreeNode* BinaryTree::restore_process_pre_order(queue<string>& str) {
        if ("#" == str.front()){
            str.pop();
            return nullptr;
        }

        auto *head = new TreeNode(stoi(str.front()));
        str.pop();
        head->left = restore_process_pre_order(str);
        head->right = restore_process_pre_order(str);

        return head;
    }

    void BinaryTree::level_print(const si9ma::TreeNode *head) {
        if (head == nullptr)
            return;

        queue<const TreeNode *> q_queue;
        q_queue.push(head);
        while (!q_queue.empty()){
            head = q_queue.front();
            cout << head->value << " ";
            q_queue.pop();

            if (head->left != nullptr)
                q_queue.push(head->left);

            if (head->right != nullptr)
                q_queue.push(head->right);
        }
    }

    string BinaryTree::level_serial(const si9ma::TreeNode *head) {
        if (head == nullptr)
            return "#_";

        string res;
        queue<const TreeNode *> q_queue;
        q_queue.push(head);
        res += to_string(head->value) + "_";
        while (!q_queue.empty()){
            head = q_queue.front();
            q_queue.pop();

            if (head->left != nullptr){
                q_queue.push(head->left);
                res += to_string(head->left->value) + "_";
            } else{
                res += "#_";
            }

            if (head->right != nullptr){
                q_queue.push(head->right);
                res += to_string(head->right->value) + "_";
            } else{
                res += "#_";
            }
        }

        return res;
    }

    TreeNode* BinaryTree::restory_tree_level(const string str) {
        queue<string> str_queue;
        queue<TreeNode *> node_queue;
        Util::split(str,'_',str_queue);

        auto *head = new TreeNode(stoi(str_queue.front()));
        str_queue.pop();
        if (head != nullptr)
            node_queue.push(head);

        auto *ptr = head;
        while (!node_queue.empty()){
            ptr = node_queue.front();
            node_queue.pop();
            ptr ->left = generate_node(str_queue.front());
            str_queue.pop();
            ptr ->right = generate_node(str_queue.front());
            str_queue.pop();

            if (ptr ->left != nullptr)
                node_queue.push(ptr ->left);

            if (ptr ->right != nullptr)
                node_queue.push(ptr ->right);
        }

        return head;
    }

    TreeNode* BinaryTree::generate_node(string str) {
        if ("#" == str)
            return nullptr;

        return new TreeNode(stoi(str));
    }

    void BinaryTree::paper_fold_print(int num) {
        paper_fold_process(1,num,true);
    }

    void BinaryTree::paper_fold_process(int layer, int total_layer, bool is_ao) {
        if (layer > total_layer)
            return;

        paper_fold_process(layer + 1,total_layer,true);
        cout << (is_ao ? "凹" : "凸") << " ";
        paper_fold_process(layer + 1,total_layer, false);
    }

    bool BinaryTree::is_complete_binary_tree(const si9ma::TreeNode *head) {
        if (head == nullptr)
            return true;

        bool leaf = false;
        queue<const TreeNode *> node_queue;
        node_queue.push(head);
        while (!node_queue.empty()){
            head = node_queue.front();
            node_queue.pop();

            if ((leaf && (head->left != nullptr || head->right != nullptr))
                 || (head->left == nullptr && head->right != nullptr))
                return false;

            if (head->left == nullptr || head->right == nullptr)
                leaf = true;

            if (head->left != nullptr)
                node_queue.push(head->left);

            if (head->right != nullptr)
                node_queue.push(head->right);
        }

        return true;
    }

    int BinaryTree::get_node_count(const si9ma::TreeNode *head) {
        if (head == nullptr)
            return 0;

        int height = get_left_most_layer(head);
        return get_node_count_process(head,height,1);
    }

    int BinaryTree::get_left_most_layer(const si9ma::TreeNode *head) {
        if (head == nullptr)
            return 0;

        int count = 0;
        while (head != nullptr){
            count ++;
            head = head->left;
        }

        return count;
    }

    int BinaryTree::get_node_count_process(const si9ma::TreeNode *head,int total_layer,int cur_layer) {
        if (head == nullptr )
            return 0;

        int right_height = get_left_most_layer(head->right);
        int left_height = total_layer - cur_layer;
        if (right_height == left_height){
            return ( 1 << left_height) + get_node_count_process(head->right,total_layer,cur_layer + 1);
        } else{
            return ( 1 << right_height ) + get_node_count_process(head->left,total_layer,cur_layer + 1);
        }
    }
}
