//
// Created by si9ma on 9/28/18.
//

#include <heap.h>
#include "sort.h"
#include "util.h"

namespace si9ma{
    sort::sort() {

    }

    // bubble sort
    template <int len>
    void sort::bubble_sort(int (&arr)[len])
    {
        if(len < 2)
            return;

        for(int end = len - 1;end > 0;end --){
            for(int i = 0;i < end;i++)
            {
                if(arr[i] > arr[i + 1])
                    util::swap(arr,i,i+1);
            }
        }
    }

    // selection sort
    template <int len>
    void sort::selection_sort(int (&arr)[len])
    {
        if(len < 2)
            return;

        int min_idx;
        for(int i = 0;i < len - 1;i++) // 1 ~ n-1
        {
            min_idx = i;
            for(int j = i + 1;j < len ;j++)  // i + 1 ~ n
                min_idx = arr[j] < arr[min_idx] ? j : min_idx;

            util::swap(arr,i,min_idx);
        }
    }

    // insertion sort
    template <int len>
    void sort::insertion_sort(int (&arr)[len])
    {
        if(len < 2)
            return;

        for(int i = 1; i < len;i++) // 0 ~ i will be sorted
        {
            for(int j = i - 1;j >=0 && arr[j] > arr[j + 1]; j --)
                util::swap(arr,j,j+1);
        }
    }

    // bubble sort
    void sort::bubble_sort(int *arr,int len)
    {
        if(len < 2)
            return;

        for(int end = len - 1;end > 0;end --){
            for(int i = 0;i < end;i++)
            {
                if(arr[i] > arr[i + 1])
                    util::swap(arr,i,i+1);
            }
        }
    }

    // selection sort
    void sort::selection_sort(int *arr,int len)
    {
        if(len < 2)
            return;

        int min_idx;
        for(int i = 0;i < len - 1;i++) // 1 ~ n-1
        {
            min_idx = i;
            for(int j = i + 1;j < len ;j++)  // i + 1 ~ n
                min_idx = arr[j] < arr[min_idx] ? j : min_idx;

            util::swap(arr,i,min_idx);
        }
    }

    // insertion sort
    void sort::insertion_sort(int *arr,int len)
    {
        if(len < 2)
            return;

        for(int i = 1; i < len;i++) // 0 ~ i will be sorted
        {
            for(int j = i - 1;j >=0 && arr[j] > arr[j + 1]; j --)
                util::swap(arr,j,j+1);
        }
    }

    template <int len>
    void sort::merge_sort(int (&arr)[len]) {
        process_merge_sort(arr, 0, len - 1);
    }

    void sort::merge_sort(int *arr, int len) {
        process_merge_sort(arr, 0, len - 1);
    }

    // 时间复杂度 --> T(N)
    template <int len>
    void sort::process_merge_sort(int (&arr)[len], int L, int R) {
        if (L == R)
            return;

        int M = ( L + R ) / 2;
        process_merge_sort(arr, L, M); // 复杂度 -->T(N/2)
        process_merge_sort(arr, M + 1, R); // 复杂度 -->T(N/2)
        merge(arr,L,M,R); // 复杂度 -->T(N)
    }

    void sort::process_merge_sort(int *arr, int L, int R) {
        if (L == R)
            return;

        int M = ( L + R ) / 2;
        process_merge_sort(arr, L, M); // 复杂度 -->T(N/2)
        process_merge_sort(arr, M + 1, R); // 复杂度 -->T(N/2)
        merge(arr,L,M,R); // 复杂度 -->T(N)
    }

    template <int len>
    void sort::merge(int (&arr)[len], int L, int M, int R) {
        int left_ptr = L,right_ptr = M + 1,tmp_ptr = 0,tmp_arr_len = R - L + 1;
        int tmp_arr[tmp_arr_len];

        while (left_ptr <= M && right_ptr <= R)
            tmp_arr[tmp_ptr++] = arr[left_ptr] < arr[right_ptr] ? arr[left_ptr ++] : arr[right_ptr++];

        while (left_ptr <= M)
            tmp_arr[tmp_ptr ++] = arr[left_ptr++];

        while (right_ptr <= M)
            tmp_arr[tmp_ptr++] = arr[right_ptr++];

        for (int i = 0; i < tmp_arr_len; ++i) {
            arr[L + i] = tmp_arr[i];
        }
    }

