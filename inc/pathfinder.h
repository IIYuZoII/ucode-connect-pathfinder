#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "../libmx/inc/libmx.h"
#include "errors_handle.h"


#define HAS_ROUTE_LEN 100


typedef struct s_islands_list {
    char *name;
    int index;
    int has_route[HAS_ROUTE_LEN];
    int distance[HAS_ROUTE_LEN];
    struct s_islands_list *next;
} t_islands_list;


typedef struct s_arrays {
    int already_has_route[HAS_ROUTE_LEN];
    int a_h_r_helper[HAS_ROUTE_LEN];
    int all_distances[HAS_ROUTE_LEN];
    char *start_name;
    int start_index;
    int checked_islands[HAS_ROUTE_LEN];
    char *looking_name;
    int looking_index;
    int current_distance;

    int shortest_distance;

    t_islands_list *ptr_on_start;

} t_arrays;

#include "checkers.h"
#include "setters.h"
#include "readers.h"
#include "printers.h"
#include "getters.h"

t_islands_list *create_island(char *name, int index);

long int long_atoi(const char *str);

void del_whole_list(t_islands_list *head);

char *read_line_before_chr(const char *filename, const char ch, int *new_size);


#endif  // PATHFINDER_H
