//
// Created by si9ma on 9/30/18.
//

#ifndef ALGORITHM_TWO_QUEUE_STACK_H
#define ALGORITHM_TWO_QUEUE_STACK_H

#include "array_queue.h"

namespace si9ma {
    class TwoQueueStack{
    private:
        ArrayQueue *queue;
        ArrayQueue *help;
        int capacity;
        void swap();

    public:
        TwoQueueStack();
        TwoQueueStack(int capacity);
        ~TwoQueueStack();
        void push(int val);
        int pop();
        int peek();
    };
}


#endif //ALGORITHM_TWO_QUEUE_STACK_H
