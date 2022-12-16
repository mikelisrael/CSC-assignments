#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(int group, int *fileIDs);

void main()
{
    // declaring a pointer to link the file to my code
    FILE *file;
    file = fopen("files.in", "r");

    // Program exits if the file pointer returns NULL
    if (file == NULL)
    {
        printf("Error! opening file");
        exit(1);
    }
    int T;
    fscanf(file, "%d", &T);
    for (int i = 0; i < T; i++)
    {
        int group;
        fscanf(file, "%d", &group);
        char fileNames[group][100];
        int fileIDs[group];

        for (int j = 0; j < group; j++)
        {
            int currFIleID;
            char currFileName[100];
            fscanf(file, "%s", currFileName);
            int indexLocation;

            for (int i = 0; i < group; i++)
            {
                // checking if the file exist in the main array i.e fileNames
                if (strcmp(fileNames[i], currFileName) == 0)
                {
                    indexLocation = i;
                    break;
                }
                else
                {

                    indexLocation = -1;
                }
            }

            fscanf(file, "%d", &currFIleID);

            // if the file doesn't exist yet add it to the file array i.e fileNames
            if (indexLocation == -1)
            {
                strcpy(fileNames[j], currFileName);
                fileIDs[j] = currFIleID;
            }
            else
            { // if the file exist compare the ID with the already existing file ID
                if (fileIDs[indexLocation] <= currFIleID)
                {
                    strcpy(fileNames[j], currFileName);
                }
                else
                {
                    strcpy(fileNames[j], currFileName);
                    fileIDs[indexLocation] = currFIleID;
                    fileIDs[j] = -1;
                }
            }
        }
        sort(group, fileIDs);
    }
}

void sort(int group, int *fileIDs)
{
    int sort;
    for (int i = 0; i < group; i++)
    {
        for (int j = i + 1; j < group; j++)
        {
            if (fileIDs[i] > fileIDs[j])
            {
                sort = fileIDs[i];
                fileIDs[i] = fileIDs[j];
                fileIDs[j] = sort;
            }
        }
    }
    for (int a = 0; a < group; a++)
    {
        if (fileIDs[a] != -1)
        {
            printf("%d ", fileIDs[a]);
        }
    }
    printf("\n");
}