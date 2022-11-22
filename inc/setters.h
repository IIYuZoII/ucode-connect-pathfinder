
#ifndef SETTERS_H
#define SETTERS_H

#include "pathfinder.h"

void set_has_route_by_default(t_islands_list *node);
void set_array_by_default(int *arr, int len);
void set_island_data(t_islands_list **head, char *name1, char *name2,
                     int distance);
void set_index_in_arr_to_default(t_arrays arrays, int index);

#endif //SETTERS_H
