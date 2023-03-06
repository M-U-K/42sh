/*
** EPITECH PROJECT, 2019
** Librairy
** File description:
** utils.h
*/

#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>

#ifndef READ_SIZE
#define READ_SIZE 9
#endif

/*  Read a file with stat()

Return a string with the content in success
Return NULL in error */
char *read_stat_file(char const *filename);

/*  read a file with read()

Return a string with the content in success
Return NULL in error */
char *read_read_file(char const *filename);

/*  Return the next line as string of the given file descriptor */
char *get_next_line(int fd);

/* Return the lenght to given character end of the given string

If a NULL pointer is give, 0 is return */
int string_len(char const *str, char end);

/* Return the lenght of the table given as argument

If a NULL pointer is give, 0 is return */
int table_len(char * const *tab);

/* Realloc a string given as argument with the size also given

If rewrite is true, the lenght of the given string is not take to realloc
If rewrite is false, the given size is added to
the lenght of the given string

my_realloc create a new string, so if you want free
the given string set want_free to true */
char *my_realloc(char *str, int size, bool rewrite, bool want_free);

/* Print the string given as argument in the error output */
void print_error(char const *error);

/* Check if the given character c is in the given string str*/
bool is_in_string(char c, char const *str);

/* Remove all character, of the given string del, in the given string str

str_clear create a new string, so if you want free
the given string str set want_free to true */
char *str_clear(char *str, char const *del, bool want_free);

/* Return an int containing the POSITIVE number in the given string str

Make a string with the number nb given as argument */
char *get_integer_nbr(int nb);

/* Return true if the given string contain a POSTIVE number
, else false is return */
bool is_a_number(char const *str);

/* Return 1 if the given string is true, 0 if is false
In case of error return -1 */
int is_boolean(char const *value);

/* Print the string given as argument in the standard output */
void print_string(char const *str);

/* Concat the given arguments like the given format

Replace :
%i for an int
%c for a character
%s for a string */
char *concat_fstring(char *format, ...);

/* Duplicate the given string */
char *string_dup(char const *src);

/* Duplicate the given table*/
char **table_dup(char * const *tab);

/* Compare the given strings */
int cmp_string(char const *s1, char const *s2);

/* Compare the given strings without comparing upper / lower character */
int cmp_string_alpha(char const *s1, char const *s2);

/* Search the given occurence to_find in the given string str

Return an int who indicate the begining of
to_find in str or -1 if to_find is not find in str */
int search_n_occurence(char const *str, char const *to_find, int n);

/* Splits the given string str in table
The separator are specified in the given string sep */
char **str_to_tab(char const *str, char const *sep);

/* Concat all string of the given table in a sigle string */
char *tab_to_str(char * const *tab);

/* Add in last the given string str in the given table tab */
char **tab_append(char **tab, char *str);

/* Remove the string to n place in the given table tab */
char **tab_suppress(char **tab, int n);

/* Free the given table tab */
void free_tab(char **tab);

/* Check if the given string str is only composed of alpha numeric character
The exception are specified in the given string except */
bool is_alpha_num(char *str, char *except);

/* Check if the given string str is only composed of alpha character
The exception are specified in the given string except */
bool is_alpha(char *str, char *except);

/* Check if the given string str is only composed of upper alpha character
The exception are specified in the given string except */
bool is_alpha_upp(char *str, char *except);

/* Check if the given string str is only composed of lower alpha character
The exception are specified in the given string except */
bool is_alpha_low(char *str, char *except);

/* Check if the given string str is only composed of numeric character
The exception are specified in the given string except */
bool is_num(char *str, char *except);

/* Sort the given table word_list depending of there alpha character */
char **sort_word(char **word_list);

/* Transform the given string str in an integer who returned */
int get_number(char const *str);

/* Reverse the given string str */
char *reverse_string(char *str);

/* Make all the first letters of each words
in the given string str in uppercase
and all other letters in lowercase */
char *capitalize_string(char *str);

/* Make all letters in uppercases */
char *upcase_string(char *str);

/* Make all letters in lowercase */
char *lowcase_string(char *str);

#endif