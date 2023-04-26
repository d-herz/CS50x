#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
  char *s = get_string("s: ");

  // this is like copying the same ADDRESS
  char *t = s;

  if (strlen(t) > 0)
  {
    t[0] = toupper(t[0]);
  }

  // both will be uppercase
  printf("s: %s\n", s);
  printf("t: %s\n", t);
}