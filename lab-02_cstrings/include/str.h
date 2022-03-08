#ifndef STR_H
#define STR_H

#include <stddef.h>

char* my_strcpy(char* restrict res, const char* restrict src);

char* my_strcat(char* restrict dest, const char* restrict src);

int my_strcmp(const char* str1, const char* str2);

size_t my_strlen(const char* str);

#endif