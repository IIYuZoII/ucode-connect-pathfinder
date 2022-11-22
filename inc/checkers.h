#ifndef CHECKERS_H
#define CHECKERS_H

#include "pathfinder.h"


bool check_line(const char *line);
bool check_if_this_rout_longer(t_islands_list *island, t_arrays arrays,
                               int prev_index);
bool check_is_this_rout_exists_in_arr(int arr[HAS_ROUTE_LEN], int index);
bool is_checked(t_arrays array, int index);

/**
 * @brief checks all bridges in str
 *
 * @param str
 * @return int 0 if all good or index of line in case of error
 */
int check_bridges_in_str(char *str);

#endif //CHECKERS_H
