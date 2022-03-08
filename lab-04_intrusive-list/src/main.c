#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <assert.h>
#include "clist.h"

#define container_of(ptr, type, member) (type*)((char*)(ptr) - offsetof(type, member))

typedef struct point {
	int x, y;
	struct intrusive_node node;
} point_t;

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

void show_all_points(intrusive_list_t *list) {
    intrusive_node_t *head = &(list->head);
    intrusive_node_t *current_node = head->next;
    
    while (current_node != head) {
        if (current_node != head->next)
            printf(" ");

        point_t *element = container_of(current_node, point_t, node);
        printf("(%d %d)", element->x, element->y);
        
        current_node = current_node->next;
    }
    printf("\n");
}

void remove_all_points(intrusive_list_t *list) {
    intrusive_node_t *head = &(list->head);

    while (head->next != head) {
        point_t *element = container_of(head->next, point_t, node);
        remove_node(list, &(element->node));
        free(element);
    }
}

int main() {
	intrusive_list_t l;
	init_list(&l);

    char *command = malloc(5 * sizeof(char));
    assert(command);

    while (scanf("%5s", command)) {
        if (strcmp(command, "add") == 0) {
            int x, y;
            scanf("%d %d", &x, &y);
            add_point(&l, x, y);
        }
        else if (strcmp(command, "rm") == 0) {
            int x, y;
            scanf("%d %d", &x, &y);
            remove_point(&l, x, y);
        }
        else if (strcmp(command, "print") == 0) 
            show_all_points(&l);
        else if (strcmp(command, "rma") == 0)
            remove_all_points(&l);
        else if (strcmp(command, "len") == 0)
            printf("%d\n", get_length(&l));
        else if (strcmp(command, "exit") == 0)
            break;
        else
            printf("Unknown command\n");
    }
    remove_all_points(&l);
    free(command);

	return 0;
}
