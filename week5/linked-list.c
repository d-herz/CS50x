#include <stdio.h>
#include <stdlib.h>

// Defining a "node" structure
// It is self-referential, so we need to include the "struct node" inside
typedef struct node
{
  int number;
  struct node *next;
} 
node;

int main(int argc, char *argv[])
{
  // Declaring a linked-list of size 0
  node *list = NULL;

  // for loop starting at 1 (because argv[0] is program name)
  for (int i = 1; i < argc; i++)
  {
    // atoi() for converting ascii to integer
    int number = atoi(argv[i]);

    // Allocate node for number
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
      return 1;
    }
    n->number = number;
    n->next = NULL;

    // Prepend node to list
    n->next = list;
    list = n;
  }

  // Print numbers 
  // temporary variable for iterating over the list in a while loop
  // It starts off pointing at the first node in the list
  node *ptr = list;
  while (ptr != NULL)
  {
    printf("%i\n", ptr->number);

    // follow the arrow and grab the "next" pointer each time
    ptr = ptr->next;
  }

  // Redeclaring ptr so we can loop through and "free" our malloc'd memory
  ptr = list;
  while (ptr != NULL)
  {
    node *next = ptr->next;
    free(ptr);
    ptr = next;
  }
}