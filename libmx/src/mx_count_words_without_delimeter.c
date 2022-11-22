#include "../inc/libmx.h"

int mx_count_words_without_delimeter(const char *str) {
    if (!str) return -1;
    bool word_started = false;
    int count = 0;
    int len = mx_strlen(str);

    for (int i = 0; i < len; i++) {
        if (mx_isspace(str[i]) && word_started == true) {
            word_started = false;
            count++;
        }
        else if (!mx_isspace(str[i]) && word_started == false) {
            word_started = true;
        }
    }
    if (word_started == true) count++;
    return count;
}

// int main(void) {
//     printf("%d\n", mx_count_words_without_delimeter("\f ff fff\n g"));
//     return 0;
// }
