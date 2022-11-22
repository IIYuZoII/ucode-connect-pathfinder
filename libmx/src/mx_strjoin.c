#include "../inc/libmx.h"

char *mx_strjoin(char const *s1, char const *s2) {
    char *str = NULL;
    if (s1 == NULL && s2 == NULL) return NULL;
    if (s1 == NULL) return mx_strdup(s2);
    if (s2 == NULL) return mx_strdup(s1);

    str = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
    mx_strcpy(str, s1);
    mx_strcat(str, s2);
    return str;
}

// int main(void) {
//     char *res = mx_strjoin("Hello!", NULL);
//     printf("%s\n", res);
//     free(res);
//     return 0;
// }
