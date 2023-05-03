#include <stdio.h>
#include <stdlib.h>

// Accept 1 command line arg
int main(int argc, char *argv[])
{
  // Ensure command line args exist
  if (argc <= 1)
  {
    printf("Usage: File name\n");
    return 1;
  }

  // Open input file
  FILE *input_file = fopen(argv[1], "r");
  // Check for nullness
  if (input_file == NULL)
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
  int image_num = 0;
  char *img_ext = ".jpg";
  char file_name[10];

  sprintf(file_name, "%03d%s", image_num, img_ext);
  printf("Filename: %s\n", file_name);

  FILE *output = fopen("000.jpg", "w");
  if (output == NULL)
  {
    printf("Failed to open the file.\n");
    fclose(input_file);
    return 1;
  }
  else
  {
    printf("Filename: %s opened.\n", file_name);
    while (fread(output, 1, 512, input_file))
    {
      printf("%p\n", output);
    }
  }
  // fread for reading data from memory card: fread(data, size, number, inptr)
  // Buffer could be an array (define it)

  fclose(input_file);
  printf("Data written to the file succefully.\n");
  return 0;
}