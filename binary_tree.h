//
// Created by si9ma on 10/3/18.
//

#ifndef ALGORITHM_BINARY_TREE_H
#define ALGORITHM_BINARY_TREE_H

#include "tree_node.h"
#include <string>
#include <vector>
#include <queue>

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

    struct MaxDistanceData{
        int max_distance;
        int height;

        MaxDistanceData(int max_distance,int height){
            this->max_distance = max_distance;
            this->height = height;
        }

        MaxDistanceData() = default;
    };

    struct SearchTreeData{
        bool is_search;
        int max;
        int min;

        SearchTreeData(bool is_search,int max,int min){
            this->is_search = is_search;
            this->max = max;
            this->min = min;
        }
    };

    class BinaryTree {
    private:
        static void print_in_order(const TreeNode *head,int height,int len,string to);
        static string get_space(int num);
        static TreeNode *restore_process_pre_order(queue<string>& str);
        static TreeNode *generate_node(string str);
        static void paper_fold_process(int layer,int total_layer,bool is_ao);
        static int get_left_most_layer(const TreeNode *head);
        static int get_node_count_process(const TreeNode *head,int total_layer,int cur_layer);

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
        static MaxDistanceData get_max_distance(const TreeNode *head);
        static bool is_search_tree(const TreeNode *head);
        static SearchTreeData is_search_tree_recursive(const TreeNode *head);
        static const TreeNode *get_pre(const TreeNode *head);
        static const TreeNode *get_next(const TreeNode *head);
        static const TreeNode *get_left_most(const TreeNode *head);
        static const TreeNode *get_right_most(const TreeNode *head);
        static string in_order_serial(const TreeNode *head);
        static TreeNode *restory_tree_pre_order(const string);
        static void level_print(const TreeNode *head);
        static string level_serial(const TreeNode *head);
        static TreeNode *restory_tree_level(const string);
        static void paper_fold_print(int num);
        static bool is_complete_binary_tree(const TreeNode *head);
        static int get_node_count(const TreeNode *head);

        static void destroy_tree(TreeNode *head);

        /* for print binary tree*/
        static void print_tree(const TreeNode *head);
        /* for print binary tree*/
    };
}


#endif //ALGORITHM_BINARY_TREE_H
