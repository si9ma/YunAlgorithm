//
// Created by si9ma on 9/28/18.
//

#include <algorithm>
#include <climits>
#include <cstring>
#include "util.h"
#include "sort.h"
#include "heap.h"
#include <vector>

using namespace std;

namespace si9ma{
    Sort::Sort() {

    }

    // bubble Sort
    void Sort::bubble_sort(int *arr,int len)
    {
        if(len < 2)
            return;

        for(int end = len - 1;end > 0;end --){
            for(int i = 0;i < end;i++)
            {
                if(arr[i] > arr[i + 1])
                    Util::swap(arr,i,i+1);
            }
        }
    }

    // selection Sort
    void Sort::selection_sort(int *arr,int len)
    {
        if(len < 2)
            return;

        int min_idx;
        for(int i = 0;i < len - 1;i++) // 1 ~ n-1
        {
            min_idx = i;
            for(int j = i + 1;j < len ;j++)  // i + 1 ~ n
                min_idx = arr[j] < arr[min_idx] ? j : min_idx;

            Util::swap(arr,i,min_idx);
        }
    }

    // insertion Sort
    void Sort::insertion_sort(int *arr,int len)
    {
        if(len < 2)
            return;

        for(int i = 1; i < len;i++) // 0 ~ i will be sorted
        {
            for(int j = i - 1;j >=0 && arr[j] > arr[j + 1]; j --)
                Util::swap(arr,j,j+1);
        }
    }

    void Sort::merge_sort(int *arr, int len) {
        process_merge_sort(arr, 0, len - 1);
    }

    void Sort::process_merge_sort(int *arr, int L, int R) {
        if (L == R)
            return;

        int M = ( L + R ) / 2;
        process_merge_sort(arr, L, M); // 复杂度 -->T(N/2)
        process_merge_sort(arr, M + 1, R); // 复杂度 -->T(N/2)
        merge(arr,L,M,R); // 复杂度 -->T(N)
    }

    void Sort::merge(int *arr, int L, int M, int R) {
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
    void Sort::partition(int *arr, int *equal_arr, int L, int R) {
        int less = L - 1;
        int more = R;
        int index = L;

        while (index < more){
            if(arr[index] < arr[R])
                Util::swap(arr,++less,index ++);
            else if(arr[index] > arr[R])
                Util::swap(arr,--more,index);
            else
                index++;
        }
        Util::swap(arr,more,R);

        equal_arr[0] = less + 1;
        equal_arr[1] = more;
    }

    void Sort::process_quick_sort(int *arr, int L, int R) {
        if (L < R){
            srand(time(0));
            int equal_arr[2];
            Util::swap(arr,L + rand() % (R - L + 1),R); // random partition value

            partition(arr,equal_arr,L,R);
            process_quick_sort(arr,L,equal_arr[0] - 1);
            process_quick_sort(arr,equal_arr[1] + 1,R);
        }
    }

    void Sort::quick_sort(int *arr, int len) {
        process_quick_sort(arr,0,len - 1);
    }

    void Sort::heap_sort(int *arr, int len) {
        if (len < 2)
            return;

        // build Heap
        for (int i = (len - 2) / 2; i >= 0 ; --i) {
            Heap::heapify(arr,i,len);
        }
        int heap_size = len;

        Util::swap(arr,0,--heap_size);
        while (heap_size > 0){
            Heap::heapify(arr,0,heap_size);
            Util::swap(arr,0,--heap_size);
        }
    }

    void Sort::shell_sort(int *arr, int len) {
        for (int gap = len/2; gap > 0; gap/=2) {
            for (int i = gap; i < len; ++i) {
                for (int j = i - gap; j >= 0 && arr[j] > arr[j + gap]; j -= gap) {
                    Util::swap(arr,j,j+gap);
                }
            }
        }
    }

    void Sort::count_sort1(int *arr, int len) {
        int max = INT_MIN;
        int min = INT_MAX;
        for (int i = 0; i < len; ++i) {
            max = arr[i] > max ? arr[i] : max;
            min = arr[i] < min ? arr[i] : min;
        }

        int range = max - min + 1;
        int count[range];
        int output[len];

        memset(count,0, sizeof(count));

        // calculate element frequency
        for (int j = 0; j < len; ++j) {
            count[arr[j] - min] ++;
        }

        // calculate element offset
        for (int k = 1; k < range; ++k) {
            count[k] += count[k - 1];
        }

        // build output array
        for (int l = 0; l < len; ++l) {
            output[count[arr[l] - min] - 1] = arr[l];
            count[arr[l] - min] --;
        }

        // copy to src array
        for (int m = 0; m < len; ++m) {
            arr[m] = output[m];
        }
    }

    void Sort::count_sort2(int *arr, int len) {
        int max = INT_MIN;
        int min = INT_MAX;
        for (int i = 0; i < len; ++i) {
            max = arr[i] > max ? arr[i] : max;
            min = arr[i] < min ? arr[i] : min;
        }

        int range = max - min + 1;
        int count[range];
        int output[len];

        memset(count,0, sizeof(count));

        // calculate element frequency
        for (int j = 0; j < len; ++j) {
            count[arr[j] - min] ++;
        }

        // build output array
        int output_idx = 0;
        for (int k = 0; k < range; ++k) {
            for (int i = count[k]; i > 0 ; --i) {
                output[output_idx++] = min + k;
            }
        }

        // copy to src array
        for (int m = 0; m < len; ++m) {
            arr[m] = output[m];
        }
    }

    void Sort::bucket_sort(int *arr, int len) {
        int max = INT_MIN;
        int min = INT_MAX;
        for (int i = 0; i < len; ++i) {
            max = arr[i] > max ? arr[i] : max;
            min = arr[i] < min ? arr[i] : min;
        }

        vector<int> buckets[len];

        // put val to bucket
        for (int i = 0; i < len; ++i) {
            int bid = bucket(len,max,min,arr[i]);
            buckets[bid].push_back(arr[i]);
        }

        // sort every bucket
        for (int j = 0; j < len; ++j)
            std::sort(buckets[j].begin(),buckets[j].end());
        
        int index = 0;
        for (int k = 0; k < len; ++k) {
            for (int i = 0; i < buckets[k].size(); ++i) {
                arr[index++] = buckets[k][i];
            }
        }
    }

    int Sort::bucket(int len, int max, int min, int val) {
        // must add 1
        return (int)((val - min) * len / (max - min + 1));
    }

    void Sort::count_sort_for_radix(int *arr, int len,int xep) {
        int base = 10;
        int count[base];
        int output[len];
        memset(count,0, sizeof(count));

        // calculate element frequency
        for (int i = 0; i < len; ++i) {
            count[(arr[i] / xep) % base] ++;
        }

        // calculate element offset
        for (int j = 1; j < base; ++j) {
            count[j] += count[j - 1];
        }

        // build output array
        for (int k = len - 1; k >= 0; --k) {
            output[count[(arr[k] / xep) % base] - 1] = arr[k];
            count[(arr[k] / xep) % base] --;
        }

        // copy to src array
        for (int l = 0; l < len; ++l) {
            arr[l] = output[l];
        }
    }

    void Sort::radix_sort(int *arr, int len) {
        int max = INT_MIN;
        for (int i = 0; i < len; ++i) {
            max = arr[i] > max ? arr[i] : max;
        }

        for (int xep = 1; max/xep > 0 ; xep*=10) {
            count_sort_for_radix(arr,len,xep);
        }
    }
}
