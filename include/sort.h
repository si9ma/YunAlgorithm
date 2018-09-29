//
// Created by si9ma on 9/28/18.
//

#ifndef ALGORITHM_SORT_H
#define ALGORITHM_SORT_H

namespace si9ma{
    class sort {

    public:
        sort();
        template <int len> static void bubble_sort(int (&arr)[len]);
        template <int len> static void selection_sort(int (&arr)[len]);
        template <int len> static void insertion_sort(int (&arr)[len]);
        template <int len> static void merge_sort(int (&arr)[len]);
        template <int len> static void quick_sort(int (&arr)[len]);
        template <int len> static void heap_sort(int (&arr)[len]);

        template <int len> static void process_merge_sort(int (&arr)[len], int L, int R);
        template <int len> static void process_quick_sort(int (&arr)[len], int L, int R);
        template <int len> static void merge(int (&arr)[len],int L,int M,int R);

        // use arr[R] as partition value
        template<int len, int len1> static void partition(int (&arr)[len], int (&equal_arr)[len1], int L, int R);

        static void bubble_sort(int * arr,int len);
        static void selection_sort(int * arr,int len);
        static void insertion_sort(int * arr,int len);
        static void merge_sort(int * arr,int len);
        static void quick_sort(int * arr,int len);
        static void heap_sort(int * arr,int len);

        static void process_merge_sort(int *arr, int L, int R);
        static void process_quick_sort(int *arr, int L, int R);
        static void merge(int *arr,int L,int M,int R);

        // use arr[R] as partition value
        static void partition(int *arr, int *equal_arr, int L, int R);
    };
}

#endif //ALGORITHM_SORT_H
