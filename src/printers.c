#include "../inc/pathfinder.h"

// DONE
void print_total_distance(t_arrays arrays) {
    int last_pos = g_l_f_p_i_a(arrays.all_distances);
    int sum = get_sum_of_distances(arrays.all_distances, last_pos);
    if (sum == 0) return;

    int correcting = 0;

    mx_printstr("Distance: ");
    if (last_pos == 1) {
        mx_printint(arrays.all_distances[0]);
        mx_printchar('\n');
    }
    else {
        for (int i = 0 + correcting; i < last_pos; i++) {
            mx_printint(arrays.all_distances[i]);
            if (i + 1 == last_pos) break;
            mx_printstr(" + ");
        }
        mx_printstr(" = ");
    
        mx_printint(sum);
        mx_printchar('\n');
    }
}

void print_num_to_errout(int num) {
    int count = mx_count_digits_in_int(num) - 1;
    for (int i = count; i >= 0; i--) {
        int digit = mx_get_digit_by_pos(num, i);
        mx_printerr(get_digit_in_char(digit));
    }
}

void print_routes_inside(t_islands_list *head, char *str, t_arrays arrays,
                         int j, int prev_index, int total_len) {
    int routes = get_free_pos(head);

    int pos = g_l_f_p_i_a(arrays.all_distances);
    if (prev_index != head->index) {
        int dist = 0;
        dist = get_dist_from_a_to_b(prev_index, head->index, arrays);
        arrays.all_distances[pos] = dist;
    }

    if (is_checked(arrays, head->index)) {
        return;
    }

    if (arrays.start_index == head->index) {
        int i = g_l_f_p_i_a(arrays.checked_islands);
        arrays.checked_islands[i] = head->index;
    }

    if (check_if_this_rout_longer(head, arrays, prev_index)) {
        int last_pos = g_l_f_p_i_a(arrays.all_distances);
        int sum = get_sum_of_distances(arrays.all_distances, last_pos);
        if (sum > arrays.shortest_distance) {
            return;
        }
    }

    str = mx_strjoin(str, head->name);
    if (prev_index != head->index &&
        mx_strcmp(head->name, arrays.looking_name) == 0) {
        int last_pos = g_l_f_p_i_a(arrays.all_distances);
        int sum = get_sum_of_distances(arrays.all_distances, last_pos);
        if (sum <= arrays.shortest_distance) {
            mx_printstr("========================================");
            mx_printchar('\n');

            mx_printstr("Path: ");
            mx_printstr(arrays.start_name);
            mx_printstr(" -> ");
            mx_printstr(arrays.looking_name);
            mx_printchar('\n');

            mx_printstr("Route: ");
            mx_printstr(str);
            mx_printchar('\n');

            print_total_distance(arrays);

            mx_printstr("========================================");
            mx_printchar('\n');
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
        char *temp = mx_strjoin(str, " -> ");
        t_islands_list *temp_ptr =
            get_island_by_index(arrays.ptr_on_start, head->has_route[i]);
        if (temp_ptr == NULL) {
            break;
        }
        if (temp_ptr->index == prev_index) {
            free(temp);
            continue;
        }
        print_routes_inside(temp_ptr, temp, arrays, j - 1, head->index,
                            (total_len + head->distance[i]));
        free(temp);
    }

    set_index_in_arr_to_default(arrays, head->index);
    arrays.all_distances[pos] = -1;

    if (str != NULL) free(str);
}

void printing_handle(t_islands_list *head) {
    int count = get_real_count_of_islands(head);
    t_arrays arrays;
    arrays.ptr_on_start = head;

    char *buff = NULL;

    t_islands_list *current = head;
    t_islands_list *ptr = head;
    for (int i = 1; i <= count; i++) {
        arrays.start_name = current->name;
        arrays.start_index = current->index;
        while (true) {
            int total_len = -1;
            arrays.looking_name = ptr->name;
            set_array_by_default(arrays.already_has_route, HAS_ROUTE_LEN);
            set_array_by_default(arrays.a_h_r_helper, HAS_ROUTE_LEN);
            set_array_by_default(arrays.all_distances, HAS_ROUTE_LEN);
            set_array_by_default(arrays.checked_islands, HAS_ROUTE_LEN);
            arrays.current_distance = -1;
            get_shortest_path(current, arrays, 0, current->index, &total_len);
            arrays.shortest_distance = total_len;

            set_array_by_default(arrays.already_has_route, HAS_ROUTE_LEN);
            set_array_by_default(arrays.a_h_r_helper, HAS_ROUTE_LEN);
            set_array_by_default(arrays.all_distances, HAS_ROUTE_LEN);
            set_array_by_default(arrays.checked_islands, HAS_ROUTE_LEN);
            arrays.current_distance = -1;
            print_routes_inside(current, buff, arrays, 0, current->index, 0);

            if (ptr->next == NULL) break;
            ptr = ptr->next;
        }

        if (current->next == NULL) break;
        current = current->next;
        ptr = current;
    }
}
