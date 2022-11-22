#include "../inc/libmx.h"

char **mx_strsplit_without_delimeter(const char *str) {
    if (!str) return NULL;
    int len_str = mx_strlen(str);
    int count_words = mx_count_words_without_delimeter(str);
    char **buff = (char **)malloc(sizeof(char *) * count_words);

    for (int i = 0; i < count_words; i++) {
        buff[i] = mx_strnew(len_str);
    }

    int index_words = 0;
    int index_characters = 0;
    bool word_started = false;

    for (int i = 0; i < len_str; i++) {
        if (mx_isspace(str[i]) && word_started == true) {
            word_started = false;
            index_words++;
            index_characters = 0;
        }
        if (!mx_isspace(str[i])) {
            word_started = true;
            buff[index_words][index_characters++] = str[i];
        }
    }

    return buff;
}

