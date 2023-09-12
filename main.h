#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct
{
	int length;
	char *buffer_space;
	int position;
	int arg;
}Buffer;

typedef struct
{
	int width;
	int zero_flag;
	int format_position;
	int minus;

}Width_Opt;

typedef struct
{
	int size;
	int format_position;
}Precision;


typedef struct 
{
	char *specifier;
	void (*f) (va_list, Width_Opt*, Precision*, Buffer *) ;

}Specifiers;

typedef struct
{
	char *specifier;
	void (*f) (va_list, Buffer*);
}Custom_Specs;

typedef struct
{
	int h;
	int l;

}Length_Mod;

typedef struct
{
	char *flg;
	char *hex_upper;
	char *hex_lower;
	char *octal;
	int space;
	Length_Mod length_modifier;

}Flags;


void precision_options(const char*, Precision*, Width_Opt*,  va_list);

typedef struct
{
	char *specifier;
	void (*f)(va_list, Flags*, Width_Opt*, Buffer*);
}Number_OP;

/*handle width */


void width_options(const char *, va_list, Width_Opt*); 

void (*select_number(const char *))(va_list, Flags*, Width_Opt*, Buffer*);

/* number specifiers functions*/
void insert_int(va_list, Flags*, Width_Opt*, Buffer*);
void insert_unsigned_int(va_list, Flags*, Width_Opt*, Buffer*);
void insert_hex_upper(va_list, Flags*, Width_Opt*, Buffer*);
void insert_hex_lower(va_list, Flags*, Width_Opt*, Buffer*);
void insert_octal(va_list, Flags*, Width_Opt*, Buffer*);
typedef struct
{
	char *flag;
	void(*f)(Flags *);
}Flag_Op;

void (*select_flag(const char *)) (Flags *flag);
void plus_flag(Flags *);
void hash_flag(Flags *);
void space_flag(Flags *);

/* length modifiers functions will be selected by select flag function*/
void h_length_modifier(Flags*);
void l_length_modifier(Flags*);

void _putchar(Buffer *);
int _printf(const char *, ...);
Buffer *init_buffer(size_t);
int start_printf(va_list, const char *, Buffer*);
void (*select_specifier(const char *)) (va_list, Width_Opt*, Precision*, Buffer *); 
void (*custom_specifier_selecter(const char*))(va_list, Buffer*);
/** handle strings*/
int _strlen(char *);
void print_string(va_list, Width_Opt*, Precision*, Buffer*);
void print_char(va_list, Width_Opt*, Precision*, Buffer*);
void print_normal_character(const char *, Buffer*);

/* handle memory */
void insert_into_buffer(Buffer*, char);
Flags *init_flags(void);
Width_Opt *init_width(void);
Precision *init_precision(void);
void free_buffer(Buffer *);
void free_options(Flags*, Width_Opt*, Precision*);


void print_binary(va_list, Buffer *);

void non_printable_char(va_list, Buffer *);
char *non_printable_hex(unsigned int);
void memory_address_hex(va_list, Flags*, Width_Opt*, Buffer*);
#endif
