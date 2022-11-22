#include "../inc/pathfinder.h"

long int long_atoi(const char *str) {
    long num = 0;
    int len = mx_strlen(str);
    int arr[len];

    for (int i = 0; i < len; i++) {
        arr[i] = str[i] - '0';
    }

    long temp = 1;
    for (int i = len - 1; i >= 0; i--) {
        num += arr[i] * temp;
        temp *= 10;
    }

    return num;
}

