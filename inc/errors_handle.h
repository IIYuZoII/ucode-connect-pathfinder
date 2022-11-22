#ifndef ERRORS_ENUM_H
#define ERRORS_ENUM_H

#include "../libmx/inc/libmx.h"

enum Errors {
    ERR_INVALID_NUM_OF_ARGV,
    ERR_FILE_DOESNT_EXIST,
    ERR_FILE_IS_EMPTY,
    ERR_FIRST_LINE_INVALID,
    ERR_LINE_INVALID,
    ERR_INVALID_NUM_OF_ISLANDS,
    ERR_DUPLICATE_BRIDGES,
    ERR_TOTAL_LEN_TOO_BIG
};

void error_printing_handle(int err_code, const char *filename, int line);

#endif  // ERRORS_ENUM_H
