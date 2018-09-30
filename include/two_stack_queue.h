//
// Created by si9ma on 9/30/18.
//

#ifndef ALGORITHM_TWO_STACK_QUEUE_H
#define ALGORITHM_TWO_STACK_QUEUE_H

#include "array_stack.h"

namespace si9ma {
    class TwoStackQueue {
    private:
        ArrayStack *push_stack;
        ArrayStack *pop_stack;
        int size;
        int capacity;
        void transfer();

    public:
        TwoStackQueue();
        explicit TwoStackQueue(int capacity);
        ~TwoStackQueue();

        void push(int val);
        int peek();
        int poll();
    };
}


#endif //ALGORITHM_TWO_STACK_QUEUE_H
