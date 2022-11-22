#include "../inc/libmx.h"


int mx_quicksort(char **arr, int left, int right) {
    static int res = 0;
    int left_index = left;
    int right_index = right;
    char *piv = arr[(left + right) / 2];

    if (left >= right) return res;

    while (left_index < right_index) {
        while (mx_strlen(arr[left_index]) < mx_strlen(piv)) left_index++;
        while (mx_strlen(piv) < mx_strlen(arr[right_index])) right_index--;
        if (left_index <= right_index) {
            if (mx_strlen(arr[left_index]) != mx_strlen(arr[right_index])) {
                mx_swap_str(&arr[left_index], &arr[right_index]);
                res++;
            }
            left_index++;
            right_index--;
        }
    }
    mx_quicksort(arr, left, right_index);
    mx_quicksort(arr, left_index, right);
    return res;
}

// // #include <stdio.h>
// int main() {
//     // int arr[] = {4, 3, 5, 2, 1, 3, 2, 3};
//     char *str[] = {"123", "12345", "1", "15", "14", "124", "1234", "12"};
//     int left = 0;
//     int right = 8;
//     int count = 0;
//     // count = qsort(str, left, right - 1);
//     count = mx_quicksort(str, left, right - 1);
//     for (int i = 0; i < right; i++) {
//         printf("%s\n", str[i]);
//     }
//     printf("\n");
//     printf("count is:  %d\n", count);
//     return 0;
// }
