#include "test_str.h"
#include "str.h"

void test_my_strcmp() {
    char firstString[4] = "abc\0";
    char secondString1[3] = "ba\0";
    assert(my_strcmp(firstString, secondString1) < 0);
    char secondString2[4] = "abc\0";
    assert(my_strcmp(firstString, secondString2) == 0);
    char secondString3[3] = "ab\0";
    assert(my_strcmp(firstString, secondString3) > 0);
}

void test_my_strcpy() {
    char firstString[6];
    char secondString[6] = "abcde\0";
    my_strcpy(firstString, secondString);
    assert(my_strcmp(firstString, secondString) == 0);
}

void test_my_strcat() {
    char firstString[9] = "abc\0";
    char secondString[6] = "defgh\0";
    my_strcat(firstString, secondString);
    char res[9] = "abcdefgh\0";
    assert(my_strcmp(firstString, res) == 0);
}

void test_my_strlen() {
    assert(my_strlen("abcde") == 5);
    assert(my_strlen("") == 0);
}