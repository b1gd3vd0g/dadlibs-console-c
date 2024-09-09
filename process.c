#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "prompt.h"

int processDadLib(char *template_fp, char *story)
{
  int MAX_PROMPT_SIZE = 128;
  int MAX_INPUT_LENGTH = 128;
  // Get a file pointer aimed at the first character in template_fp.
  FILE *template = fopen(template_fp, "r");
  // Error if necessary.
  if (template == NULL)
  {
    printf("Failed to open file at %s", template_fp);
    return 0;
  }

  // Parse the file.

  // The current character in the file.
  int curr_char = 0;
  // The index of story that we are on.
  int story_index = 0;

  // Now let us parse the file.
  while (1)
  {
    // Get the next character in the file.
    curr_char = fgetc(template);
    if (curr_char == EOF)
      break;

    if (curr_char != '{')
    {
      // This is the easy case. Copy the curr_char to story and increment.
      story[story_index] = curr_char;
      story_index++;
    }
    else
    {
      // curr_char is at '{', meaning that a prompt is coming up.
      // Skip the bracket and do nothing.
      curr_char = fgetc(template);
      // allocate space for an array prompt
      char *prompt = (char *)calloc(MAX_PROMPT_SIZE, sizeof(char));
      int prompt_index = 0;

      while (curr_char != '}')
      {
        if (curr_char == EOF)
        {
          printf("Bad template - missing an ending bracket somewhere.");
          return 0;
        }
        // Add the character to the prompt.
        prompt[prompt_index] = curr_char;
        curr_char = fgetc(template);
        prompt_index++;
      }

      // We got the prompt. Now we need the output string.
      char *output = (char *)calloc(MAX_INPUT_LENGTH, sizeof(char));
      promptString(prompt, output);
      free(prompt);
      // Now output contains the user input. We need to add it to story.
      int k = 0;
      while (output[k] != '\0')
      {
        story[story_index] = output[k];
        story_index++;
        k++;
      }
      // Deallocate output.
      free(output);
      // Now, the user's response ought to have been written to the story.
      // curr_char is still equal to '}'. Skip.
    }
  }
  fclose(template);
  // We have processed the entirety of our story.
  // We are done.
  return 1;
}