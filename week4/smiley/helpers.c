#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
  // Looping through the 2-dimensional array
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      // Checking if the current colors are black, and if so change to a nice green
      if (image[i][j].rgbtRed == 0x00 && image[i][j].rgbtGreen == 0x00 && image[i][j].rgbtBlue == 0x00)
      {
        image[i][j].rgbtRed = 0x7a;
        image[i][j].rgbtGreen = 0xFF;
        image[i][j].rgbtRed = 0x33;
      }
    }
  }
}
