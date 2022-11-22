#include "../inc/libmx.h"

char *mx_duplicate_str_before_sub(const char *str, const char *sub) {
    if (!str || !sub) return NULL;

    char *temp = mx_strstr(str, sub);
    int total_len = mx_strlen(str);
    int len_after_sub = mx_strlen(temp);
    int len_res = total_len - len_after_sub;
    char *res = mx_strndup(str, len_res);

    return res;
}



