#include "test.h"
#include <cstring>
#include <iostream>
#include "sort.h"
#include <algorithm>
#include "min_sum.h"
#include "util.h"
#include "nether_lands_flag.h"
#include "max_gap.h"
#include "heap.h"
#include "array_stack.h"
#include "array_queue.h"
#include <string>
#include "new_stack.h"
#include "two_stack_queue.h"
#include "two_queue_stack.h"
#include "matrix.h"
#include "binary_tree.h"
#include "tree_node.h"
#include "singly_linked_list.h"
#include "doubly_linked_list.h"
#include "binary_search.h"

using namespace si9ma;
using namespace std;

extern int arr_len;
extern int *arr, *arr_copy;

bool test_heap(){
    int heap_size = 0;

    // build Heap
    for (int i = 0; i < arr_len; ++i) {
        Heap::heap_insert(arr,i);
    }

    Util::print_array(arr,arr_len," ");
    Util::print_array(arr_copy,arr_len," ");
    cout << endl;

    return true;
}

bool test_max_gap(){
    Util::print_array(arr,arr_len," ");
    std::sort(arr_copy,arr_copy + arr_len);
    Util::print_array(arr_copy,arr_len," ");
    cout << MaxGap::max_gap(arr,arr_len) << "\n" << endl;
    return true;
}

bool test_stack(){
    ArrayStack stack(100);
    try {
        stack.push(100);
        stack.push(50);
        stack.push(30);

        cout << stack.peek() << endl;
        cout << stack.peek() << endl;
        cout << stack.pop() << endl;
        cout << stack.pop() << endl;
        cout << stack.pop() << endl;
        return true;
    }catch (char const* str){
        cout << str << endl;
        return false;
    }
}

bool test_queue(){
    ArrayQueue queue(3);
    try {
        queue.push(100);
        queue.push(30);
        cout << queue.poll() << endl;
        cout << queue.poll() << endl;
        queue.push(50);
        queue.push(80);
        queue.push(80);
        queue.push(80);
        queue.push(80);
        cout << queue.poll() << endl;
        cout << queue.poll() << endl;
        return true;
    }catch (char const* str){
        cout << str << endl;
        return false;
    }
}

bool test_new_stack(){
    try {
        NewStack newStack(100);
        newStack.push(100);
        cout << newStack.get_min() << endl;
        newStack.push(80);
        cout << newStack.get_min() << endl;
        newStack.push(107);
        cout << newStack.get_min() << endl;
        newStack.push(23);
        cout << newStack.get_min() << endl;
        newStack.push(78);
        cout << newStack.get_min() << endl;

        cout << "begin pop" << endl;

        newStack.pop();
        cout << newStack.get_min() << endl;
        newStack.pop();
        cout << newStack.get_min() << endl;
        newStack.pop();
        cout << newStack.get_min() << endl;
        newStack.pop();
        cout << newStack.get_min() << endl;
        newStack.pop();
        cout << newStack.get_min() << endl;
        newStack.pop();
        cout << newStack.get_min() << endl;
        return true;
    }catch (const char* str){
        cout << str << endl;
        return false;
    }
}

bool test_two_stack_queue(){
    TwoStackQueue queue(3);
    try {
        queue.push(100);
        queue.push(30);
        cout << queue.poll() << endl;
        cout << queue.poll() << endl;
        queue.push(50);
        queue.push(80);
        cout << queue.poll() << endl;
        cout << queue.poll() << endl;
        cout << queue.peek() << endl;
        return true;
    }catch (char const* str){
        cout << str << endl;
        return false;
    }
}

bool test_two_queue_stack(){
    TwoQueueStack stack(3);
    try {
        stack.push(100);
        stack.push(50);
        stack.push(30);

        cout << stack.peek() << endl;
        cout << stack.peek() << endl;
        cout << stack.pop() << endl;
        cout << stack.pop() << endl;
        cout << stack.pop() << endl;
        return true;
    }catch (char const* str){
        cout << str << endl;
        return false;
    }
}

bool test_sort(sort_func func){
    /* Sort test */
    // system library Sort
    std::sort(arr,arr + arr_len);

    // tested Sort
    func(arr_copy,arr_len);

    // compare result
    if (!Util::is_equal(arr,arr_copy,arr_len)){
        Util::print_array(arr,arr_len," ");
        Util::print_array(arr_copy,arr_len," ");
        cout << endl;
        return false;
    }
    /* Sort test */

    return true;
}

