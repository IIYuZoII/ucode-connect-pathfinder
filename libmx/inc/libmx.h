#ifndef LIBMX_H
#define LIBMX_H

#ifdef __APPLE__
#include <malloc/malloc.h>
#endif  //__APPLE__

#ifdef __linux__
#include <malloc.h>
#define malloc_size malloc_usable_size
#endif  //__linux__

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include <stdbool.h>
#include <fcntl.h>
#include <string.h>

// Act: Utils Pack
int mx_count_digits_in_int(int num);                 // own
int mx_get_digit_by_pos(int num, int repeat_count);  // own
int mx_normalizer(int n);                            // own
int mx_get_count_digit(int n);                       // own
int mx_size_check(char **arr, int size);             // own
void mx_printerr(const char *s);                     // own
int mx_atoi(const char *str);                        // own

void mx_printchar(char c);                                              // pdf
char *mx_itoa(int number);                                              // pdf
void mx_printstr(const char *s);                                        // pdf
void mx_printint(int n);                                                // pdf
double mx_pow(double n, unsigned int pow);                              // pdf
int mx_sqrt(int x);                                                     // pdf
char *mx_nbr_to_hex(unsigned long nbr);                                 // pdf
unsigned long mx_hex_to_nbr(const char *hex);                           // pdf
void mx_foreach(const int *arr, int size, void (*f)(int));              // pdf
int mx_binary_search(char **arr, int size, const char *s, int *count);  // pdf

// Act: String Pack
void mx_swap_str(char **a, char **b);                                 // own
bool mx_isalpha(int c);                                               // own
bool mx_isdigit(int c);                                               // own
bool mx_islower(int c);                                               // own
bool mx_isupper(int c);                                               // own
bool mx_isspace(char c);                                              // own
void mx_borders(const char *str, int lenght, int *left, int *right);  // own
int mx_count_words_without_delimeter(const char *str);                // own
char *mx_concat_words(char **words, unsigned int count_words);        // own
char **mx_strsplit_without_delimeter(const char *str);                // own
char *mx_duplicate_str_before_sub(const char *str, const char *sub);  // own
char *mx_duplicate_str_before_chr(const char *str, const char chr);   // own
int mx_strncmp(const char *s1, const char *s2, size_t n);             // own

int mx_strcmp(const char *s1, const char *s2);                // pdf
int mx_strlen(const char *s);                                 // pdf
int mx_get_char_index(const char *str, char c);               // pdf
void mx_swap_char(char *s1, char *s2);                        // pdf
void mx_str_reverse(char *s);                                 // pdf
void mx_strdel(char **str);                                   // pdf
void mx_del_strarr(char ***arr);                              // pdf
char *mx_strnew(const int size);                              // pdf
char *mx_strcpy(char *dst, const char *src);                  // pdf
char *mx_strncpy(char *dst, const char *src, int len);        // pdf
char *mx_strdup(const char *s1);                              // pdf
char *mx_strndup(const char *s1, size_t n);                   // pdf
char *mx_strcat(char *restrict s1, const char *restrict s2);  // pdf
char *mx_strchr(const char *s, int c);                        // pdf
char *mx_strstr(const char *haystack, const char *needle);    // pdf
int mx_count_substr(char *str, const char *sub);              // pdf
int mx_count_words(const char *str, char c);                  // pdf
char *mx_strtrim(const char *str);                            // pdf
char *mx_del_extra_whitespaces(const char *str);              // pdf
char **mx_strsplit(char const *s, char c);                    // pdf
char *mx_strjoin(char const *s1, char const *s2);             // pdf
char *mx_file_to_str(const char *filename);                   // pdf
int mx_read_line(char **lineptr, size_t buf_size, char delim,
                 const int fd);  // pdf

// Act: Memory Pack
void *mx_memset(void *b, int c, size_t len);                              // pdf
void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n);  // pdf
void *mx_memccpy(void *restrict dst, const void *restrict src, int c,
                 size_t n);                               // pdf
int mx_memcmp(const void *s1, const void *s2, size_t n);  // pdf
void *mx_memchr(const void *s, int c, size_t n);          // pdf
void *mx_memrchr(const void *s, int c, size_t n);         // pdf
void *mx_memmem(const void *big, size_t big_len, const void *little,
                size_t little_len);                        // pdf
void *mx_memmove(void *dst, const void *src, size_t len);  // pdf
void *mx_realloc(void *ptr, size_t size);                  // pdf

// Act: List Pack
typedef struct s_list {
    void *data;
    struct s_list *next;
} t_list;

t_list *mx_create_node(void *data);                                 // pdf
void mx_push_front(t_list **list, void *data);                      // pdf
void mx_push_back(t_list **list, void *data);                       // pdf
void mx_pop_front(t_list **head);                                   // pdf
void mx_pop_back(t_list **head);                                    // pdf
int mx_list_size(t_list *list);                                     // pdf
t_list *mx_sort_list(t_list *list, bool (*cmp)(void *a, void *b));  // pdf

#endif  // LIBMX_H
