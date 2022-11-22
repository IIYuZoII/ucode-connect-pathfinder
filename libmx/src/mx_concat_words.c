#include "../inc/libmx.h"

static int calc_total_len(char **words, unsigned int count_words) {
    int total_lenght = 0;

    for (unsigned int i = 0; i < count_words; i++) {
        total_lenght += mx_strlen(words[i]) + 1;
    }

    return total_lenght - 1;
}

char *mx_concat_words(char **words, unsigned int count_words) {
    if (words == NULL) return NULL;

    int total_len = calc_total_len(words, count_words);
    char *str = mx_strnew(total_len);

    for (unsigned int i = 0; i < count_words; i++) {
        mx_strcat(str, words[i]);
        if (i + 1 < count_words) {
            mx_strcat(str, " ");
        }
    }

    return str;
}

// int main(void) {
//     char *string[] = {"Free", "your", "mind.", "wfwefwefwefweeff",
//     "wfwefwefwefweeff","wfwefwefwefweeff",
//     "wfwefwefwefweeff","wfwefwefwefweeff", "wfwefwefwefweeff", NULL};

//     char *str;
//     str = mx_concat_words(string);

//     if (str == NULL) {printf("%s\n", "text");}

//     printf("%s\n", str);

//     free(str);

//     return 0;

// }
