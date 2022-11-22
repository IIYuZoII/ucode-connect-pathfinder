#include "../inc/libmx.h"

int mx_count_substr(char *str, const char *sub) {
    if (!str || !sub) return -1;

    int count = 0;
    int len_sub = mx_strlen(sub);
    char *temp = str;

    while (1) {
        if ((temp = mx_strstr(temp, sub)) != NULL) {
            temp += len_sub;
            count++;
        }
        else {
            break;
        }
    }

    return count;
}

// int main(void) {
//     char text[] = "yo, yo, yo Neo yo";
//     char find[] = "o";

    // printf("%d\n", mx_count_substr(text, find));

//     return 0;
// }
