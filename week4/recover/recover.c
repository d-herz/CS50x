#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  if (argc <= 1)
  {
    printf("Usage: ./recover IMAGE\n");
    return 1;
  }

  // Open memory card
  FILE *input_file = fopen(argv[1], "r");
  if (input_file == NULL)
  {
    printf("Filename: '%s' unopenable\n", argv[1]);
    return 1;
  }
  else
  {
    printf("Filename: '%s' opened\n", argv[1]);
  }

  int image_num = 0;
  char *img_ext = ".jpg";
  char file_name[15];
  unsigned char buffer[512];

  FILE *output = NULL;

  while (fread(buffer, 1, 512, input_file))
  {
    // If start of new JPEG, check if first jpeg or not, and start writing
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
    {
      if (output != NULL)
      {
        fclose(output);
        output = NULL;
        image_num++;
      }
      // Print formatted string to memory (and terminal, to check)
      sprintf(file_name, "%03d%s", image_num, img_ext);
      printf("Filename: %s created\n", file_name);

      // Open file with new filename (and print to terminal)
      output = fopen(file_name, "w");
      printf("Filename: %s opened\n", file_name);

      // Write to new file, and print to terminal
      fwrite(buffer, 1, 512, output);
      printf("Filename: %s written too\n", file_name);

      // Check if new file is empty, if so then an error has occured
      if (output == NULL)
      {
        printf("Failed to open the file.\n");
        fclose(input_file);
        return 1;
      }

      // Continue reading and writing the subsequent blocks until a new JPEG header is found
    }
    else if (output != NULL)
    {
      fwrite(buffer, 1, 512, output);
    }
  }

  fclose(output);
  fclose(input_file);
  printf("Data written to the files successfully.\n");
  return 0;
}