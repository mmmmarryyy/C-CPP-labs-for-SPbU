#include "point_list.h"

#define container_of(ptr, type, member) (type*)((char*)(ptr) - offsetof(type, member))

void add_point(intrusive_list_t *list, int x, int y) {
	point_t *point = malloc(sizeof(point_t));
	assert(point);
	point->x = x;
	point->y = y;
	add_node(list, &(point->node));
}

void remove_point(intrusive_list_t *list, int x, int y) { 
    intrusive_node_t *head = &(list->head);
    intrusive_node_t *current_node = head->next;
    
    while (current_node != head) {
        intrusive_node_t *next_node = current_node->next;
        
        point_t *element = container_of(current_node, point_t, node);
        if (element->x == x && element->y == y) {
            remove_node(list, &(element->node));
            free(element);
        }
        
        current_node = next_node;
    }
}

void remove_all_points(intrusive_list_t *list) {
    intrusive_node_t *head = &(list->head);

    while (head->next != head) {
        point_t *element = container_of(head->next, point_t, node);
        remove_node(list, &(element->node));
        free(element);
    }
}

void show_all_points(intrusive_list_t *list) {
    intrusive_node_t *head = &(list->head);
    intrusive_node_t *current_node = head->prev;
    
    while (current_node != head) {
        if (current_node != head->prev)
            printf(" ");

        point_t *element = container_of(current_node, point_t, node);
        printf("(%d %d)", element->x, element->y);
        
        current_node = current_node->prev;
    }
    printf("\n");
}