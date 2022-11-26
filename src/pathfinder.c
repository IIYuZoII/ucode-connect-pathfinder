#include "../inc/pathfinder.h"

t_islands_list *create_island(char *name, int index) {
    t_islands_list *island = NULL;
    island = malloc(sizeof(t_islands_list));
    if (island == NULL) return NULL;

    island->name = mx_strdup(name);
    island->index = index;
    island->next = NULL;

    return island;
}

void check_file_and_content_on_existing(char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        error_printing_handle(ERR_FILE_DOESNT_EXIST, filename, 0);
    }
    char buff[1];
    int status = read(fd, buff, 1);
    if (status == 0) {
        error_printing_handle(ERR_FILE_IS_EMPTY, filename, 0);
    }
    close(fd);
}

void print_all_for_test(t_islands_list *head) {
    t_islands_list *ptr = head;
    int i = 0;
    while (true) {
        printf("%s\n", "==================================");
        printf("head->name(%d): %s\n", i, ptr->name);
        printf("head->index(%d): %d\n", i, ptr->index);
        for (int i = 0; i < get_free_pos(ptr); i++) {
            printf("%d  ", ptr->has_route[i]);
        }
        printf("\n");
        for (int i = 0; i < get_free_pos(ptr); i++) {
            printf("%d  ", ptr->distance[i]);
        }
        printf("\n");

        printf("%s\n", "==================================");
        printf("\n");
        if (ptr->next == NULL) {
            break;
        }
        i++;
        ptr = ptr->next;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        error_printing_handle(ERR_INVALID_NUM_OF_ARGV, NULL, 0);
    }

    check_file_and_content_on_existing(argv[1]);

    t_islands_list *head = NULL;
    read_file(argv[1], &head);

    if (head != NULL) {
        printing_handle(head);
    }

    del_whole_list(head);

    return 0;
}
