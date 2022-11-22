#include "../inc/libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    unsigned char *ptr1 = (unsigned char *)s1;
    unsigned char *ptr2 = (unsigned char *)s2;
    return mx_strncmp((const char *)ptr1, (const char *)ptr2, n);
}

// int main(void) {
//     char *str1 = "4abc";
//     char *str2 = "abc";

//     printf("%d\n", mx_memcmp(str1, str2, 3));
//     printf("%d\n", memcmp(str1, str2, 3));
//     return 0;
// }
