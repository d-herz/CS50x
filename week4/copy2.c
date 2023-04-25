#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  char *s = get_string("s: ");

  // t is now a pointer to some random chunk of free space;
  char *t = malloc(strlen(s) + 1);

  for (int i = 0; i < strlen(s) + 1; i++)
  {
    t[i] = s[i];
  }

  printf("s: %s\n", s);
  printf("t: %s\n", t);
}