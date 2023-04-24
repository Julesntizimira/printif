# ifndef MAIN_H
# define MAIN_H
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024
/**
 * struct format - struct type
 * @c: member
 * @ptr: function pointer
 */
typedef struct format
{
	char c;
	int (*ptr)(va_list args);
} _fmt;

int _print(int c);
int _printmod(va_list args);
int _printstr(char *s);
int _print_int(int n);
int _print_Uint(unsigned int n);
int _printint(va_list args);
int _printUint(va_list args);
int _printbinary(int n);
int _binaryT(va_list args);
int _print_octal(unsigned int n);
int _printoctal(va_list args);
int _print_hex(va_list args);
int _print_hexUpper(va_list args);
int charhandler(va_list args);
int strhandler(va_list args);
int hexUpper(int num);
int _printf(const char *format, ...);
int printhandler(va_list args, const char *format, int i);
void print_buffer(char buffer[], int *buff_ind);
int _nonprinthandler(va_list args);
int __nonprintchars(char *s);
# endif
