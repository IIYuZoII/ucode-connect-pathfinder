#include "../inc/libmx.h"

void mx_print_strarr(char **arr, const char *delim) {
    if (!arr || !*arr || !delim) return;
    for (int i = 0; arr[i]; i++) {
        mx_printstr(arr[i]);
        if (arr[i + 1]) {
            mx_printstr(delim);
        }
    }
    mx_printchar('\n');
}

// int main(void) {
//     char *str[] = {"first", "second", "third", NULL};
//     mx_print_strarr(str, "1111");
//     return 0;
// }


