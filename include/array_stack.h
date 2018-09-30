//
// Created by si9ma on 9/30/18.
//

#ifndef ALGORITHM_ARRAYSTACK_H
#define ALGORITHM_ARRAYSTACK_H


namespace si9ma {
    class ArrayStack {
    private:
        int *stack_array;
        int capacity;
        int sp; // stack pointer

    public:
        ArrayStack();
        ArrayStack(int capacity);
        ~ArrayStack();

        void push(int val);
        int pop();
        int peek();
        bool is_empty();
        bool is_full();
    };
}


#endif //ALGORITHM_ARRAYSTACK_H
