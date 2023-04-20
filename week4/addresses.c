#include <stdio.h>

int main(void)
{
  int n = 50;
  printf("%i\n", n);
}

int x = 42; // declare an integer variable and initialize it with the value 42
int *ptr;   // declare a pointer variable that can store the memory address of an integer

ptr = &x; // assign the memory address of x to the pointer variable ptr
