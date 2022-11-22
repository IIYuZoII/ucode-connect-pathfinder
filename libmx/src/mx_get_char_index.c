#include "../inc/libmx.h"

int mx_get_char_index(const char *str, char c) {
    if (!str) return -2;
    int index_res = -1;
    int len = mx_strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == c) {
            index_res = i;
            break;
        }
    }
    return index_res;
}

// int main(void) {
//     // char *str = "Aang";
//     int index = mx_get_char_index(NULL, '0');
//     printf("%d\n", index);
//     return 0;
// }
