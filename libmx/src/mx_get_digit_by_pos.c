int mx_get_digit_by_pos (int num, int repeat_count) {
    int digit;
    while (repeat_count >= 0) {
        digit = num % 10;
        num /= 10;
        repeat_count--;
    }
    return digit;
}

















