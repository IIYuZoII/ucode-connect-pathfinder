#include "../inc/libmx.h"

void mx_pop_back(t_list **head) {
    if (!head || !*head) return;
    t_list *node_to_del = *head;
    t_list *node_to_save = *head;
    for (; node_to_del->next != NULL; node_to_del = node_to_del->next) {
        node_to_save = node_to_del;
    }
    
    if (node_to_del == *head) *head = NULL;
    if (node_to_save != NULL) node_to_save->next = NULL;
    free(node_to_del);
}
