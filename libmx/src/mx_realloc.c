#include "../inc/libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    if (ptr != NULL) {
        int current_len = malloc_size(ptr);
        if (size == 0) {
            free(ptr);
            return NULL;
        }
        else {
            void *new_ptr = malloc(size);
            mx_memcpy(new_ptr, ptr, current_len);
            free(ptr);
            return new_ptr;
        }
    }
    else {
        void *new_ptr = malloc(size);
        return new_ptr;
    }
}

// int main(void) {
//     int *arr = (int *)malloc(sizeof(int) * 100);
//     for (int i = 0; i < 5; i++) {
//         arr[i] = i;
//     }

//     printf("%zu\n", malloc_size(arr));
//     arr = realloc(arr, sizeof(int) * 10);
//     printf("%zu\n", malloc_size(arr));
//     return 0;
// }
