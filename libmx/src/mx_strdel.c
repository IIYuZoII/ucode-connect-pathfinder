#include "../inc/libmx.h"

void mx_strdel(char **str) {
    free(*str);
    *str = NULL;
}

// int main(void) {
//     char *str = NULL;
//     str = malloc(15);

//     if (str != NULL) {
//         printf("%s\n", "case#0");
//     }

//     mx_strdel(&str);

//     if (str == NULL) {
//         printf("%s\n", "case#1");
//     }

//     return 0;
// }
