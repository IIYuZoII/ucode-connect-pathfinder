#ifndef GETTERS_H
#define GETTERS_H

#include "pathfinder.h"

int get_real_count_of_islands(t_islands_list *head);
int get_sum_of_distances(int arr[HAS_ROUTE_LEN], int len_arr);
int get_free_pos(t_islands_list *node);
t_islands_list *get_island_by_index(t_islands_list *head, int index);
int get_index_by_name(t_islands_list *list, char *name);
char *get_name_by_index(t_islands_list *list, int index);
int g_l_f_p_i_a(int arr[HAS_ROUTE_LEN]);
int get_first_line(char *str);
int get_count_of_routs(t_islands_list *node);
int get_last_free_pos_in_arr(int arr[HAS_ROUTE_LEN]);
int get_dist_from_a_to_b(int index_a, int index_b, t_arrays array);
void get_shortest_path(t_islands_list *head, t_arrays arrays, int j,
                       int prev_index, int *total_len);
char *get_digit_in_char(int digit);

#endif //GETTERS_H
