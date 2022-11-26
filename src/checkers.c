#include "../inc/pathfinder.h"

static bool find_sub_in_str(const char *haystack, const char *needle) {
    int len_input = mx_strlen(haystack);
    int len_needle = mx_strlen(needle);
    for (int i = 0; i < len_input; i++) {
        if (mx_strncmp(haystack, needle, len_needle) == 0) return true;
        haystack++;
    }

    return false;
}

bool check_bridges_dup_in_str(char *str, const char *name_1,
                              const char *name_2) {


    char *ptr = str;
    char *temp = NULL;
    int index_of_end_line = 0;

    char *name = NULL;
    char *name2 = NULL;
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
            break;
        }
        else {
            temp = mx_strndup(ptr, index_of_end_line);
            clean_up_temp = temp;
        }

        //взяли первое имя
        index_of_end_line = mx_get_char_index(temp, '-');
        name = mx_strndup(temp, index_of_end_line);

        //скипнули '-'
        temp += index_of_end_line + 1;

        //взяли второе имя
        index_of_end_line = mx_get_char_index(temp, ',');
        name2 = mx_strndup(temp, index_of_end_line);

        if (mx_strcmp(name, name_1) == 0 && mx_strcmp(name2, name_2) == 0) {
            free_all_in_read_file(NULL, NULL, name, name2, clean_up_temp);
            return true;
        }
        if (mx_strcmp(name, name_2) == 0 && mx_strcmp(name2, name_1) == 0) {
            free_all_in_read_file(NULL, NULL, name, name2, clean_up_temp);
            return true;
        }

        free_all_in_read_file(NULL, NULL, name, name2, clean_up_temp);
    }

    return false;
}

int check_bridges_in_str(char *str) {
    char *ptr = str;
    char *temp = NULL;
    int index_of_end_line = 0;
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

        if (str_num == 2 && mx_strlen(temp) == 0) {
            free(clean_up_temp);
            return str_num;
        }
        else if (str_num > 2 && mx_strlen(temp) == 0) {
            return 0;
        }
        if (check_line(temp, str_num) == false) {
            free(clean_up_temp);
            return str_num;
        }

        int comma_index = mx_get_char_index(temp, ',');
        char *bridge = mx_strndup(temp, comma_index);
        int len_bridge = mx_strlen(bridge);

        if (find_sub_in_str(ptr + len_bridge, bridge)) {
            free(bridge);
            free(clean_up_temp);
            return -1;
        }

        free(bridge);
        free(clean_up_temp);
        str_num++;
    }
    return 0;
}

int check_str_on_existings_free_lines(char *str) {
    bool is_ended = false;
    int str_num = 2;
    char *ptr = str;
    char *temp = NULL;
    int bad_line = 0;
    int index_of_end_line = 0;

    while (true) {
        ptr = mx_strchr(ptr, '\n');
        if (ptr != NULL) {
            ptr++;
        }
        else {
            break;
        }
        if (mx_strlen(ptr) == 0) {
            if (is_ended == true) {
                return bad_line;
            }
            else {
                break;
            }
        }
        temp = NULL;
        index_of_end_line = mx_get_char_index(ptr, '\n');
        if (index_of_end_line == -1 && str_num == 2) {
            error_printing_handle(ERR_LINE_INVALID, NULL, str_num);
        }
        if (index_of_end_line == -1) {
            if (is_ended == false) {
                is_ended = true;
                bad_line = str_num;
            }
            else {
                if (temp) free(temp);
                return bad_line;
            }
            index_of_end_line = mx_get_char_index(ptr, '\0');
            if (index_of_end_line == -1) {
                temp = ptr;
                if (mx_strlen(temp) != 0) {
                    return bad_line;
                }
            }
        }
        else {
            temp = mx_strndup(ptr, index_of_end_line);
        }

        if (check_line(temp, str_num) == false) {
            if (temp) free(temp);
            return str_num;
        }

        if (mx_strlen(temp) == 0) {
            if (is_ended == false) {
                is_ended = true;
                bad_line = str_num;
            }
            else {
                if (temp) free(temp);
                return bad_line;
            }
        }

        str_num++;
        if (temp) free(temp);
    }
    return 0;
}

bool check_line(const char *line, int str_num) {
    bool is_alpha_found = false;
    bool is_first_word_found = false;
    bool is_second_word_found = false;
    bool is_num_found = false;

    int line_len = mx_strlen(line);
    if (line_len == 0 && str_num == 2) {
        return false;
    }

    for (int i = 0; line[i]; i++) {
        if (is_first_word_found == false) {
            if (!mx_isalpha(line[i]) && line[i] != '-') return false;
            else if (mx_isalpha(line[i])) is_alpha_found = true;
            else if (is_alpha_found && line[i] == '-') {
                is_first_word_found = true;
                is_alpha_found = false;
            }
            continue;
        }
        else if (is_second_word_found == false) {
            if (!mx_isalpha(line[i]) && line[i] != ',') return false;
            else if (mx_isalpha(line[i])) is_alpha_found = true;
            else if (is_alpha_found && line[i] == ',') {
                is_second_word_found = true;
                is_alpha_found = false;
            }
            continue;
        }
        else {
            if (!mx_isdigit(line[i]) && line[i] != '\n') return false;
            else if (mx_isdigit(line[i])) {
                if (!line[i + 1]) is_num_found = true;
            }
        }
    }

    if (is_first_word_found && is_second_word_found && is_num_found)
        return true;
    return false;
}

bool check_if_this_rout_longer(t_islands_list *island, t_arrays arrays,
                               int prev_index) {
    for (int i = 0; i < HAS_ROUTE_LEN; i++) {
        if (island->index == arrays.already_has_route[i] &&
            arrays.a_h_r_helper[i] != prev_index) {
            return true;
        }
    }

    return false;
}

bool check_is_this_rout_exists_in_arr(int arr[HAS_ROUTE_LEN], int index) {
    for (int i = 0; i < HAS_ROUTE_LEN; i++) {
        if (arr[i] == index) return true;
    }
    return false;
}

bool is_checked(t_arrays array, int index) {
    for (int i = 0; i < HAS_ROUTE_LEN; i++) {
        if (index == array.checked_islands[i]) return true;
    }
    return false;
}
