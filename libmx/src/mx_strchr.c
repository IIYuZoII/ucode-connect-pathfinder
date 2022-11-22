#include "../inc/libmx.h"

char *mx_strchr(const char *s, int c) {
    if (c == '\0') {
        while (1){
            if (*s == c){
                return (char*)s;
            }
            s++;
        }
    }
    else {
        while (*s != '\0'){
            if (*s == c){
                return (char*)s;
            }
            s++;
        }
    }

    return NULL;
}