    void sort::merge(int *arr, int L, int M, int R) {
        int left_ptr = L,right_ptr = M + 1,tmp_ptr = 0,tmp_arr_len = R - L + 1;
        int tmp_arr[tmp_arr_len];

        while (left_ptr <= M && right_ptr <= R)
            tmp_arr[tmp_ptr++] = arr[left_ptr] < arr[right_ptr] ? arr[left_ptr ++] : arr[right_ptr++];

        while (left_ptr <= M)
            tmp_arr[tmp_ptr ++] = arr[left_ptr++];

        while (right_ptr <= R)
            tmp_arr[tmp_ptr++] = arr[right_ptr++];

        for (int i = 0; i < tmp_arr_len; ++i) {
            arr[L + i] = tmp_arr[i];
        }
    }

    // use arr[R] as partition value
    void sort::partition(int *arr, int *equal_arr, int L, int R) {
        int less = L - 1;
        int more = R;
        int index = L;

        while (index < more){
            if(arr[index] < arr[R])
                util::swap(arr,++less,index ++);
            else if(arr[index] > arr[R])
                util::swap(arr,--more,index);
            else
                index++;
        }
        util::swap(arr,more,R);

        equal_arr[0] = less + 1;
        equal_arr[1] = more;
    }

    // use arr[R] as partition value
    template <int len,int len1>
    void sort::partition(int (&arr)[len], int (&equal_arr)[len1], int L, int R){
        int less = L - 1;
        int more = R;
        int index = L;

        while (index < R){
            if(arr[index] < arr[R])
                util::swap(arr,++less,index ++);
            else if(arr[index] > arr[R])
                util::swap(arr,--more,index);
            else
                index++;
        }
        util::swap(arr,more,R);

        equal_arr[0] = less + 1;
        equal_arr[1] = more;
    }

    template <int len>
    void sort::process_quick_sort(int (&arr)[len], int L, int R) {
        if (L < R){
            srand(time(0));
            int equal_arr[2];
            util::swap(arr,L + rand() % (R - L + 1),R); // random partition value

            partition(arr,equal_arr,L,R);
            process_quick_sort(arr,L,equal_arr[0] - 1);
            process_quick_sort(arr,equal_arr[1] + 1,R);
        }
    }

    void sort::process_quick_sort(int *arr, int L, int R) {
        if (L < R){
            srand(time(0));
            int equal_arr[2];
            util::swap(arr,L + rand() % (R - L + 1),R); // random partition value

            partition(arr,equal_arr,L,R);
            process_quick_sort(arr,L,equal_arr[0] - 1);
            process_quick_sort(arr,equal_arr[1] + 1,R);
        }
    }

    template <int len>
    void sort::quick_sort(int (&arr)[len]) {
        process_quick_sort(arr,0,len - 1);
    }

    void sort::quick_sort(int *arr, int len) {
        process_quick_sort(arr,0,len - 1);
    }

    template <int len>
    void sort::heap_sort(int (&arr)[len]) {
        if (len < 2)
            return;

        // build heap
        for (int i = 0; i < len; ++i) {
            heap::heap_insert(arr,i);
        }
        int heap_size = len;

        util::swap(arr,0,--heap_size);
        while (heap_size > 0){
            heap::heapify(arr,0,heap_size);
            util::swap(arr,0,--heap_size);
        }
    }

    void sort::heap_sort(int *arr, int len) {
        if (len < 2)
            return;

        // build heap
        for (int i = (len - 2) / 2; i >= 0 ; --i) {
            heap::heapify(arr,i,len);
        }
        int heap_size = len;

        util::swap(arr,0,--heap_size);
        while (heap_size > 0){
            heap::heapify(arr,0,heap_size);
            util::swap(arr,0,--heap_size);
        }
    }
}
