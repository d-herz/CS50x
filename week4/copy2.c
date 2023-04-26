#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  char *s = get_string("s: ");

  // t is now a pointer to some random chunk of free space;
  // by using the strlen of s PLUS 1, we will have room for the \0 NUL character
  char *t = malloc(strlen(s) + 1);

  // using a for loop, notice the 2 variables in the initialization
  // for (int i = 0, n = strlen(s) + 1; i < n; i++)
  // {
  //   t[i] = s[i];
  // }

  // using strcpy() from the string.h library
  strcpy(t, s);

  if (strlen(t) > 0)
  {
    t[0] = toupper(t[0]);
  }

  printf("s: %s\n", s);
  printf("t: %s\n", t);
}