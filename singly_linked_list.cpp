//
// Created by si9ma on 10/1/18.
//

#include <clocale>
#include <iostream>
#include "singly_linked_list.h"

using namespace std;

namespace si9ma{
    SinglyLinkedList::SinglyLinkedList() {
        size = 0;
        head = tail = nullptr;
    }

    SinglyLinkedList::~SinglyLinkedList() {
        while (!is_empty())
            remove();
    }

    bool SinglyLinkedList::is_empty() {
        return size == 0;
    }

    void SinglyLinkedList::push_back(int val) {
        auto *new_node = new SinglyNode(val);

        // when linked list is empty
        if(is_empty())
            head = tail = new_node;
        else{
            tail->next = new_node;
            tail = new_node;
        }

        size++;
    }

    void SinglyLinkedList::remove(int index) {
        auto *del_node = get_node(index);
        if(size == 1) {
            head = tail = nullptr;
            delete del_node;
            size--;
            return;
        }

        if(del_node == head)
            head = head->next;
        else if(del_node == tail){
            tail = get_prev(tail);
            tail->next = nullptr;
        } else{
            auto *prev = get_prev(del_node);
            prev->next = del_node->next;
        }

        delete del_node;
        size--;
    }

    SinglyNode* SinglyLinkedList::get_prev(SinglyNode *node) {
        if (size == 0)
            throw "linked list is empty";

        if (node == head)
            return nullptr;

        SinglyNode *prev = head;
        while (prev->next != node && prev != tail)
            prev = prev->next;

        if (prev == tail)
            throw "can not found prev";

        return prev;
    }

    SinglyNode* SinglyLinkedList::get_node(int index) {
        if(index < 0 || index >= size)
            throw "range overflow";

        auto *node = head;
        int tmp_idx = 0;
        while (tmp_idx++ < index)
            node = node->next;

        return node;
    }

    void SinglyLinkedList::print_list(string separator) {
        SinglyNode *ptr = head;
        while (ptr != nullptr){
            std::cout << ptr->value << separator;
            ptr = ptr->next;
        }

        std::cout << std::endl;
    }

    void SinglyLinkedList::insert(int val, int index) {
        auto *new_node = new SinglyNode(val);

        if (is_empty()){
            head = tail = new_node;
            size++;
            return;
        }

        auto *old_node = get_node(index);
        if (old_node == head){
            head = new_node;
            new_node->next = old_node;
        } else{
            SinglyNode *prev = get_prev(old_node);
            prev->next = new_node;
            new_node->next = old_node;
        }

        size++;
    }

    void SinglyLinkedList::reverse_list() {
        if (size < 2)
            return;

        SinglyNode *prev = head;
        SinglyNode *cur = head->next;
        SinglyNode *next = head->next->next;

        while (cur){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        head->next = nullptr;
        SinglyNode *ptr = head;
        head = tail;
        tail = head;
    }
}
