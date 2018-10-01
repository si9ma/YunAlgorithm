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
        SinglyNode *head;
        SinglyNode *tail;
        int size;

    public:
        SinglyLinkedList();
        ~SinglyLinkedList();
        bool is_empty();

        void push_back(int val);
        void insert(int val,int index=0);
        void remove(int index=0);
        SinglyNode *get_prev(SinglyNode *node);
        SinglyNode *get_node(int index=0);
        void print_list(string separator=" ");
        void reverse_list();
    };
}

#endif //ALGORITHM_LIST_H
