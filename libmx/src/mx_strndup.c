#include "../inc/libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    char *str_dup = mx_strnew(n);

    if (str_dup == NULL) return NULL;

    return mx_strncpy(str_dup, s1, n);
}
