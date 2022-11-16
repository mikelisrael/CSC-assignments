#include <stdio.h>

// input .in file
#define INPUT_FILE "adam.in"

int main()
{
    // if file is null
    if (fopen(INPUT_FILE, "r") == NULL)
    {
        // print error
        printf("Error: File not found!");
        // exit program
        return 1;
    }

    // open file
    FILE *file = fopen(INPUT_FILE, "r");

    // read each line of file
    char line[256];
    while (fgets(line, sizeof(line), file))
    {
        // convert line to lowercase
        for (int i = 0; line[i] != '\0'; i++)
        {
            if (line[i] >= 'A' && line[i] <= 'Z')
            {
                line[i] = line[i] + 32;
            }
        }

        int number_of_steps = 0;

        // while s[i] is not D, increment number_of_steps
        for (int i = 0; line[i] != 'd'; i++)
        {
            number_of_steps++;
        }

        // print the result
        printf("%s | Adam walked %i step(s) \n", line, number_of_steps);
    }

    return 0;
}
