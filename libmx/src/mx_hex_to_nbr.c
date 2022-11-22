#include "../inc/libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
    if (!hex) return 0;
    unsigned long decimal = 0;
    unsigned long base = 1;
    int i = 0;
    int length = mx_strlen(hex);
    for (i = length--; i >= 0; i--) {
        if (mx_isdigit(hex[i])) {
            decimal += (hex[i] - 48) * base;
            base *= 16;
        }
        else if (mx_isupper(hex[i])) {
            decimal += (hex[i] - 55) * base;
            base *= 16;
        }
        else if (mx_islower(hex[i])) {
            decimal += (hex[i] - 87) * base;
            base *= 16;
        }
    }
    return decimal;
}

// int main(void) {
//     char hex[] = "FFFFFFFFFFFF";
//     // char hex[] = "1";
//     printf("%s\n", hex);
//     unsigned long num = mx_hex_to_nbr(NULL);
//     printf("%lu\n", num);
//     return 0;
// }
