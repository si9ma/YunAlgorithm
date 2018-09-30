//
// Created by si9ma on 9/30/18.
//

#include "new_stack.h"

namespace si9ma{
    NewStack::NewStack(int size) {
        stack = ArrayStack(size);
        min_stack = ArrayStack(size);
    }

    NewStack::~NewStack() {

    }

    void NewStack::push(int val) {
        stack.push(val);

        int min_push_val = !min_stack.is_empty() && min_stack.peek() < val ? min_stack.peek() : val;
        min_stack.push(min_push_val);
    }

    int NewStack::pop() {
        min_stack.pop();

        return stack.pop();
    }

    int NewStack::peek() {
        return stack.peek();
    }

    int NewStack::get_min() {
        return min_stack.peek();
    }
}
