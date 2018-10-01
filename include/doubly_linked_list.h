//
// Created by si9ma on 10/2/18.
//

#ifndef ALGORITHM_DOUBLY_LINKED_LIST_H
#define ALGORITHM_DOUBLY_LINKED_LIST_H

#include <string>
#include "doubly_node.h"

namespace si9ma {
    class DoublyLinkedList {
    private:
        int size;
        DoublyNode *head;
        DoublyNode *tail;

    public:
        DoublyLinkedList();
        ~DoublyLinkedList();

        bool is_empty();
        void push_back(int val);
        void insert(int val,int index=0);
        void remove(int index = 0);
        void reverse_list();
        void print_list(std::string separator=" ");
        void print_list_reverse(std::string separator=" ");
        DoublyNode *get_node(int index=0);
    };
}


#endif //ALGORITHM_DOUBLY_LINKED_LIST_H
