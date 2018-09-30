//
// Created by si9ma on 9/30/18.
//

#ifndef ALGORITHM_NEW_STACK_H
#define ALGORITHM_NEW_STACK_H

#include "array_stack.h"

namespace si9ma {
    class NewStack {
        /* a stack with getMin() */
    private:
        ArrayStack stack;
        ArrayStack min_stack;

    public:
        NewStack(int size);
        ~NewStack();

        void push(int val);
        int pop();
        int peek();
        int get_min();
    };
}


#endif //ALGORITHM_NEW_STACK_H
