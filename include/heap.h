//
// Created by si9ma on 9/29/18.
//

#ifndef ALGORITHM_HEAP_H
#define ALGORITHM_HEAP_H

namespace si9ma {
    class Heap {
    public:
        Heap();

        static void heap_insert(int *arr,int index);
        static void heapify(int *arr,int index,int cur_size);
    };
}


#endif //ALGORITHM_HEAP_H
