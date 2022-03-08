#include "str.h"

char* my_strcpy(char* restrict res, const char* restrict src) {
    char* initial_res = res;
    while (*src != '\0') 
        *res++ = *src++;
    *res = '\0';
    return initial_res;
}

char* my_strcat(char* restrict dest, const char* restrict src) {
    char* initial_dest = dest; 
    while (*dest != '\0')
        dest++;
    while (*src != '\0')
        *dest++ = *src++;
    *dest = '\0';
    return initial_dest;
}

int my_strcmp(const char* str1, const char* str2) {
    while (*str1 && *str2 && *str1 == *str2) {
        ++str1; ++str2;
    }
    return *str1 - *str2;
}

size_t my_strlen(const char* string) {
    const char* begin = string;
    while (*string != '\0')
        string++;
    return string - begin;
}