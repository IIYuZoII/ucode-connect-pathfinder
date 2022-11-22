#include "../inc/libmx.h"

int mx_count_words(const char *str, char c) {
    if (!str) return -1;
    bool word_started = false;
    int count = 0;
    int len = mx_strlen(str);

    for (int i = 0; i < len; i++) {
        if (str[i] == c) {
            if (word_started == true) {
                word_started = false;
                count++;
            }
        }
        if (str[i] != c) {
            if (word_started == false) {
                word_started = true;
            }
        }
    }
    if (word_started == true) count++;
    return count;
}

// int main(void) {
//     printf("%d\n", mx_count_words("  follow  *  the  white  rabbit ", ' ')); //5
//     return 0;
// }


