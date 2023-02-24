#include <cs50.h>
#include <stdio.h>

int main(void)
{
  int initialPop;
  int endingPop;
  int currentPop;
  int popChange;
  int years = 0;

  // TODO: Prompt for start size
  do
  {
    initialPop = get_int("Starting Population Size: ");
    currentPop = initialPop;

  } while (initialPop < 9);

  // TODO: Prompt for end size
  do
  {
    endingPop = get_int("Ending Population Size: ");
  } while (endingPop < initialPop);

  // TODO: Calculate number of years until we reach threshold
  while (currentPop < endingPop)
  {
    popChange = (currentPop / 3) - (currentPop / 4);
    currentPop += popChange;
    years++;
  }

  // TODO: Print number of years
  printf("Years: %i\n", years);
}
