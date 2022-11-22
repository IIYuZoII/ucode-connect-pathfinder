int mx_get_count_digit(int n) {
    int count_digit = 1;

    while (n > 0) {
        if (count_digit == 1000000000) return count_digit;
        count_digit *= 10;
        n /= 10;
    }
    return count_digit / 10;
}




