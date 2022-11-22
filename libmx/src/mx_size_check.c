int mx_size_check(char **arr, int size) {
    int real_size = 0;
    for (int i = 0; arr[i]; i++) {
        real_size++;
    }
    return (real_size < size) ? 0 : 1;
}



