#include "../inc/pathfinder.h"

void del_whole_list(t_islands_list *head) {
    if (!head) return;
    int count = get_real_count_of_islands(head);
    t_islands_list *ptr = head;
    t_islands_list *ptr_prev;
    for (int i = 0; i < count; i++) {
        while (true) {
            if (ptr->next == NULL) {
                if (ptr_prev->next != NULL) ptr_prev->next = NULL;
                free(ptr->name);
                free(ptr);
                break;
            }
            ptr_prev = ptr;
            ptr = ptr->next;
        }
        ptr = head;
    }
}
