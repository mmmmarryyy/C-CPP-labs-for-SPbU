#include "clist.h"

void init_list(intrusive_list_t *list) {
    intrusive_node_t *head = &(list->head);
    head->prev = head;
    head->next = head;
}

void add_node(intrusive_list_t *list, intrusive_node_t *element) {
    intrusive_node_t *head = &(list->head);
    intrusive_node_t *first_in_list = head->next;

    first_in_list->prev = element;

    element->next = first_in_list;
    element->prev = head;

    head->next = element;
}

void remove_node(intrusive_list_t*list, intrusive_node_t *node) {
    intrusive_node_t *next_node = node->next;
    intrusive_node_t *prev_node = node->prev;
    next_node->prev = prev_node;
    prev_node->next = next_node;
}

int get_length(intrusive_list_t *list) {
    intrusive_node_t *head = &(list->head);
    intrusive_node_t *current_node = head->next;
    int length = 0;
    while (current_node != head) {
        length++;
        current_node = current_node->next;
    }
    return length;
}
