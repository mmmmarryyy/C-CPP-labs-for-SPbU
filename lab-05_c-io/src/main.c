#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "point_list.h"
#include <string.h>
#define container_of(ptr, type, member) (type*)((char*)(ptr) - offsetof(type, member))

void read_from_text_file(char *path_to_file, intrusive_list_t *l) {
    FILE *f = fopen(path_to_file, "r");
    int x, y;
    while (fscanf(f, "%d %d", &x, &y) == 2) 
        add_point(l, x, y);
    fclose(f);
}

int convert_from_additional(int number) {
    if (number >> 23 & 1) {
        number -= (1 << 24);
    }
    return number;
}

void read_from_binary_file(char *path_to_file, intrusive_list_t *l) {
    FILE *f = fopen(path_to_file, "rb");
    
    const int size_of_element = 3;
    int unsigned_x = 0, unsigned_y = 0;
    while (fread(&unsigned_x, size_of_element, 1, f) == 1 && fread(&unsigned_y, size_of_element, 1, f) == 1) {
        int x = convert_from_additional(unsigned_x);
        int y = convert_from_additional(unsigned_y);
        add_point(l, x, y);
    }
    fclose(f);
}

int convert_to_additional(int number) {
    if (number < 0) {
        number = -number;
        number = (1 << 24) - number;
    }
    return number;
}

void save_to_text_file(char *path_to_file, intrusive_list_t *l) {
    FILE *f = fopen(path_to_file, "w");
    
    intrusive_node_t *head = &(l->head);
    intrusive_node_t *cur_node = head->prev;
    
    while (cur_node != head) {
        point_t *item = container_of(cur_node, point_t, node);
        fprintf(f, "%d %d\n", item->x, item->y);
        cur_node = cur_node->prev;
    }
    fclose(f);
}

void save_to_binary_file(char *path_to_file, intrusive_list_t *l) {
    FILE *f = fopen(path_to_file, "wb");
    intrusive_node_t *head = &(l->head);
    intrusive_node_t *cur_node = head->prev;
    const int size_of_element = 3;
    
    while (cur_node != head) {
        point_t *item = container_of(cur_node, point_t, node);
        int x = convert_to_additional(item -> x);
        int y = convert_to_additional(item -> y);
        fwrite(&(x), size_of_element, 1, f);
        fwrite(&(y), size_of_element, 1, f);
        cur_node = cur_node->prev;
    }
    fclose(f);
}

void print_node(intrusive_node_t *node, void* fmt) {
    point_t *item = container_of(node, point_t, node);
    printf((char*)fmt, item->x, item->y);
}

void count_node(intrusive_node_t *node, void* number) {
    assert(node);
    (*(int*)number)++;
}



int main(int argc, char** argv) {
    if (argc < 4)
        return 0;
    char* type_of_file = argv[1];
    char* path_to_input_file = argv[2];
    intrusive_list_t list;
    intrusive_list_t *l = &list;
    init_list(l);
    if (strcmp(type_of_file, "loadtext") == 0)
        read_from_text_file(path_to_input_file, l);
    else
        read_from_binary_file(path_to_input_file, l);
    char* action = argv[3];
    if (strcmp(action, "savetext") == 0) {
        char* path_to_output_file = argv[4];
        save_to_text_file(path_to_output_file, l);
    }
    else if (strcmp(action, "savebin") == 0) {
        char* path_to_output_file = argv[4];
        save_to_binary_file(path_to_output_file, l);
    }
    else if (strcmp(action, "print") == 0) {
        char* fmt = argv[4];
        apply(l, print_node, fmt);
        printf("\n");
    }
    else {
        int *size = malloc(sizeof(int));
        assert(size);
        *size = 0;
        apply(l, count_node, size);
        printf("%d\n", *size);
        free(size);
    }
    remove_all_points(l);
    return 0;
}