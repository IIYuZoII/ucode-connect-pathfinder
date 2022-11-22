int mx_count_digits_in_int(int num) {
    int count = 0;
    if (num == 0) return 1;
    while (num != 0) {
        num /= 10;
        count++;
    }
    return count;
}





