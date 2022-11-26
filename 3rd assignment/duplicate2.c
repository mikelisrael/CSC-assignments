#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// input in file
#define INPUT_FILE "files.in"

int main()
{
    // open file
    FILE *file = fopen(INPUT_FILE, "r");

    // check if file exists
    if (file == NULL)
    {
        printf("File not found");
        return 1;
    }

    // put first line in an integer variable T
    int T;
    fscanf(file, "%d", &T);

    char line[11];
    // for number of T, read a line
    for (int i = 0; i < T; i++)
    {
        // read line
        while (fgets(line, sizeof(line), file))
        {
            // if line is integer, compute a loop
            if (atoi(line) != 0)
            {
                // put line in an integer variable N
                int group = atoi(line);
                char *prevName = malloc(sizeof(char) * 11);
                int prevID;

                // for number of N, read a line and print it
                for (int j = 0; j < group; j++)
                {
                    fgets(line, sizeof(line), file);

                    // separate text and number in line
                    char *name = strtok(line, " ");
                    char *number = strtok(NULL, " ");
                    // convert number to integer
                    int ID = atoi(number);
                    // check if previous name is the same to current name
                    if (strcmp(prevName, name) == 0)
                    {
                        if (prevID > ID)
                        {
                            prevID = ID;
                        }
                    }

                    else
                    {
                        prevName = name;
                        prevID = ID;
                        // printf("%s == %s", prevName, name);
                    }
                }
                printf("ID: %d\n", prevID);
            }
        }
    }
    fclose(file);
    return 0;
}