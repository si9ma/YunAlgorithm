//
// Created by si9ma on 10/2/18.
//

#include "doubly_linked_list.h"
#include <iostream>

using namespace std;

namespace si9ma{
    DoublyLinkedList::DoublyLinkedList() {
        size = 0;
        head = tail = nullptr;
    }

    DoublyLinkedList::~DoublyLinkedList() {
        while (!is_empty())
            remove();
    }

    bool DoublyLinkedList::is_empty() {
        return size == 0;
    }

    void DoublyLinkedList::print_list(string separator) {
        auto *ptr = head;
        while (ptr != nullptr){
            std::cout << ptr->value << separator;
            ptr = ptr->next;
        }

        cout << endl;
    }

    void DoublyLinkedList::push_back(int val) {
        auto *new_node = new DoublyNode(val);
        if (is_empty()){
            head = tail = new_node;
            new_node->next = new_node->prev = nullptr;
        } else{
            new_node->prev = tail;
            new_node->next = nullptr;
            tail->next = new_node;
            tail = new_node;
        }

        size ++;
    }

    void DoublyLinkedList::print_list_reverse(std::string separator) {
        auto *ptr = tail;
        while (ptr != nullptr){
            std::cout << ptr->value << separator;
            ptr = ptr->prev;
        }

        cout << endl;
    }

    void DoublyLinkedList::insert(int val, int index) {
        auto *new_node = new DoublyNode(val);

        if (is_empty()){
            head = tail = new_node;
            new_node->next = new_node->prev = nullptr;
            size ++;
            return;
        }

        auto *old_node = get_node(index);
        if (old_node == head){
            new_node->next = head;
            new_node->prev = nullptr;
            head->prev = new_node;
            head = new_node;
        } else{
            new_node->next = old_node;
            new_node->prev = old_node->prev;
            old_node->prev->next = new_node;
            old_node->prev = new_node;
        }

        size++;
    }

    DoublyNode* DoublyLinkedList::get_node(int index) {
        if (index < 0 || index >= size)
            throw "range overflow";

        auto *ptr = head;
        int tmp_idx = 0;
        while (tmp_idx++ < index)
            ptr = ptr->next;

        return ptr;
    }

    void DoublyLinkedList::reverse_list() {
        auto *cur = head;
        auto *next = head->next;
        DoublyNode *tmp;

        while (cur){
            next = cur->next;
            tmp = cur->next;
            cur->next = cur->prev;
            cur->prev = tmp;
            cur = next;
        }

        tmp = head;
        head = tail;
        tail = tmp;
    }

    void DoublyLinkedList::remove(int index) {
        auto *del_node = get_node(index);
        if (size == 1){
            head = tail = nullptr;
            size--;
            delete del_node;
            return;
        }

        if (del_node == head){
            head = del_node->next;
            head->prev = nullptr;
        } else if(del_node == tail){
            tail = del_node->prev;
            tail->next = nullptr;
        } else{
            del_node->prev->next = del_node->next;
            del_node->next->prev = del_node->prev;
        }

        delete del_node;
        size--;
    }
}
