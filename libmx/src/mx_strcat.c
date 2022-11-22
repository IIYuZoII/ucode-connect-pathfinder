#include "../inc/libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2) {
    int dest_len = mx_strlen(s1);
    int src_len = mx_strlen(s2);
    int i;

    for (i = 0; i < src_len && s2[i] != '\0'; i++) {
        s1[dest_len + i] = s2[i];
    }

    s1[dest_len + i] = '\0';

    return s1;
}

// int main(void){
//     char s1[] = "lol ";
//     char s2[] = "kek";
//     printf("%s", mx_strcat(s1, s2));
// }
