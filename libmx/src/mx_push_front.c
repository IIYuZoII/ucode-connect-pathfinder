#include "../inc/libmx.h"

void mx_push_front(t_list **list, void *data) {
    if (*list == NULL) {
        *list = mx_create_node(data);
        return;
    }

    t_list *temp = mx_create_node(data);
    temp->next = *list;
    *list = temp;
}
