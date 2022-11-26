#include "../inc/errors_handle.h"
#include "../inc/pathfinder.h"

void error_printing_handle(int err_code, const char *filename, int line) {
    switch (err_code) {
        case ERR_INVALID_NUM_OF_ARGV:  // done; no leaks
            mx_printerr("usage: ./pathfinder [filename]\n");
            exit(EXIT_FAILURE);
        case ERR_FILE_DOESNT_EXIST: // done; no leaks
            mx_printerr("error: file ");
            mx_printerr(filename);
            mx_printerr(" does not exist\n");
            exit(EXIT_FAILURE);
        case ERR_FILE_IS_EMPTY:  // done; no leaks
            mx_printerr("error: file ");
            mx_printerr(filename);
            mx_printerr(" is empty\n");
            exit(EXIT_FAILURE);
        case ERR_FIRST_LINE_INVALID:  // done
            mx_printerr("error: line 1 is not valid\n");
            exit(EXIT_FAILURE);
        case ERR_LINE_INVALID: // done; no leaks
            mx_printerr("error: line ");
            print_num_to_errout(line);
            mx_printerr(" is not valid\n");
            exit(EXIT_FAILURE);
        case ERR_INVALID_NUM_OF_ISLANDS: // done; no leaks
            mx_printerr("error: invalid number of islands\n");
            exit(EXIT_FAILURE);
        case ERR_DUPLICATE_BRIDGES: // done; no leaks
            mx_printerr("error: duplicate bridges\n");
            exit(EXIT_FAILURE);
        case ERR_TOTAL_LEN_TOO_BIG: // done; no leaks
            mx_printerr("error: sum of bridges lengths is too big\n");
            exit(EXIT_FAILURE);
        default:
            break;
    }
}
