#include "../inc/libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    char *hex_string_res = NULL;
    char hex_string_temp[100];
    int i = 1;
    int len = 0;

    if (nbr == 0) return "0";

    while (nbr != 0) {
        int temp = nbr % 16;
        if (temp < 10) temp += '0';
        else temp += 87;
        hex_string_temp[i++] = temp;
        nbr /= 16;
    }

    len = i--;
    hex_string_res = mx_strnew(len--);

    for (int j = 0; j < len; j++) {
        hex_string_res[j] = hex_string_temp[i--];
    }

    return hex_string_res;
}










