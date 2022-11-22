#include "../inc/libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    if (!str || !sub) return -2;

    int index_res = -1;
    int len_str = mx_strlen(str);
    const char *temp = str;

    for (int i = 0; i < len_str; i++) {
        if (mx_strcmp(temp, sub) == 0) {
            index_res = i;
            break;
        }
        temp++;
    }

    return index_res;
}

// int main(void) {
//     char *str = "Hello World!";
//     char *sub = "World";
//     int index = 0;
//     index = mx_get_substr_index(str, sub);  // returns 6
//     printf("%d\n", index);
//     index = mx_get_substr_index(str, "doesn't exist");  // returns -1
//     printf("%d\n", index);
//     index = mx_get_substr_index(NULL, sub);  // returns -2
//     printf("%d\n", index);
//     index = mx_get_substr_index(str, NULL);  // returns -2
//     printf("%d\n", index);
//     return 0;
// }
