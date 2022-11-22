#include "../inc/libmx.h"

char *mx_itoa(int number) {
    size_t length = mx_count_digits_in_int(number);
    char *res = NULL;
    int stop = 0;
    int temp = 0;

    if (number < 0) {
        res = malloc(sizeof(char) * length++ + 1);
        if (number == -2147483648) {
            mx_strcpy(res, "-2147483648");
            return res;
        }
        res[stop++] = '-';
        number *= -1;
    } else {
        res = malloc(sizeof(char) * length);
    }

    for (int i = length - 1; i >= stop; i--) {
        res[i] = mx_get_digit_by_pos(number, temp++) + '0';
    }
    return res;
}

// int main(void) {
//     char *ptr = mx_itoa(1);
//     printf("%s\n", ptr);
//     return 0;
// }
