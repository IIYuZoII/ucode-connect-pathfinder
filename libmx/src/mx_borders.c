#include "../inc/libmx.h"

void mx_borders(const char *str, int lenght, int *left, int *right) {
    for (int i = 0; i < lenght; i++) {
        if (mx_isalpha(str[i]) || mx_isdigit(str[i])) {
            *left = i;
            break;
        }
    }
    for (int i = lenght - 1; i >= 0; i--) {
        if (mx_isalpha(str[i]) || mx_isdigit(str[i])) {
            *right = i;
            break;
        }
    }
}