bool test_matrix(){
    Matrix matrix(10,10,100,true,true);
    matrix.print_matrix();
//    matrix.print_matrix_rotate();
//    matrix.rotate_matrix();
//    matrix.print_matrix();
    matrix.print_matrix_round();

    cout << "---------------------------------"<< endl;

    return true;
}

bool test_singly_linked_list(){
    SinglyNodeWithRand *head1 = nullptr;
    SinglyNodeWithRand *head2 = nullptr;

    try {
        // head1
        SinglyLinkedList::insert(&head1,23);
        SinglyLinkedList::insert(&head1,34);
        SinglyLinkedList::insert(&head1,19);
        SinglyLinkedList::insert(&head1,1);
        SinglyLinkedList::insert(&head1,20);

        head1->next->next->next->next->next = head1->next->next;

        // head2
        SinglyLinkedList::insert(&head2,99);
        SinglyLinkedList::insert(&head2,99);
        SinglyLinkedList::insert(&head2,99);
        SinglyLinkedList::insert(&head2,23);
        SinglyLinkedList::insert(&head2,29);

//        head2->next->next->next->next->next = head2->next->next;

        head2->next->next->next = head1->next->next;

//        /* test code for deep clone*/
//        // bad code ,just for test
//        head->set_rand(head->next->next); // 20 --> 19
//        head->next->set_rand(head->next->next->next); // 1 --> 34
//        head->next->next->next->next->set_rand(head->next); // 23 --> 1
//
//        cout << "\nbefore copy:\n";
//        cout << head->value << "-->" << head->rand->value << endl;
//        cout << head->next->value << "-->" << head->next->rand->value << endl;
//        cout << head->next->next->next->next->value << "-->" << head->next->next->next->next->rand->value << endl;
//
//        auto *head_copy = SinglyLinkedList::deep_clone2(head);
//
//        cout << "\nafter copy:\n";
//        cout << head_copy ->value << "-->" <<  head_copy->rand->value << endl;
//        cout <<  head_copy->next->value << "-->" <<  head_copy->next->rand->value << endl;
//        cout <<  head_copy->next->next->next->next->value << "-->" <<  head_copy->next->next->next->next->rand->value << endl;
//        SinglyLinkedList::delete_list(&head_copy);
//        /* test code for deep clone*/

//        auto *loop_node = SinglyLinkedList::get_loop_node2(head1);
//        cout << (loop_node != nullptr ? loop_node->value : -1) << endl;

        auto *intersection_node = SinglyLinkedList::get_intersection(head1,head2);
        cout << (intersection_node != nullptr ? intersection_node->value : -1) << endl;

        SinglyLinkedList::delete_list(&head1);
        return true;
    }catch (const char * str){
        cout << str << endl;
    }
}

bool test_doubly_linked_list(){
    DoublyLinkedList linkedList;

    try {
        linkedList.insert(8);
        linkedList.print_list();
        linkedList.insert(9);
        linkedList.print_list();
        linkedList.insert(10);
        linkedList.print_list();
        linkedList.push_back(11);
        linkedList.print_list();
        linkedList.insert(12,1);
        linkedList.print_list();
        linkedList.reverse_list();
        linkedList.print_list();
        linkedList.print_list_reverse();

        return true;
    }catch (const char * str){
        cout << str << endl;
    }
}

bool test_binary_search(){
    int arr[] = {30,3,4,7,8,9,23,34,56,78};

    cout << BinarySearch::find_local_min(arr,0, sizeof(arr)/ sizeof(arr[0]) - 1) << endl;
}

bool test_binary_tree(){
    auto *head = new TreeNode(10);
    head->right = new TreeNode(30);
    head->right->left = new TreeNode(32);
    head->right->right = new TreeNode(44);

    BinaryTree::print_tree(head);
    cout << "\npre_order:" << endl;
    BinaryTree::recursive_pre_order(head);
    cout << "\nin_order:" << endl;
    BinaryTree::recursive_in_order(head);
    cout << "\npos_order:" << endl;
    BinaryTree::recursive_pos_order(head);

    cout << endl;
    cout << "\npre_order:" << endl;
    BinaryTree::iterative_pre_order(head);
    cout << "\nin_order:" << endl;
    BinaryTree::iterative_in_order(head);
    cout << "\npos_order:" << endl;
    BinaryTree::iterative_pos_order(head);

    cout << "\nis balance tree:" << boolalpha << BinaryTree::is_balance_tree(head).is_balance << endl;

    cout << endl;
    BinaryTree::destroy_tree(head);
    return true;
}
