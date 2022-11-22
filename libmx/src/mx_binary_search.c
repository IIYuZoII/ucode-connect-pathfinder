#include "../inc/libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    int mid = 0;
    int left = 0;
    int right = size - 1;

    if (!mx_size_check(arr, size)) return -1;
    while (left <= right) {
        mid = (left + right) / 2;
        *count += 1;

        if (mx_strcmp(arr[mid], s) > 0) right = mid - 1;
        else if (mx_strcmp(arr[mid], s) < 0) left = mid + 1;
        else return mid;
    }
    *count = 0;
    return -1;
}

// int main(void) {
//     char *arr[] = {"22222222", "Abcd", "ab", "az", "z", "aBc"};

//     int count = 0;
//     printf("%d\n", mx_binary_search(arr, 6, "wefbwfbwf", &count));
//     printf("%d\n", count);

//     return 0;
// }
