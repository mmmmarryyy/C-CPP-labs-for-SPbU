#include "mergesort.h"
#include <string.h>

int func_mergesort(char* array, size_t element_size, 
                    int (*comparator)(const void*, const void*), 
                    int left, int right) {
    if (right - left <= 1)
        return 0;

    int mid = (left + right) / 2;
    int correct_l = func_mergesort(array, element_size, comparator, left, mid);
    int correct_r = func_mergesort(array, element_size, comparator, mid, right);

    if (correct_l == -1 || correct_r == -1)
        return -1;

    char* sorted_subarray = (char*)malloc((right - left) * element_size);
    if (sorted_subarray == NULL)
        return -1;
    
    int first = left, second = mid;
    while (first < mid || second < right) {
        char* dest = sorted_subarray + (first - left + second - mid) * element_size;
        char* element1 = array + first * element_size;
        char* element2 = array + second * element_size;
        if (second == right || 
                (first != mid && comparator((void*)element1, (void*)element2) <= 0)) {
            memcpy(dest, element1, element_size);
            first++;
        }
        else {
            memcpy(dest, element2, element_size);   
            second++;
        }
    }

    for (int i = left; i < right; i++)
        memcpy(array + i * element_size, sorted_subarray + (i - left) * element_size, element_size);
    
    free(sorted_subarray);
    return 0;
}

int mergesort(void* array, size_t elements, size_t element_size, int (*comparator)(const void*, const void*)) {
    return func_mergesort((char*)array, element_size, comparator, 0, elements);
}