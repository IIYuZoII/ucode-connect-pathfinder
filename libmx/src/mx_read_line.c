#include "../inc/libmx.h"



int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    int count_bytes = 0;
    char *buff_big = NULL;
    int status_of_reading = 0;

    if (buf_size < 6) buf_size = 6;

    while (true) {
        char *buff_small = (char *)malloc(sizeof(char) * buf_size);
        char *temp = buff_big;
        status_of_reading = read(fd, buff_small, buf_size);
        if (status_of_reading < 0) return -2;

        if (mx_strchr(buff_small, delim) != NULL) {
            char *temp_dup = mx_duplicate_str_before_chr(buff_small, delim);
            buff_big = mx_strjoin(buff_big, temp_dup);
            count_bytes += mx_strlen(temp_dup);
            free(temp_dup);
            free(temp);
            free(buff_small);
            break;
        }
        else {
            buff_big = mx_strjoin(buff_big, buff_small);
            count_bytes += buf_size;
        }
        if (status_of_reading == 0) {
            free(buff_big);
            free(temp);
            free(buff_small);
            return -1;
        }
        if (temp) free(temp);
        free(buff_small);
    }

    if (malloc_size(*lineptr) < (size_t)count_bytes) {
        *lineptr = mx_realloc(*lineptr, count_bytes);
    }

    mx_strcpy(*lineptr, buff_big);
    free(buff_big);
    return count_bytes;
}


// int main(void) {
//     int fd = open("../text.txt", O_RDONLY);
//     char *str = (char *)malloc(sizeof(char) * 10);
//     int res = mx_read_line(&str, 50, '0', fd);
//     printf("Res is: %d\n\n", res);
//     printf("Str is:\n%s\n", str);
//     free(str);
//     return 0;
// }
