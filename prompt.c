#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * Prompts the user to make a choice between two options.
 *
 * @param max the amount of possible choices.
 * @return the player's choice.
 */
int promptInt(int choices)
{
  int MAX_INPUT_LENGTH = 128;
  // A place to store our input string.
  char *input = (char *)calloc(MAX_INPUT_LENGTH, sizeof(char));
  // The player's choice.
  int choice = 0;
  while (!choice)
  {
    // Player has not yet made a decision.
    // Prompt the user.
    printf("Enter a number between 1 and %d: ", choices);
    // Store their input.
    fgets(input, MAX_INPUT_LENGTH, stdin);
    printf("\n");
    // Parse an int from input into choice.
    choice = atoi(input);
    if (choice < 1 || choice > choices)
    {
      printf("Invalid input. Try again.\n");
      choice = 0;
    }
  }
  // Remember to deallocate the memory for input.
  free(input);
  return choice;
}

int promptString(char *type, char *output)
{
  int MAX_INPUT_LENGTH = 128;
  char *input = (char *)calloc(MAX_INPUT_LENGTH, sizeof(char));
  while (strlen(input) == 0)
  {
    printf("[%s]: ", type);
    // Get a string from the user.
    fgets(input, MAX_INPUT_LENGTH, stdin);
    printf("\n");
    if (strlen(input) == 0)
    {
      printf("Invalid input. Try again.\n");
    }
  }
  for (int i = 0; i < strlen(input) - 1; i++)
  {
    output[i] = input[i];
    output[i + 1] = '\0';
  }
  free(input);
  return 1;
}