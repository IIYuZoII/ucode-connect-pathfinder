#include "../inc/libmx.h"

void mx_printint(int n) {
    int count_digit = 0;
    int first_digit = 0;
    if (n == -2147483648) {
        mx_printstr("-2147483648");
        return;
    }
    else if (n == 0) {
        mx_printchar('0');
        return;
    }
    n = mx_normalizer(n);
    first_digit = n;
    count_digit = mx_get_count_digit(n);
    while (count_digit >= 1) {
        first_digit = n / count_digit;
        mx_printchar(first_digit + 48);
        n -= count_digit * first_digit;
        count_digit /= 10;
    }
}

// int main(void) {
//     mx_printint(12345);
//     return 0;
// }
