#include "../inc/libmx.h"

char **mx_strsplit(char const *s, char c) {
    if (!s) return NULL;
    int len_str = mx_strlen(s);
    int count_words = mx_count_words(s, c);
    char **buff = (char **)malloc(sizeof(char *) * count_words + 1);
    buff[0] = NULL;
    for (int i = 0; i < count_words; i++) {
        buff[i] = mx_strnew(len_str);
    }

    int index_words = 0;
    int index_characters = 0;
    bool word_started = false;

    for (int i = 0; i < len_str; i++) {
        if (s[i] == c && word_started == true) {
            word_started = false;
            index_words++;
            index_characters = 0;
        }
        if (s[i] != c) {
            word_started = true;
            buff[index_words][index_characters++] = s[i];
        }
    }

    return buff;
}

// int main(void) {
//     // char *str = "**Good bye,**Mr.*Anderson.****";
//     char *str = "         Knock,    knock,    Neo.   ";
//     char **res = mx_strsplit(str, ' ');
//     for (int i = 0; i < 3; i++) {
//         printf("%s\n", res[i]);
//     }

//     for (int i = 0; i < 3; i++) {
//         free(res[i]);
//     }
//     free(res);
//     return 0;
// }
