#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "process.h"
#include "prompt.h"

char *A_DAY_IN_THE_LIFE_OF_A_TEACHER =
    "./templates/day_in_life_of_teacher.txt";

char *BEST_BIG_SISTER =
    "./templates/best_big_sister.txt";

int MAX_STORY_LEN = 5096;
int MAX_FP_LEN = 128;

int main(int argc, char **argv)
{
    printf("\nDad Libs\n");
    printf("A C Program written by BigDevDog\n\n");
    printf("Choose your template:\n\n");

    printf("[1] A day in the life of a teacher\n");
    printf("[2] Best big sister\n\n");

    int choice = promptInt(2);
    char *templatefp;
    if (choice == 1)
    {
        templatefp = A_DAY_IN_THE_LIFE_OF_A_TEACHER;
    }
    else if (
        choice == 2)
    {
        templatefp = BEST_BIG_SISTER;
    }

    // allocate space for the story string.
    char *story = (char *)calloc(MAX_STORY_LEN, sizeof(char));
    // This is going to read the file, prompt the users for input, and write the
    // constructed story to story.
    processDadLib(templatefp, story);
    // print the story to the user.
    printf("%s\n", story);
    // deallocate the story.
    free(story);
    return 0;
}