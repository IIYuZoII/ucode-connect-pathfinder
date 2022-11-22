#include "../inc/libmx.h"

char *mx_del_extra_whitespaces(const char *str) {
    if (!str) return NULL;
    int count_words = mx_count_words_without_delimeter(str);

    char **buff = mx_strsplit_without_delimeter(str);
    char *res = mx_concat_words(buff, count_words);

    for (int i = 0; i < count_words; i++) {
        free(buff[i]);
    }
    free(buff);
    return res;
}

// int main(void) {
//     char *str = "\f My name...  \n f gg  is  \r Neo  \t\n ";
//     char *res = mx_del_extra_whitespaces(str);
//     printf("%s\n", res);
//     free(res);
//     return 0;
// }
