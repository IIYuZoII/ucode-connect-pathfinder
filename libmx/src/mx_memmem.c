#include "../inc/libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little,
                size_t little_len) {
    char *ptr1 = (char *)big;
    char *buff_little = mx_strndup(little, little_len);
    for (size_t i = 0; i < big_len; i++) {
        if (mx_strcmp(ptr1, little) == 0) {
            free(buff_little);
            return (void *)ptr1;
        }
        ptr1++;
    }
    free(buff_little);
    return NULL;
}

// int main(void) {
//     char *big = mx_strdup("1234567890");
//     char *little = mx_strdup("56");
//     size_t len_big = mx_strlen(big);
//     size_t len_little = mx_strlen(little);

//     char *res = mx_memmem(big, len_big, little, len_little);
//     printf("%s\n", res);

//     free(big);
//     free(little);
//     return 0;
// }
