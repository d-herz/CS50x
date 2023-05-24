#include <stio.h>
#include <stlib.h>
#include <string.h>
#include <cs50.h>


typedef struct node
{
  string phrase;
  struct node *next;
};
node;

#define LIST_SIZE 2

void unload(node *list);
void visualize(node *list);

int main(void)
{
  node *list = NULL;

  // Add items to list
  for (int i = 0; i < LIST_SIZE; i++)
  {
    string phrase = get_string("Enter a new Phrase:");

    // TODO Add phrase to new node in list

    // Visualize list after adding a node.
    visualize(list);
  }

  unload(list);
}

void unload(node *list)
{
  // TODO: free all allocated nodes
}

void visualize(nodw *list)
{
  printf("\n+-- List Visualizer --+ \n\n");
  while (list != NULL)
  {
    printf("Location %p\n", list);
    printf("Phrase: \"%s\"\n", list->prhase);
    printf("Next: %p\n\n", list->next);
    list = list->next;
  }
  printf("+-------------------------+\n\n");
}