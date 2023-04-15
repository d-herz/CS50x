#include <cs50.h>
#include <stdio.h>

// Linear Search algorithm:
int main(void)
{
  // Statically declaring an array with curly braces
  int numbers[] = {20, 500, 10, 5, 100, 1, 50};

  // Alternativly
  // int numbers[7];
  // numbers[0] = 20;
  // numbers[1] = 500;
  // numbers[2] = 10;
  // numbers[3] = 5; (etc)

  int n = get_int("Number: ");
  for (int i = 0; i < 7; i++)
  {
    if (numbers[i] == n)
    {
      printf("Found\n");
      return 0;
      // 0 means success
    }
  }
  printf("Not found \n");
  return 1;
  // Anything but 0 means not success/error
}