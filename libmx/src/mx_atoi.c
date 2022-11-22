#include "../inc/libmx.h"

int mx_atoi(const char *str) {
    int num = 0;
    int minus_check = false;
    int space_check = false;
    int digit_check = false;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!mx_isdigit(str[i]) && !mx_isspace(str[i])) {
            if (str[i] == '-' && mx_isdigit(str[i + 1])) {
                minus_check = true;
                continue;
            }
            break;
        }

        if (mx_isspace(str[i]) && space_check == false) {
            space_check = 1;
            continue;
        }
        else if (mx_isspace(str[i]) && space_check == true) {
            if (digit_check == false) {
                continue;
            }
            else {
                break;
            }
        }

        if (mx_isdigit(str[i])) {
            digit_check = true;
            num *= 10;
            num += str[i] - 48;
        }
    }

    if (minus_check == false) {
        return num;
    }
    else {
        return -num;
    }
}

// int main(void){
//     printf("%d\n", atoi("-449529731")); //original func
//     printf("%d\n", mx_atoi("-449529731")); //myfunc
//     return 0;
// }
