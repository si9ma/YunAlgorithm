//
// Created by si9ma on 9/30/18.
//

#include <iostream>
#include "array_queue.h"

namespace si9ma{
    ArrayQueue::ArrayQueue() {
    }

    ArrayQueue::ArrayQueue(int capacity) {
        this->capacity = capacity;
        queue_array = new int(8);
        size = head = tail = 0;
    }

    ArrayQueue::~ArrayQueue() {
        delete [] queue_array;
    }

    void ArrayQueue::push(int val) {
        if(size == capacity)
            throw "queue is full!";

        queue_array[tail] = val;
        size ++;
        tail = (tail + 1) % capacity;
    }

    int ArrayQueue::peek() {
        if(size == 0)
            throw "queue is empty!";

        return queue_array[head];
    }

    int ArrayQueue::poll() {
        if(size == 0)
            throw "queue is empty!";

        int res = queue_array[head];
        size --;
        head = (head + 1) % capacity;
        return res;
    }

    bool ArrayQueue::is_empty() {
        return size == 0;
    }

    bool ArrayQueue::is_full() {
        return size == capacity;
    }

    int ArrayQueue::get_size() {
        return size;
    }
}
