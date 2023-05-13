#include <stdio.h>
#include <stdlib.h>

// Accept 1 command line arg
int main(int argc, char *argv[])
{
  if (argc <= 1)
  {
    printf("Usage: File name\n");
    return 1;
  }

  FILE *file = fopen(argv[1], "r");

  if (file == NULL)
  {
    printf("Filename: '%s' unopenable\n", argv[1]);
    return 1;
  }
  else
  {
    printf("Filename: '%s' opened\n", argv[1]);
  }
}