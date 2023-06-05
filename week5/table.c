#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>

typedef struct node
{
  string phrase;
  struct node *next;
} node;

node *table[26];

int hash(string phrase);

int main(void)
{
  for (int i = 0; i < 3; i++)
  {
    string phrase = get_string("Enter a new Phrase:");
    int index = hash(phrase);
    printf("%s hashes to %i\n", phrase, index);
  }
}

int hash(string phrase)
{
  return 0;
}