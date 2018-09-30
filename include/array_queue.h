//
// Created by si9ma on 9/30/18.
//

#ifndef ALGORITHM_ARRAY_QUEUE_H
#define ALGORITHM_ARRAY_QUEUE_H


namespace si9ma {
    class ArrayQueue {
    private:
        int capacity;
        int size;
        int *queue_array;
        int head;
        int tail;

    public:
        ArrayQueue();
        ArrayQueue(int capacity);
        ~ArrayQueue();

        void push(int val);
        int poll();
        int peek();
        bool is_empty();
        bool is_full();
        int get_size();
    };
}


#endif //ALGORITHM_ARRAY_QUEUE_H
