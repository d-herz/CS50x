// Program that "encrypts" a message using Caesars cipher
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declaring Prototypes
bool only_digits(string str);
char rotate(char c, int n);

// Main Function
int main(int argc, string argv[])
{
  string cipherText = "";

  if (argc != 2)
  {
    printf("Usage: ./caesar key\n");
    return 1;
  }
  else if (only_digits(argv[1]) == false)
  {
    printf("Usage: ./caesar key\n");
    return 1;
  }
  else
  {
    int key = atoi(argv[1]);
    string plainText = get_string("plaintext: ");

    for (int i = 0; i < strlen(plainText); i++)
    {
      if (isalpha(plainText[i]))
      {
        plainText[i] = rotate(plainText[i], key);
      }
      else
      {
        plainText[i] = plainText[i];
      }
    }
    printf("ciphertext: %s\n", plainText);
  }
  return 0;
}

// Check if every "char" of str is a digit
bool only_digits(string str)
{
  for (int i = 0; i < strlen(str); i++)
  {
    if (!isdigit(str[i]))
    {
      return false;
    }
  }
  return true;
}

// Rotate function
char rotate(char c, int key)
{
  int oldIdx = ((int)c);
  int newIdx = ((int)c + key);

  if (isupper(c))
  {
    while (newIdx > 90)
    {
      newIdx -= 26;
    }
    // printf("new idx: %i\n", newIdx);
  }
  else if (islower(c))
  {
    while (newIdx > 122)
    {
      newIdx -= 26;
    }
    // printf("new idx: %i\n", newIdx);
  }

  char rotated = (char)newIdx;
  // printf("Old C: %c\n", c);
  // printf("Rotated C: %c\n", rotated);

  return rotated;
}