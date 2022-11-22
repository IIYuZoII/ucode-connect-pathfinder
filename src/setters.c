#include "../inc/pathfinder.h"

void set_has_route_by_default(t_islands_list *node) {
    for (int i = 0; i < HAS_ROUTE_LEN; i++) {
        node->has_route[i] = -1;
    }
}

void set_array_by_default(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        arr[i] = -1;
    }
}




void set_island_data(t_islands_list **head, char *name1, char *name2,
                     int distance) {
    bool name1_exists = false;
    bool name2_exists = false;

    if (*head == NULL) {
        *head = create_island(name1, 0);
        set_has_route_by_default(*head);
        name1_exists = true;
    }

    t_islands_list *ptr = *head;

    int index = 0;
    int index_name1 = 0;
    int index_name2 = 0;
    while (true) {
        if (mx_strcmp(name1, ptr->name) == 0) {
            name1_exists = true;
        }
        if (mx_strcmp(name2, ptr->name) == 0) {
            name2_exists = true;
        }
        if (name1_exists && name2_exists) break;

        if (ptr->next == NULL) {
            ptr->next = malloc(sizeof(t_islands_list));
            index = ptr->index + 1;
            ptr = ptr->next;
            set_has_route_by_default(ptr);
            ptr->next = NULL;
            break;
        }
        ptr = ptr->next;
    }

    if (name1_exists == false) {
        ptr->name = mx_strjoin(NULL, name1);
        ptr->index = index;
        index_name1 = index;
    }

    if (name2_exists == false && name1_exists == false) {
        ptr->next = malloc(sizeof(t_islands_list));
        index = ptr->index + 1;
        index_name2 = index;
        ptr = ptr->next;
        set_has_route_by_default(ptr);
        ptr->index = index;
        ptr->next = NULL;
        ptr->name = mx_strjoin(NULL, name2);
    }

    if (name2_exists == false && name1_exists == true) {
        ptr->name = mx_strjoin(NULL, name2);
        ptr->index = index;
        index_name2 = index;
    }

    ptr = *head;

    if (name1_exists && !name2_exists) {
        while (true) {
            if (mx_strcmp(name1, ptr->name) == 0) {
                int i = get_free_pos(ptr);
                ptr->has_route[i] = index_name2;
                ptr->distance[i] = distance;
                break;
            }
            ptr = ptr->next;
        }
        ptr = get_island_by_index(*head, index_name2);
        int i = g_l_f_p_i_a(ptr->has_route);
        index_name1 = get_index_by_name(*head, name1);
        ptr->has_route[i] = index_name1;
        ptr->distance[i] = distance;
    }

    if (!name1_exists && name2_exists) {
        index_name2 = get_index_by_name(*head, name2);
        while (true) {
            if (mx_strcmp(name2, ptr->name) == 0) {
                int i = get_free_pos(ptr);
                ptr->has_route[i] = index_name1;
                ptr->distance[i] = distance;
                break;
            }
            ptr = ptr->next;
        }

        ptr = get_island_by_index(*head, index_name1);
        int i = g_l_f_p_i_a(ptr->has_route);
        ptr->has_route[i] = index_name2;
        ptr->distance[i] = distance;
    }

    if (!name1_exists && !name2_exists) {
        index_name1 = get_index_by_name(*head, name1);
        index_name2 = get_index_by_name(*head, name2);
        ptr = get_island_by_index(*head, index_name1);

        int i = g_l_f_p_i_a(ptr->has_route);
        ptr->has_route[i] = index_name2;
        ptr->distance[i] = distance;

        ptr = get_island_by_index(*head, index_name2);
        i = g_l_f_p_i_a(ptr->has_route);
        ptr->has_route[i] = index_name1;
        ptr->distance[i] = distance;
    }

    if (name1_exists && name2_exists) {
        index_name1 = get_index_by_name(*head, name1);
        index_name2 = get_index_by_name(*head, name2);

        // setting fisrt island
        ptr = get_island_by_index(*head, index_name1);
        int i = g_l_f_p_i_a(ptr->has_route);
        ptr->has_route[i] = index_name2;
        ptr->distance[i] = distance;

        // setting second island
        ptr = get_island_by_index(*head, index_name2);
        i = g_l_f_p_i_a(ptr->has_route);
        ptr->has_route[i] = index_name1;
        ptr->distance[i] = distance;
    }
}



// DONE
void set_index_in_arr_to_default(t_arrays arrays, int index) {
    for (int i = 0; i < HAS_ROUTE_LEN; i++) {
        if (arrays.already_has_route[i] == index) {
            arrays.already_has_route[i] = -1;
            arrays.a_h_r_helper[i] = -1;
            break;
        }
    }
}




