#include <cs50.h>
#include <stdio.h>

int main(void)
{

  const int mine = 2;

  int points = get_int("How many points did you lost? ");

  if (points < mine)
  {
    printf("you lost fewer points than me.\n");
  }
  else if (points > mine)
  {
    printf("You lost more points than me.\n")
  }
  else
  {
   printf("You lost the same amount of points as me.\n") 
  }
}