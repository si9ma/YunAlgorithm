//
// Created by si9ma on 9/30/18.
//

#include "two_queue_stack.h"

namespace si9ma{
    TwoQueueStack::TwoQueueStack() {

    }

    TwoQueueStack::TwoQueueStack(int capacity) {
        queue = new ArrayQueue(capacity + 1);
        help = new ArrayQueue(capacity);
    }

    TwoQueueStack::~TwoQueueStack() {

    }

    void TwoQueueStack::push(int val) {
        if(queue->is_full())
            throw "stack is full";

        queue->push(val);
    }

    int TwoQueueStack::peek() {
        if(queue->is_empty())
            throw "stack is empty";

        while (queue->get_size() > 1)
            help->push(queue->poll());

        int res = queue->peek();
        help->push(queue->poll());
        swap();
        return res;
    }

    int TwoQueueStack::pop() {
        if(queue->is_empty())
            throw "stack is empty";

        while (queue->get_size() > 1)
            help->push(queue->poll());

        int res = queue->poll();
        swap();
        return res;
    }

    void TwoQueueStack::swap() {
        ArrayQueue *tmp_queue = queue;
        queue = help;
        help = tmp_queue;
    }
}
