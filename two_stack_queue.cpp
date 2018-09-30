//
// Created by si9ma on 9/30/18.
//

#include "two_stack_queue.h"

namespace si9ma{
    TwoStackQueue::TwoStackQueue() {

    }

    TwoStackQueue::~TwoStackQueue() {
        delete push_stack;
        delete pop_stack;
    }

    TwoStackQueue::TwoStackQueue(int capacity) {
        push_stack = new ArrayStack(capacity);
        pop_stack = new ArrayStack(capacity);
        this->capacity = capacity;
        size = 0;
    }

    void TwoStackQueue::push(int val) {
        if(size == capacity)
            throw "queue is full!";

        push_stack->push(val);
        transfer();
        size ++;
    }

    int TwoStackQueue::peek() {
        if(size == 0)
            throw "queue is empty!";

        transfer();
        return pop_stack->peek();
    }

    int TwoStackQueue::poll() {
        if(size == 0)
            throw "queue is empty!";

        transfer();
        size --;
        return pop_stack->pop();
    }

    void TwoStackQueue::transfer() {
        if(pop_stack->is_empty()){
            while (!push_stack->is_empty())
                pop_stack->push(push_stack->pop());
        }
    }
}
