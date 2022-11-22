#include "../inc/libmx.h"

int mx_normalizer(int n) {
    if (n < 0) {
        mx_printchar('-');
        return -n;
    }
    else {
        return n;
    }
}



