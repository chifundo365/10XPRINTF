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
    char *specifier;
    void (*f) (va_list, Buffer *) ;

}Specifiers;

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


typedef struct
{
    char *specifier;
    void (*f)(va_list, Flags*, Buffer*);
}Number_OP;

void (*select_number(const char *))(va_list, Flags*, Buffer*);

void insert_int(va_list, Flags*, Buffer*);
void insert_unsigned_int(va_list, Flags*, Buffer*);
void insert_hex_upper(va_list, Flags*, Buffer *);
void insert_hex_lower(va_list, Flags*, Buffer*);
void insert_octal(va_list, Flags*, Buffer*);
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
void (*select_specifier(const char *)) (va_list, Buffer *); 

/** handle strings*/
int _strlen(char *);
void print_string(va_list, Buffer *);
void print_char(va_list, Buffer *);
void print_normal_character(const char *, Buffer *);

void free_memory(Buffer *);
void print_binary(va_list, Buffer *);

void non_printable_char(va_list, Buffer *);
char *non_printable_hex(unsigned int);
void memory_address_hex(va_list, Buffer *);
#endif
