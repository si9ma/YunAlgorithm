//
// Created by si9ma on 9/30/18.
//

#include "array_stack.h"

namespace si9ma{
    ArrayStack::ArrayStack() {

    }

    ArrayStack::ArrayStack(int capacity) {
        stack_array = new int[capacity];
        this->capacity = capacity;
        sp = 0;
    }

    ArrayStack::~ArrayStack() {
        delete [] stack_array;
    }

    void ArrayStack::push(int val) {
        if(sp == capacity)
            throw "stack is full!";

        stack_array[sp++] = val;
    }

    int ArrayStack::peek() {
        if(sp == 0)
            throw "stack is empty!";

        return stack_array[sp -1 ];
    }

    int ArrayStack::pop() {
        if(sp == 0)
            throw "stack is empty!";

        return stack_array[--sp];
    }

    bool ArrayStack::is_empty() {
        return sp == 0;
    }

    bool ArrayStack::is_full() {
        return sp == capacity;
    }
}
