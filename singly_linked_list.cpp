//
// Created by si9ma on 10/1/18.
//

#include <clocale>
#include <iostream>
#include "singly_linked_list.h"
#include <stack>
#include <unordered_map>
#include <bits/unordered_set.h>
#include "nether_lands_flag.h"

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
        auto *new_node = new SinglyNodeWithRand(val);

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

    SinglyNodeWithRand* SinglyLinkedList::get_prev(SinglyNodeWithRand *node) {
        if (size == 0)
            throw "linked list is empty";

        if (node == head)
            return nullptr;

        SinglyNodeWithRand *prev = head;
        while (prev->next != node && prev != tail)
            prev = prev->next;

        if (prev == tail)
            throw "can not found prev";

        return prev;
    }

    SinglyNodeWithRand* SinglyLinkedList::get_node(int index) {
        if(index < 0 || index >= size)
            throw "range overflow";

        auto *node = head;
        int tmp_idx = 0;
        while (tmp_idx++ < index)
            node = node->next;

        return node;
    }

    void SinglyLinkedList::print_list(string separator) {
        SinglyNodeWithRand *ptr = head;
        while (ptr != nullptr){
            std::cout << ptr->value << separator;
            ptr = ptr->next;
        }

        std::cout << std::endl;
    }

    void SinglyLinkedList::insert(int val, int index) {
        auto *new_node = new SinglyNodeWithRand(val);

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
            SinglyNodeWithRand *prev = get_prev(old_node);
            prev->next = new_node;
            new_node->next = old_node;
        }

        size++;
    }

    void SinglyLinkedList::reverse_list() {
        if (size < 2)
            return;

        SinglyNodeWithRand *prev = head;
        SinglyNodeWithRand *cur = head->next;
        SinglyNodeWithRand *next = head->next->next;

        while (cur){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        head->next = nullptr;
        SinglyNodeWithRand *ptr = head;
        head = tail;
        tail = head;
    }

    void SinglyLinkedList::print_list(SinglyNodeWithRand *head,string separator) {
        while (head != nullptr){
            std::cout << head->value << separator;
            head = head->next;
        }

        std::cout << std::endl;
    }

    void SinglyLinkedList::reverse_list(SinglyNodeWithRand **head) {
        if (*head == nullptr)
            return;

        SinglyNodeWithRand *prev = *head;
        SinglyNodeWithRand *cur = (*head)->next;
        SinglyNodeWithRand *next = nullptr;

        while (cur){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        (*head)->next = nullptr;
        *head = prev;
    }

    void SinglyLinkedList::insert(SinglyNodeWithRand **head, int val, int index) {
        if (index < 0)
            throw "out of range";

        auto *new_node = new SinglyNodeWithRand(val);

        if (index == 0){
            new_node->next = *head;
            *head = new_node;
            return;
        }

        auto *old_node = *head;
        SinglyNodeWithRand *pre_node = nullptr ;
        int tmp_idx = 0;
        while (tmp_idx++ < index && old_node != nullptr){
            pre_node = old_node;
            old_node = old_node->next;
        }

        if (old_node == nullptr){
            delete new_node;
            throw "out of range";
        }

        pre_node->next = new_node;
        new_node->next = old_node;
    }

    void SinglyLinkedList::remove(SinglyNodeWithRand **head, int index) {
        if (index < 0)
            throw "out of range";

        auto *del_node = *head;
        if (index == 0){
            *head = (*head)->next;
            delete del_node;
            return;
        }

        SinglyNodeWithRand *pre_node = nullptr;
        int tmp_idx = 0;
        while (tmp_idx++ < index && del_node != nullptr){
            pre_node = del_node;
            del_node = del_node->next;
        }

        if (del_node == nullptr)
            throw "out of range";

        pre_node->next = del_node->next;
        delete del_node;
    }

    void SinglyLinkedList::delete_list(SinglyNodeWithRand **head) {
        auto *ptr = *head;
        while (ptr != nullptr){
            *head = ptr->next;
            delete ptr;
            ptr = *head;
        }
    }

    bool SinglyLinkedList::is_palindroom1(SinglyNodeWithRand *head) {

        // when list is empty or just one element,true
        if (head == nullptr || head->next == nullptr)
            return true;

        auto *slow_ptr = head;
        auto *quick_ptr = head;
        while (quick_ptr->next != nullptr && quick_ptr->next->next != nullptr){
            quick_ptr = quick_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }

        auto *head2 = slow_ptr->next;
        slow_ptr->next = nullptr;

        // reverse right side list
        reverse_list(&head2);
        auto *head1_ptr =head;
        auto *head2_ptr =head2;

        bool res = true;
        while (head1_ptr != nullptr && head2_ptr != nullptr){
            if (head1_ptr->value != head2_ptr->value){
                res = false;
                break;
            }

            head1_ptr = head1_ptr->next;
            head2_ptr = head2_ptr->next;
        }

        // restore
        reverse_list(&head2);
        slow_ptr->next = head2;

        return res;
    }

    bool SinglyLinkedList::is_palindroom2(si9ma::SinglyNodeWithRand *head) {
        auto *ptr = head;
        stack<int> s_stack;
        while (ptr != nullptr){
            s_stack.push(ptr->value);
            ptr = ptr->next;
        }

        ptr = head;
        while (ptr != nullptr){
            if (ptr->value != s_stack.top())
                return false;

            ptr = ptr->next;
            s_stack.pop();
        }

        return true;
    }

    bool SinglyLinkedList::is_palindroom3(si9ma::SinglyNodeWithRand *head) {
        // when list is empty or just one element,true
        if (head == nullptr || head->next == nullptr)
            return true;

        auto *slow_ptr = head;
        auto *quick_ptr = head;
        while (quick_ptr->next != nullptr && quick_ptr->next->next != nullptr){
            quick_ptr = quick_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }

        auto *ptr = slow_ptr->next;
        stack<int> s_stack;
        while (ptr != nullptr){
            s_stack.push(ptr->value);
            ptr = ptr->next;
        }

        ptr = head;
        while (ptr != slow_ptr->next && !s_stack.empty()){
            if (ptr->value != s_stack.top())
                return false;
            ptr = ptr->next;
            s_stack.pop();
        }

        return true;
    }

    void SinglyLinkedList::partition_list1(SinglyNodeWithRand *head,int p) {
        int tmp_arr[256];
        int tmp_idx = 0;
        auto *ptr = head;

        while (ptr != nullptr){
            tmp_arr[tmp_idx++] = ptr->value;
            ptr = ptr->next;
        }

        int equal_arr[2];
        NetherLandsFlag::partition(tmp_arr,equal_arr,0,tmp_idx - 1,p);

        ptr = head;
        tmp_idx = 0;
        while (ptr != nullptr){
            ptr->value = tmp_arr[tmp_idx++];
            ptr = ptr->next;
        }
    }

    void SinglyLinkedList::partition_list2(si9ma::SinglyNodeWithRand **head, int p) {
        SinglyNodeWithRand *less_start,*less_end,*equal_start,*equal_end,*more_start,*more_end;
        less_start = less_end = equal_start = equal_end = more_start = more_end = nullptr;

        auto *ptr = *head;
        while (ptr != nullptr){
            if (ptr->value < p){
                if (less_start == nullptr){
                    less_start = less_end = ptr;
                } else{
                    less_end->next = ptr;
                    less_end = ptr;
                }
            } else if(ptr->value == p){
                if (equal_start == nullptr){
                    equal_start = equal_end = ptr;
                } else{
                    equal_end->next = ptr;
                    equal_end = ptr;
                }
            } else{
                if (more_start == nullptr){
                    more_start = more_end = ptr;
                } else{
                    more_end->next = ptr;
                    more_end = ptr;
                }
            }

             ptr = ptr->next;
        }

        if (less_end != nullptr){
            less_end->next = equal_start;
            equal_end = equal_end == nullptr ? less_end : equal_end;
        }

        if (equal_end != nullptr){
            equal_end->next = more_start;
        }

        more_end->next = nullptr;

        *head = less_start != nullptr ? less_start : (equal_start != nullptr ? equal_start : more_start);
    }

    // TODO unordered_map insert custom element
    SinglyNodeWithRand * SinglyLinkedList::deep_clone1(si9ma::SinglyNodeWithRand *head) {
//        std::unordered_map<SinglyNodeWithRand *,SinglyNodeWithRand *> map;
//        auto *ptr = head;
//
//        while (ptr != nullptr){
//            map.insert(ptr,new SinglyNodeWithRand(ptr->value));
//            ptr = ptr->next;
//        }
//
//        ptr = head;
//        while (ptr != nullptr){
//            map.at(ptr)->next = map.at(ptr->next);
//            map.at(ptr)->rand = map.at(ptr->rand);
//            ptr = ptr->next;
//        }
//
//        return map.at(head);
    }

    SinglyNodeWithRand* SinglyLinkedList::deep_clone2(si9ma::SinglyNodeWithRand *head) {
        auto *ptr = head;
        SinglyNodeWithRand *new_node;

        while (ptr != nullptr){
            new_node = new SinglyNodeWithRand(ptr->value);
            new_node->next = ptr->next;
            ptr->next = new_node;
            ptr = ptr->next->next;
        }

        ptr = head;
        SinglyNodeWithRand *copy_node;
        while (ptr != nullptr){
            copy_node = ptr->next;
            copy_node->rand = ptr->rand != nullptr ? ptr->rand->next : nullptr;

            ptr = ptr->next->next;
        }

        ptr = head;
        SinglyNodeWithRand *new_head = head->next;

        while (ptr != nullptr){
            copy_node = ptr->next;
            ptr->next = ptr->next->next;
            copy_node->next = copy_node->next != nullptr ? copy_node->next->next : nullptr;

            ptr = ptr->next;
        }

        return new_head;

    }

    // TODO how to use unorder_set
    // use set
    SinglyNodeWithRand* SinglyLinkedList::get_loop_node1(si9ma::SinglyNodeWithRand *head) {
//        unordered_set<SinglyNodeWithRand> set;
//        auto *ptr = head;
//
//        while (ptr != nullptr){
//            if (set.find(*ptr) != set.end())
//                return ptr;
//
//            set.insert(*ptr);
//            ptr = ptr->next;
//        }
//
//        return nullptr;
    }

    SinglyNodeWithRand* SinglyLinkedList::get_loop_node2(SinglyNodeWithRand *head) {

        bool is_loop = false;
        auto *slow = head;
        auto *fast = head;

        while ( fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;

            if (fast == slow){
                is_loop = true;
                break;
            }
        }

        if (!is_loop)
            return nullptr;

        fast = head;
        while (fast != slow){
            fast = fast->next;
            slow = slow->next;
        }

        return slow;
    }

    SinglyNodeWithRand* SinglyLinkedList::get_intersection(SinglyNodeWithRand *head1,SinglyNodeWithRand *head2) {
        auto *loop1 = get_loop_node2(head1);
        auto *loop2 = get_loop_node2(head2);

        // two single list
        if (loop1 == nullptr && loop2 == nullptr)
            return common_loop_intersection(head1,head2, nullptr);
        else if(loop1 != nullptr && loop2 != nullptr)
            return both_loop_intersection(head1,head2);
        else
            return nullptr;
    }

    SinglyNodeWithRand* SinglyLinkedList::common_loop_intersection(si9ma::SinglyNodeWithRand *head1, si9ma::SinglyNodeWithRand *head2, si9ma::SinglyNodeWithRand *list_terminal) {
        int len = 0;

        auto *ptr = head1;
        while (ptr != list_terminal){
            len ++;
            ptr = ptr->next;
        }

        ptr = head2;
        while (ptr != list_terminal){
            len --;
            ptr = ptr->next;
        }

        auto *long_list = len > 0 ? head1 : head2;
        auto *short_list = len > 0 ? head2 : head1;
        int diff = abs(len);

        while (diff-- > 0)
            long_list = long_list->next;

        while (long_list != short_list){
            long_list = long_list->next;
            short_list = short_list->next;
        }

        return long_list;
    }

    SinglyNodeWithRand* SinglyLinkedList::both_loop_intersection(si9ma::SinglyNodeWithRand *head1, si9ma::SinglyNodeWithRand *head2) {
        auto *loop1 = get_loop_node2(head1);
        auto *loop2 = get_loop_node2(head2);

        if (loop1 == loop2)
            return common_loop_intersection(head1,head2,loop1->next);

        auto *ptr = loop1->next;
        while (ptr != loop1){
            if (ptr == loop2)
                return loop1;
            ptr = ptr->next;
        }

        return nullptr;
    }
}
