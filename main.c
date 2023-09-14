#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
     char *s = malloc(10);
     unsigned int n = 355544;
     _printf("%20ome\n", n);
      printf("%20ome\n", n);


     _printf("address: ++%-20p++\n", (void*)s);
      printf("address: ++%-20p++\n",(void*) s);

     _printf("%R", "abczxy");	      ;
     return (0);
}

