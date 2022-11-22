#include "../inc/libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    unsigned char *ptr1 = (unsigned char *)s;
    for (int i = (int)n - 1; i >= 0; i--) {
        if (ptr1[i] == c) return (void *)&(((unsigned char *)s)[i]);
    }
    return NULL;
}

// int main(void) {
//     char *res1 = mx_memrchr("Trinity", 'T', 7);  // returns "ity"
//     printf("\n");
//     char *res2 = mx_memrchr("Trinity", 'M', 7);  // returns NULL
//     printf("\n");

//     printf("%s\n", res1);
//     printf("%s\n", res2);

//     return 0;
// }
