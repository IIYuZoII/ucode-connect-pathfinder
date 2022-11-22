#include "../inc/libmx.h"

t_list *mx_create_node(void *data) {
    if (data == NULL) return NULL;

    t_list *node = NULL;
    node = malloc(sizeof(t_list));
    if (node == NULL) return NULL;

    node->data = data;
    node->next = NULL;

    return node;
}
