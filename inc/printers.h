
#ifndef PRINTERS_H
#define PRINTERS_H

#include "pathfinder.h"

void print_total_distance(t_arrays arrays);
void print_num_to_errout(int num);
void print_routes_inside(t_islands_list *head, char *str, t_arrays arrays,
                         int j, int prev_index, int total_len);
void printing_handle(t_islands_list *head);

#endif  // PRINTERS_H
