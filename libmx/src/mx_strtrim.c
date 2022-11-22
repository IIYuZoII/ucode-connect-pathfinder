#include "../inc/libmx.h"



char *mx_strtrim(const char *str) {
    if (str == NULL) return NULL;

    char *res = NULL;
    int lenght = mx_strlen(str);
    int left = 0;
    int right = 0;

    mx_borders(str, lenght, &left, &right);
    lenght -= left + (lenght - right);

    res = mx_strnew(lenght + 1);
    res = mx_strncpy(res, &str[left], lenght + 1);
    return res;
}

// int main(void) {
//     char *str = "\fMy name... is Neo\t\n ";
//     // char *str = "\f My name...    is  \r Neo  \t\n ";
//     // char *str = "\0\0\0";
//     char *res;
//     res = mx_strtrim(str);
//     printf("%s\n", res);

//     free(res);

//     return 0;
// }
