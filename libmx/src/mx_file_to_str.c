#include "../inc/libmx.h"

char *mx_file_to_str(const char *filename) {
    if (filename == NULL) return NULL;
    char buff;
    char *str_res = NULL;
    int lenght = 0;
    int fd = open(filename, O_RDONLY);
    
    if (fd == -1) return NULL;
    while (read(fd, &buff, 1) > 0) lenght++;
    if (close(fd) == -1) return NULL;

    fd = open(filename, O_RDONLY);
    if (fd == -1) return NULL;
    str_res = mx_strnew(lenght);

    for (int i = 0; i < lenght; i++) {
        read(fd, &buff, 1);
        str_res[i] = buff;
    }
    if (close(fd) == -1) return NULL;
    return str_res;
}




// int main(int argc, char const *argv[]) {
//     if (argc) {}
//     printf("%s\n", mx_file_to_str(argv[1]));
//     return 0;
// }


