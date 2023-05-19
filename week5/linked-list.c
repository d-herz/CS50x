#include <stdio.h>
#include <stdlib.h>

// Defining a "node" structure
// It is self-referential, so we need to include the "struct node" inside
typedef struct node
{
  int number;
  struct node *next;
} node;

int main(int argc, char *argv[])
{
  // Declaring a linked-list of size 0
  node *list = NULL;

  // for loop starting at 1 (because argv[0] is program name)
  for (int i = 1; i < argc; i++)
  {
    // atoi() for converting ascii to integer
    int number = atoi(argv[i]);

    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
      return 1;
    }
    n->number = number;
    n->next = NULL;

    n->next = list;
    list = n;
  }

  // temporary variable for iterating over the list in a while loop
  // it starts off pointing at the first node in the list
  node *ptr = list;

  while (ptr != NULL)
  {
    printf("%i\n", ptr->number);

    // follow the arrow and grab the "next" pointer each time
    ptr = ptr->next;
  }

  // redeclaring ptr so we can loop through and "free" our malloc'd memory
  ptr = list;
  while (ptr != NULL)
  {
    node *next = ptr->next;
    free(ptr);
    ptr = next;
  }
}