
#ifndef READERS_H
#define READERS_H

#include "pathfinder.h"

void read_file(char *filename, t_islands_list **head);
void free_all_in_read_file(t_islands_list *head, char *str, char *name1,
                           char *name2, char *temp);

#endif  // READERS_H
