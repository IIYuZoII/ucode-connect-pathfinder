#include "../inc/libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    char *buff = mx_strndup(src, len);
    mx_memcpy(dst, buff, len);
    free(buff);
    return dst;
}

// int main(void) {
//     char *res = (char *)malloc(sizeof(char) * 11);
//     mx_memmove(res, "1234567890", 3);
//     printf("%s\n", res);
//     free(res);
//     return 0;
// }
