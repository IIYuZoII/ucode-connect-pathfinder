#include "../inc/libmx.h"

void mx_str_reverse(char *s) {
    int lenght = mx_strlen(s);

    for (int i = 0; i < lenght; i++) {
        for (int j = 0; j < lenght - i - 1; j++) {
            mx_swap_char(&s[j], &s[j + 1]);
        }
    }
}









