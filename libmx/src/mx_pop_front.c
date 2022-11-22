#include "../inc/libmx.h"

void mx_pop_front(t_list **head) {
    if (head == NULL || *head == NULL) return;

    t_list *temp = (*head)->next;
    free(*head);
    *head = NULL;

    if (temp != NULL) *head = temp;
}
