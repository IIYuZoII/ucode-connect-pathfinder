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
        if (mx_strlen(temp) == 0) {
            return str_num;
        }
        if (check_line(temp) == false) {
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

bool check_line(const char *line) {
    bool is_alpha_found = false;
    bool is_first_word_found = false;
    bool is_second_word_found = false;
    bool is_num_found = false;

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
