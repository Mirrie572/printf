#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFF_SIZE 1024
#define UNUSED(x) (void)(x)

/* Flag values */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

int _printf(const char *format, ...);
int print_char(va_list types, char buffer[], int flags, int width,
              int precision, int size);
int print_string(va_list types, char buffer[], int flags, int width,
                int precision, int size);
int print_percent(va_list types, char buffer[], int flags, int width,
                  int precision, int size);
int print_int(va_list types, char buffer[], int flags, int width,
              int precision, int size);
int print_binary(va_list types, char buffer[], int flags, int width,
                 int precision, int size);
int print_unsigned(va_list types, char buffer[], int flags, int width,
                   int precision, int size);
int print_octal(va_list types, char buffer[], int flags, int width,
                int precision, int size);
int print_hexadecimal(va_list types, char buffer[], int flags, int width,
                      int precision, int size);
int print_hexa_upper(va_list types, char buffer[], int flags, int width,
                     int precision, int size);
int print_hexa(va_list types, char map_to[], char buffer[], int flags,
               char flag_ch, int width, int precision, int size);
int write_number(int is_negative, int ind, char buffer[], int flags,
                 int width, int precision, int size);
int write_unsgnd(int is_negative, int ind, char buffer[], int flags,
                 int width, int precision, int size);
int write_num(int ind, char buffer[], int flags, int width, int prec,
              int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length, int width,
                  int flags, char padd, char extra_c, int padd_start);
int handle_print(const char *format, int *i, va_list types, char buffer[],
                 int flags, int width, int precision, int size);
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);
unsigned long int convert_size_number(long int n, int size);
unsigned long int convert_size_unsgnd(unsigned long int n, int size);

#endif /* MAIN_H */
