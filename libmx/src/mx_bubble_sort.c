#include "../inc/libmx.h"

int mx_bubble_sort(char **arr, int size) {
    int count = 0;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (mx_strcmp(arr[j], arr[j + 1]) > 0) {
                char *ptr = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = ptr;
                count++;
            }
        }
    }
    return count;
}

// int main(void) {

//     char *arr[] = {"abc", "xyz", "ghi", "def"};
//     int a = mx_bubble_sort(arr, 4);
//     printf("%d\n", a);

//     char *arr1[] = {"abc", "acb", "a"};
//     a = mx_bubble_sort(arr1, 3);
//     printf("%d\n", a);

//     return 0;
// }
