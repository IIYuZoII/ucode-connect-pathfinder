#include "../inc/libmx.h"

bool mx_isspace(char c) {
    if (c == ' ' 
        || c == '\f' 
        || c == '\n' 
        || c == '\r' 
        || c == '\t' 
        || c == '\v') {
        return true;
    }
    return false;
}








