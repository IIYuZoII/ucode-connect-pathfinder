#include "../inc/libmx.h"

char *mx_strdup(const char *s1) {
    int lenght = mx_strlen(s1);
    char *str_dup = mx_strnew(lenght);

    if (str_dup == NULL) return NULL;

    return mx_strcpy(str_dup, s1);
}

// int main(void) {
//     printf("%s\n", mx_strdup("hello w"));
//     return 0;
// }
