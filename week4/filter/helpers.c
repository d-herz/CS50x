#include "helpers.h"
#include <stdio.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
  // for loop, each " i'th " row
  for (int i = 0; i < height; i++)
  {
    // Each "jth" pixel
    for (int j = 0; j < width; j++)
    {
      float average = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0;
      printf("Avg: %f\n", average);
      int avg_rnd = (int)round(average);
      image[i][j].rgbtRed = avg_rnd;
      image[i][j].rgbtGreen = avg_rnd;
      image[i][j].rgbtBlue = avg_rnd;
    }
  }
  return;
}

// Convert image to sepia
// Calc each new color value using Sepia formula
// Cap values at 255
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {

      float sepiaRedFloat = (0.393 * image[i][j].rgbtRed) + (0.769 * image[i][j].rgbtGreen) + (0.189 * image[i][j].rgbtBlue);
      float sepiaGreenFloat = (0.349 * image[i][j].rgbtRed) + (0.686 * image[i][j].rgbtGreen) + (0.168 * image[i][j].rgbtBlue);
      float sepiaBlueFloat = (0.272 * image[i][j].rgbtRed) + (0.534 * image[i][j].rgbtGreen) + (0.131 * image[i][j].rgbtBlue);

      int sepiaRed = (int)round(sepiaRedFloat);
      int sepiaGreen = (int)round(sepiaGreenFloat);
      int sepiaBlue = (int)round(sepiaBlueFloat);

      if (sepiaRed > 255)
      {
        sepiaRed = 255;
      }

      if (sepiaGreen > 255)
      {
        sepiaGreen = 255;
      }
      if (sepiaBlue > 255)
      {
        sepiaBlue = 255;
      }
      image[i][j].rgbtRed = sepiaRed;
      image[i][j].rgbtGreen = sepiaGreen;
      image[i][j].rgbtBlue = sepiaBlue;
    }
  }
  return;
}

// Reflect image horizontally
// Reverse each row (essentially)
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
  RGBTRIPLE temp;
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width / 2; j++)
    {
      temp = image[i][j];
      image[i][j] = image[i][width - j - 1];
      image[i][width - j - 1] = temp;
    }
  }
  return;
}

// Blur image
// Box blur
// Average of all pixels within 1 row and 1 column of pixel
// Row -1;
// Pixel -1, pixel same, pixel + 1
// Row Same
// Pixel -1, pixel same, pixel +1
// Row + 1
// Pixel -1, pixel same, pixel + 1

// count # of pixels for average sake
void blur(int height, int width, RGBTRIPLE image[height][width])
{
  // Copy "image" so blurred pixels don't effect outcome
  RGBTRIPLE image_copy[height][width];

  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      image_copy[i][j] = image[i][j];
    }
  }

  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      // Counter for average division
      int counter = 1;

      // Going to be some massive conditionals

      // If the first row
      if (i = 0)
      {
        // First column
        if (j = 0)
        {
          float avg_Red = (image_copy[i][j].rgbtRed + image_copy[i][j + 1].rgbtRed + image_copy[i + 1][j].rgbtRed + image_copy[i + 1][j + 1].rgbtRed) / 4.0;
          float avg_Green = (image_copy[i][j].rgbtGreen + image_copy[i][j + 1].rgbtGreen + image_copy[i + 1][j].rgbtGreen + image_copy[i + 1][j + 1].rgbtGreen) / 4.0;
          float avg_Blue = (image_copy[i][j].rgbtBlue + image_copy[i][j + 1].rgbtBlue + image_copy[i + 1][j].rgbtBlue + image_copy[i + 1][j + 1].rgbtBlue) / 4.0;
        }
        // 2nd column through 2nd to last
        if (j > 0 && j < width - 1)
        {
          float avg_Red = (image_copy[i][j].rgbtRed + image_copy[i][j - 1].rgbtRed + image_copy[i][j + 1].rgbtRed + image_copy[i + 1][j].rgbtRed + image_copy[i + 1][j - 1].rgbtRed + image_copy[i + 1][j + 1].rgbtRed) / 6.0;
          float avg_Green = (image_copy[i][j].rgbtGreen + image_copy[i][j - 1].rgbtGreen + image_copy[i][j + 1].rgbtGreen + image_copy[i + 1][j].rgbtGreen + image_copy[i + 1][j - 1].rgbtGreen + image_copy[i + 1][j + 1].rgbtGreen) / 6.0;
          float avg_Blue = (image_copy[i][j].rgbtBlue + image_copy[i][j - 1].rgbtBlue + image_copy[i][j + 1].rgbtBlue + image_copy[i + 1][j].rgbtBlue + image_copy[i + 1][j - 1].rgbtBlue + image_copy[i + 1][j + 1].rgbtBlue) / 6.0;
        }
        if (j = width - 1)
        {
          float avg_Red = (image_copy[i][j].rgbtRed + image_copy[i][j - 1].rgbtRed + image_copy[i + 1][j].rgbtRed + image_copy[i + 1][j - 1].rgbtRed) / 4.0;
          float avg_Green = (image_copy[i][j].rgbtGreen + image_copy[i][j - 1].rgbtGreen + image_copy[i + 1][j].rgbtGreen + image_copy[i + 1][j - 1].rgbtGreen) / 4.0;
          float avg_Blue = (image_copy[i][j].rgbtBlue + image_copy[i][j - 1].rgbtBlue + image_copy[i + 1][j].rgbtBlue + image_copy[i + 1][j - 1].rgbtBlue) / 4.0;
        }
      }
      // 2nd row through 2nd to last row
      if (i > 0 && i < height - 1)
      {
        // First column
        if (j = 0)
        {
          float avg_Red = (image_copy[i][j].rgbtRed + image_copy[i][j + 1].rgbtRed + image_copy[i - 1][j].rgbtRed + image_copy[i - 1][j + 1].rgbtRed + image_copy[i + 1][j].rgbtRed + image_copy[i + 1][j + 1].rgbtRed) / 6.0;
          float avg_Green = (image_copy[i][j].rgbtGreen + image_copy[i][j + 1].rgbtGreen + image_copy[i - 1][j].rgbtGreen + image_copy[i - 1][j + 1].rgbtGreen + image_copy[i + 1][j].rgbtGreen + image_copy[i + 1][j + 1].rgbtGreen) / 6.0;
          float avg_Blue = (image_copy[i][j].rgbtBlue + image_copy[i][j + 1].rgbtBlue + image_copy[i - 1][j].rgbtBlue + image_copy[i - 1][j + 1].rgbtBlue + image_copy[i + 1][j].rgbtBlue + image_copy[i + 1][j + 1].rgbtBlue) / 6.0;
        }
        // 2nd column through 2nd to last
        if (j > 0 && j < width - 1)
        {
          float avg_red = ;
        }

        // Same row
        float avg_Red = (image_copy[i][j].rgbtRed + image_copy[i][j + 1].rgbtRed + image_copy[i][j - 1].rgbtRed) / 3.0;
        float avg_Green = (image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i][j - 1].rgbtGreen) / 3.0;
        float avg_Blue = (image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i][j - 1].rgbtBlue) / 3.0;
      }
    }
    return;
  }
