#include "../inc/libmx.h"

int mx_strncmp(const char *s1, const char *s2, size_t n) {
    int res = 0;
    for (size_t i = 0; i < n; i++) {
        if (s1[i] == '\0' || s2[i] == '\0') break;

        if (s1[i] != s2[i]) {
            res = s1[i] - s2[i];
            break;
        }
    }
    return res;
}
