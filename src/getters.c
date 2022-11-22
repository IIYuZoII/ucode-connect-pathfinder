#include "../inc/pathfinder.h"


int get_real_count_of_islands(t_islands_list *head) {
    int count = 0;
    while (true) {
        count++;
        if (head->next == NULL) break;
        head = head->next;
    }
    return count;
}

int get_sum_of_distances(int arr[HAS_ROUTE_LEN], int len_arr) {
    int res = 0;
    for (int i = 0; i < len_arr; i++) {
        res += arr[i];
    }
    return res;
}


int get_free_pos(t_islands_list *node) {
    int last_pos = 0;
    for (int i = 0; i < HAS_ROUTE_LEN; i++) {
        if (node->has_route[i] == -1) {
            return i;
        }
    }
    return last_pos;
}


t_islands_list *get_island_by_index(t_islands_list *head, int index) {
    while (true) {
        if (head->index == index) return head;
        if (head->next == NULL) break;
        head = head->next;
    }
    return NULL;
}

int get_index_by_name(t_islands_list *list, char *name) {
    while (true) {
        if (mx_strcmp(list->name, name) == 0) {
            return list->index;
        }
        if (list->next == NULL) {
            break;
        }
        list = list->next;
    }
    return -1;
}

char *get_name_by_index(t_islands_list *list, int index) {
    while (true) {
        if (list->index == index) {
            return list->name;
        }
        list = list->next;
    }
    return NULL;
}

int g_l_f_p_i_a(int arr[HAS_ROUTE_LEN]) {
    int last_pos = 0;
    bool is_found = false;
    for (int i = 0; i < HAS_ROUTE_LEN; i++) {
        if (arr[i] != -1 && is_found == false) {
            last_pos = i;
            is_found = true;
        }
        if (arr[i] == -1 && is_found == true) {
            return i;
        }
    }
    return last_pos;
}




/**
 * @brief Checks first line
 *
 * return -1 if line is invalid
 */
int get_first_line(char *str) {
    int index = mx_get_char_index(str, '\n');
    if (index == -1) {
        return -1;
    }
    char *buff = mx_strndup(str, index);
    for (int i = 0; i < index; i++) {
        if (!mx_isdigit(buff[i])) {
            free(buff);
            return -1;
        }
    }
    int res = mx_atoi(buff);
    free(buff);
    return res;
}



// DONE
int get_count_of_routs(t_islands_list *node) {
    int res = 0;
    for (int i = 0; i < HAS_ROUTE_LEN; i++) {
        if (node->has_route[i] != -1) res++;
    }
    return res;
}



// DONE
int get_last_free_pos_in_arr(int arr[HAS_ROUTE_LEN]) {
    int last_pos = 0;
    for (int i = 0; i < HAS_ROUTE_LEN; i++) {
        if (arr[i] != -1) last_pos = i;
    }
    return last_pos;
}



int get_dist_from_a_to_b(int index_a, int index_b, t_arrays array) {
    t_islands_list *ptr_a = get_island_by_index(array.ptr_on_start, index_a);
    for (int i = 0; i < HAS_ROUTE_LEN; i++) {
        if (ptr_a->has_route[i] == index_b) {
            return ptr_a->distance[i];
        }
    }
    return 0;
}


// mx_itoa doesn't work inside the func error_printing_handle
// so I have to use this crutch... I know that it seems so bad...

char *get_digit_in_char(int digit) {
    switch (digit) {
        case 0:
            return ("0");
        case 1:
            return ("1");
        case 2:
            return ("2");
        case 3:
            return ("3");
        case 4:
            return ("4");
        case 5:
            return ("5");
        case 6:
            return ("6");
        case 7:
            return ("7");
        case 8:
            return ("8");
        case 9:
            return ("9");
        default:
            return("0");
    }
}




void get_shortest_path(t_islands_list *head, t_arrays arrays, int j,
                       int prev_index, int *total_len) {
    int routes = get_free_pos(head);

    if (is_checked(arrays, head->index)) {
        return;
    }

    if (arrays.start_index == head->index) {
        int i = g_l_f_p_i_a(arrays.checked_islands);
        arrays.checked_islands[i] = head->index;
    }

    if (check_if_this_rout_longer(head, arrays, prev_index)) {
        return;
    }

    if (prev_index != head->index &&
        mx_strcmp(head->name, arrays.looking_name) == 0) {
        int last_pos = g_l_f_p_i_a(arrays.all_distances);
        int sum = get_sum_of_distances(arrays.all_distances, last_pos);
        if (*total_len == -1 || sum < *total_len) {
            *total_len = sum;
        }
    }

    if (routes > 1) {
        int move = 0;
        for (int k = 0; k < get_free_pos(head); k++) {
            if (check_is_this_rout_exists_in_arr(arrays.already_has_route,
                                                 head->has_route[k])) {
                move++;
            }
        }
        for (int i = 1 + move; i <= routes + move; i++) {
            arrays.already_has_route[j] = head->has_route[i];
            if (arrays.already_has_route[j] != -1) {
                arrays.a_h_r_helper[j] = head->index;
            }
            j++;
        }
    }

    if (j == 0) j++;

    for (int i = 0; i < routes; i++) {
        int pos = g_l_f_p_i_a(arrays.all_distances);
        arrays.all_distances[pos] = head->distance[i];
        t_islands_list *temp_ptr =
            get_island_by_index(arrays.ptr_on_start, head->has_route[i]);
        if (temp_ptr == NULL) {
            break;
        }
        if (temp_ptr->index == prev_index) {
            continue;
        }
        get_shortest_path(temp_ptr, arrays, j - 1, head->index, total_len);
        arrays.all_distances[pos] = -1;
    }
    set_index_in_arr_to_default(arrays, head->index);
}





