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

  // TODO's below
  // Each jpg starts with header: 0xff, 0xd8, 0xff, and ends with 0xe(0-f)
  // Look through file/blocks for begining headers
  // Once found:
  // Open new file to start writing to, block x block until you find another beginning header

  // Need to name new output file and increment it each time
  int image_num = 000;
  char *img_ext = ".jpg";
  char *file_name = "image_num + img_ext";

  FILE *output = fopen("000.jpg", "w");
  if (output == NULL)
  {
    fclose(input);
    return 1;
  }
  // fread for reading data from memory card: fread(data, size, number, inptr)
  // Buffer could be an array (define it)
  while (fread(buffer, 1, BLOCK_SIZE, raw_file) == BLOCK_SIZE)
  {
    fwrite()
  }

  fclose(file);
}