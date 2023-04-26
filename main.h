# ifndef MAIN_H
# define MAIN_H
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define BUFFER_SIZE 1024
/**
 * struct format - struct type
 * @c: member
 * @ptr: function pointer
 */
typedef struct format
{
	char c;
	int (*ptr)(va_list args, int flags, int width, int precision, int size);
} _fmt;
int calc_flags(const char *format, int *i);
int _print(int c);
int _strlen(char *s);
int _printmod(va_list args, int flags,
		int width, int precision, int size);
int _printstr(char *s);
int _print_int(int n);
int _print_Uint(unsigned int n);
int _printint(va_list args, int flags, int width, int precision, int size);
int _printUint(va_list args, int flags, int width, int precision, int size);
int _printbinary(int n);
int _binaryT(va_list args, int flags, int width, int precision, int size);
int _print_octal(unsigned int n);
int _printoctal(va_list args, int flags, int width, int precision, int size);
int _printptr(va_list args, int flags, int width, int precision, int size);
int _print_hex1(va_list args, int flags, int width, int precision, int size);
int _print_hexUpper(va_list args,
		int flags, int width, int precision, int size);
int charhandler(va_list args, int flags, int width, int precision, int size);
int strhandler(va_list args, int flags, int width, int precision, int size);
int hexUpper(unsigned int num);
int _printf(const char *format, ...);
int printhandler(va_list args, const char *format,
		int i, int flags, int width, int precision, int size);
void print_buffer(char buffer[], int *buff_ind);
int _nonprinthandler(va_list args,
		int flags, int width, int precision, int size);
int __nonprintchars(char *s);
int reverse(va_list args, int flags, int width, int precision, int size);
int rot13(va_list args, int flags, int width, int precision, int size);
# endif
