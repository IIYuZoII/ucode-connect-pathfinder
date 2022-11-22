#include "../inc/libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c,
                 size_t n) {
    unsigned char *ptr1 = (unsigned char *)dst;
    unsigned char *ptr2 = (unsigned char *)src;
    size_t temp = 0;
    bool is_c_found = false;
    while (temp < n) {
        ptr1[temp] = ptr2[temp];
        if (ptr2[temp] == c) {
            is_c_found = true;
            break;
        }
        temp++;
    }

    return is_c_found ? (void *)&(((unsigned char *)dst)[temp + 1]) : NULL;
}
