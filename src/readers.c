#include "../inc/pathfinder.h"

static void free_all_in_read_file(t_islands_list *head, char *str, char *name1,
                                  char *name2, char *temp) {
    del_whole_list(head);
    if (head || str || name1 || name2 || temp) {
    }
    if (str) free(str);
    if (name1) free(name1);
    if (name2) free(name2);
    if (temp) free(temp);
}

void read_file(char *filename, t_islands_list **head) {
    char *str = mx_file_to_str(filename);
    int check_bridges_res = check_bridges_in_str(str);
    if (check_bridges_res < 0) {
        free(str);
        error_printing_handle(ERR_DUPLICATE_BRIDGES, NULL, 0);
    }
    else if (check_bridges_res > 0) {
        free(str);
        error_printing_handle(ERR_LINE_INVALID, NULL, check_bridges_res);
    }

    char *ptr = str;
    int count_islands = get_first_line(str);  //взяли кол-во островов
    if (count_islands < 0) {
        free(str);
        error_printing_handle(ERR_FIRST_LINE_INVALID, NULL, 0);
    }
    long int total_dist = 0L;
    char *temp = NULL;
    int index_of_end_line = 0;

    char *name = NULL;
    char *name2 = NULL;
    long int distance_int = 0;
    int str_num = 2;

    while (true) {
        char *clean_up_temp = NULL;

        ptr = mx_strchr(ptr, '\n');  //сдвинули строку на следующую
        if (ptr != NULL) {
            ptr++;
        }
        else {
            break;
        }

        //взяли строку
        temp = NULL;
        index_of_end_line = mx_get_char_index(ptr, '\n');
        if (index_of_end_line == -1) {
            index_of_end_line = mx_get_char_index(ptr, '\0');
            if (index_of_end_line == -1) {
                temp = ptr;
            }
        }
        else {
            temp = mx_strndup(ptr, index_of_end_line);
            clean_up_temp = temp;
        }

        //чекнули строку
        if (check_line(temp) == false) {
            free_all_in_read_file(*head, str, NULL, NULL, clean_up_temp);
            error_printing_handle(ERR_LINE_INVALID, NULL, str_num);
        }

        //взяли первое имя
        index_of_end_line = mx_get_char_index(temp, '-');
        name = mx_strndup(temp, index_of_end_line);

        //скипнули '-'
        temp += index_of_end_line + 1;

        //взяли второе имя
        index_of_end_line = mx_get_char_index(temp, ',');
        name2 = mx_strndup(temp, index_of_end_line);

        if (mx_strcmp(name, name2) == 0) {
            free_all_in_read_file(*head, str, name, name2, clean_up_temp);
            error_printing_handle(ERR_LINE_INVALID, NULL, str_num);
        }

        //скипнули ','
        temp += index_of_end_line + 1;

        //взяли расстояние
        int temp_len = mx_strlen(temp);
        if (temp_len == 10) {
            int num = temp[9];
            if (num > 7 + '0') {
                free_all_in_read_file(*head, str, name, name2, clean_up_temp);
                error_printing_handle(ERR_TOTAL_LEN_TOO_BIG, NULL, 0);
            }
        }
        distance_int = long_atoi(temp);
        total_dist += distance_int;
        if (total_dist > 2147483647 || temp_len > 10) {
            free_all_in_read_file(*head, str, name, name2, clean_up_temp);
            error_printing_handle(ERR_TOTAL_LEN_TOO_BIG, NULL, 0);
        }

        set_island_data(head, name, name2, distance_int);
        free_all_in_read_file(NULL, NULL, name, name2, clean_up_temp);
        str_num++;
    }

    int real_count_of_islands = get_real_count_of_islands(*head);
    if (real_count_of_islands != count_islands) {
        del_whole_list(*head);
        free(str);
        error_printing_handle(ERR_INVALID_NUM_OF_ISLANDS, NULL, 0);
    }

    free(str);
}
