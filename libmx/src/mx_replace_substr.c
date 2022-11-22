#include "../inc/libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    if (!str || !sub || !replace) return NULL;
    char *str_original = mx_strdup(str);
    int count_repeats = mx_count_substr(str_original, sub);
    if (count_repeats == 0) return str_original;

    char *str_res = mx_duplicate_str_before_sub(str, sub);
    int len_str_res = mx_strlen(str_res);
    int len_sub = mx_strlen(sub);
    int current_pos_in_str = len_str_res + len_sub;

    char *temp = str_res;
    char *buff = NULL;

    while (count_repeats > 0) {
        temp = str_res;
        str_res = mx_strjoin(str_res, replace);
        len_str_res = mx_strlen(str_res);
        free(temp);
        if (count_repeats > 1) {
            buff = mx_duplicate_str_before_sub(str + current_pos_in_str, sub);
            current_pos_in_str += mx_strlen(buff) + len_sub;
            temp = str_res;
            str_res = mx_strjoin(str_res, buff);
            free(temp);
            free(buff);
        }
        count_repeats--;
    }

    free(str_original);
    return str_res;
}

// int main(void) {
//     char *ptr = mx_replace_substr("Ururufff ruru uru", "uru", "ar");
//     char *ptr1 = mx_replace_substr("Ururufff ruru uru", "uru", "arab");
//     char *ptr2 = mx_replace_substr("1234 123 123123", "123", "098765");
//     char *ptr3 = mx_replace_substr("1234 123 123123", "can't find it",
//     "098765"); char *ptr4 = mx_replace_substr("1234 123 123123", "123",
//     NULL); char *ptr5 = mx_replace_substr("1234 123 123123", NULL, "321");

//     printf("%s\n", ptr);
//     printf("%s\n", ptr1);
//     printf("%s\n", ptr3);
//     printf("%s\n", ptr4);
//     printf("%s\n", ptr5);

//     free(ptr);
//     free(ptr1);
//     free(ptr2);
//     free(ptr3);

//     return 0;
// }
