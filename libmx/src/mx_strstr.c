#include "../inc/libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    int len_input = mx_strlen(haystack);

    for (int i = 0; i < len_input; i++) {
        if (mx_strcmp(haystack, needle) == 0) return (char *)haystack;
        haystack++;
    }

    return NULL;
}

// #include <string.h>
// int main(void) {
//     char text[] = "  I'm The 101 tHe the best";
//     char find[] = "101";

//     printf("%s\n", mx_strstr(text, find)); //my
//     printf("--------------\n");
//     printf("%s\n", strstr(text, find)); //original

//     return 0;
// }
