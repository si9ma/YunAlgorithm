//
// Created by si9ma on 9/29/18.
//

#include "util.h"
#include "heap.h"

namespace si9ma{
    Heap::Heap() {

    }

    void Heap::heap_insert(int *arr, int index) {
        while (arr[index] > arr[(index - 1) / 2]){
            Util::swap(arr,index,(index - 1)/2);
            index = (index - 1) / 2;
        }
    }

    void Heap::heapify(int *arr, int index, int cur_size) {
        int L = index * 2 + 1;  // left child
        while (L < cur_size){ // no overflow
            int largest = L + 1 < cur_size && arr[L + 1] > arr[L] ? L + 1: L; // if have right child and right > left
            largest = arr[largest] > arr[index] ? largest : index;

            if (largest == index){ // stop
                break;
            }
            Util::swap(arr,largest,index);

            index = largest;
            L = 2 * index + 1;
        }
    }
}
