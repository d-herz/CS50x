#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates defined as a constant
#define MAX 9

// Candidates have name and vote count
typedef struct
{
  string name;
  int votes;
} candidate;

// Global array of candidates, each element is a candidate
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
  // Check for invalid usage
  if (argc < 2)
  {
    printf("Usage: plurality [candidate ...]\n");
    return 1;
  }

  // Populate array of candidates
  candidate_count = argc - 1;
  if (candidate_count > MAX)
  {
    printf("Maximum number of candidates is %i\n", MAX);
    return 2;
  }
  for (int i = 0; i < candidate_count; i++)
  {
    candidates[i].name = argv[i + 1];
    candidates[i].votes = 0;
  }

  int voter_count = get_int("Number of voters: ");

  // Loop over all voters
  for (int i = 0; i < voter_count; i++)
  {
    string name = get_string("Vote: ");

    // Check for invalid vote
    if (!vote(name))
    {
      printf("Invalid vote.\n");
    }
  }

  // Display winner of election
  print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
  // Check if "name" matches on of the candidates in the array
  for (int i = 0; i < 9; i++)
  {
    if (strcmp(candidates[i].name, name) == 0)
    {
      printf("Found\n");
      candidates[i].votes++;
      return true;
    }
  }
  return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
  string winner[candidate_count];
  int maxVoteTrack = 0;

  for (int i = 0; i < 9; i++)
  {
    if (candidates[i].votes != 0 && candidates[i].votes > maxVoteTrack)
    {
      maxVoteTrack = candidates[i].votes;
      winner[i] = candidates[i].name;
    }
  }

  printf("Array: %s\n", winner[0]);
  printf("Winner: %i\n", maxVoteTrack);
}