//
// Created by si9ma on 10/1/18.
//

#ifndef ALGORITHM_LIST_H
#define ALGORITHM_LIST_H

#include "singly_node.h"
#include <string>

using namespace std;

namespace si9ma{
    class SinglyLinkedList {
    private:
        SinglyNodeWithRand *head;
        SinglyNodeWithRand *tail;
        int size;

        static SinglyNodeWithRand *common_loop_intersection(SinglyNodeWithRand *head1,SinglyNodeWithRand *head2,SinglyNodeWithRand *list_terminal);
        static SinglyNodeWithRand *both_loop_intersection(SinglyNodeWithRand *head1,SinglyNodeWithRand *head2);

    public:
        SinglyLinkedList();
        ~SinglyLinkedList();
        bool is_empty();

        void push_back(int val);
        void insert(int val,int index=0);
        void remove(int index=0);
        SinglyNodeWithRand *get_prev(SinglyNodeWithRand *node);
        SinglyNodeWithRand *get_node(int index=0);
        void print_list(string separator=" ");
        void reverse_list();

        static void print_list(SinglyNodeWithRand *head,string separator=" ");
        static void reverse_list(SinglyNodeWithRand **head);
        static void insert(SinglyNodeWithRand **head,int val,int index=0);
        static void remove(SinglyNodeWithRand **head,int index=0);
        static void delete_list(SinglyNodeWithRand **head);
        static bool is_palindroom1(SinglyNodeWithRand *head);
        static bool is_palindroom2(SinglyNodeWithRand *head);
        static bool is_palindroom3(SinglyNodeWithRand *head);
        static void partition_list1(SinglyNodeWithRand *head,int p);
        static void partition_list2(SinglyNodeWithRand **head,int p);
        static SinglyNodeWithRand * deep_clone1(SinglyNodeWithRand *head);
        static SinglyNodeWithRand * deep_clone2(SinglyNodeWithRand *head);

        // use set
        static SinglyNodeWithRand *get_loop_node1(SinglyNodeWithRand *head);
        static SinglyNodeWithRand *get_loop_node2(SinglyNodeWithRand *head);
        static SinglyNodeWithRand *get_intersection(SinglyNodeWithRand *head1,SinglyNodeWithRand *head2);
    };
}

#endif //ALGORITHM_LIST_H
