#ifndef CHECKERS_H
#define CHECKERS_H

#include "pathfinder.h"

// bool check_line(const char *line);
bool check_line(const char *line, int str_num);
bool check_if_this_rout_longer(t_islands_list *island, t_arrays arrays,
                               int prev_index);
bool check_is_this_rout_exists_in_arr(int arr[HAS_ROUTE_LEN], int index);
bool is_checked(t_arrays array, int index);
bool check_bridges_dup_in_str(char *str, const char *name_1,
                              const char *name_2);

int check_str_on_existings_free_lines(char *str);

/**
 * @brief checks all bridges in str
 *
 * @param str
 * @return int 0 if all good or index of line in case of error
 */
int check_bridges_in_str(char *str);

#endif  // CHECKERS_H
