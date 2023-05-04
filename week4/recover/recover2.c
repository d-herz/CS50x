#include <stdio.h>
#include <stdlib.h>

// works for first 25 images
int main(int argc, char *argv[])
{
  if (argc <= 1)
  {
    printf("Usage: File name\n");
    return 1;
  }

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
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
    {
      if (output != NULL)
      {
        fclose(output);
        output = NULL;
      }

      sprintf(file_name, "%03d%s", image_num, img_ext);
      printf("Filename: %s\n", file_name);

      output = fopen(file_name, "w");
      if (output == NULL)
      {
        printf("Failed to open the file.\n");
        fclose(input_file);
        return 1;
      }
      else
      {
        printf("Filename: %s opened.\n", file_name);
      }

      fwrite(buffer, 1, 512, output);
      image_num++;

      // Continue reading and writing the subsequent blocks until a new JPEG header is found
      while (fread(buffer, 1, 512, input_file) == 512)
      {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
          // Found a new JPEG header, break the inner loop
          break;
        }

        fwrite(buffer, 1, 512, output);
      }
        }
  }

  if (output != NULL)
  {
    fclose(output);
  }

  fclose(input_file);
  printf("Data written to the files successfully.\n");
  return 0;
}