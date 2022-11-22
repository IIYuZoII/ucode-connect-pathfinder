#include "../inc/libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    unsigned char *ptr1 = (unsigned char *)s;
    for (size_t i = 0; i < n; i++) {
        if (ptr1[i] == c) return (void *)&(((unsigned char *)s)[i]);
    }
    return NULL;
}

// int main(void) {
//     char *str1 = "1234567890";
//     char *str2 = "1234567890";
//     char *res1 = mx_memchr(str1, ' ', 11);
//     char *res2 = memchr(str2, ' ', 11);

//     printf("%s\n", res1);
//     printf("%s\n", res2);
//     return 0;
// }
