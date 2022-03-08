#include "mergesort.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

int char_comparator(const void* first, const void* second) {
    return *(char*)first - *(char*)second;
}

int int_comparator(const void* first, const void* second) {
    return *(int*)first - *(int*)second;
}

int str_comparator(const void* first, const void* second) {
    return strcmp(*(char**)first, *(char**)second);
}

void print_int(void* array, int index) {
    printf("%d", ((int*)array)[index]);
}

void print_char(void* array, int index) {
    printf("%c", ((char*)array)[index]);
}

void print_str(void* array, int index) {
    printf("%s", ((char**)array)[index]);
}

int call_mergesort(void* array, size_t size, size_t size_of_elements, int (*comparator)(const void*, const void*), void (*print)(void*, int)) {
    int correct = mergesort(array, size, size_of_elements, comparator);
    if (correct == -1) {
        printf("%s\n", "Error: memory allocation failed.");
        return 1;
    }

    for (int i = 0; i < size; i++) {
        print(array, i);
        if (i != size - 1) printf(" ");
    }
    
    printf("\n");
    return 0;
}

int main(int argc, char** argv) {
    char* type = *(argv+1); 
    const size_t size = argc - 2;

    if(strcmp(type, "char") == 0) {
        char array[size]; 
        assert(array); 
        for (int i = 0; i < size; i++)
            array[i] = *argv[i + 2]; 

        return call_mergesort(array, size, sizeof(char), char_comparator, print_char);  
    }
    
    if(strcmp(type, "int") == 0) {
        int array[size];
        assert(array);
        for (int i = 0; i < size; i++)
            array[i] = atoi(argv[i + 2]);
        
        return call_mergesort(array, size, sizeof(int), int_comparator, print_int);
    }

    if (strcmp(type, "str") == 0) {
        char* array[size];
        assert(array);
        for (int i = 0; i < size; i++)
            array[i] = argv[i + 2];

        return call_mergesort(array, size, sizeof(char*), str_comparator, print_str);
    }
}