#include <stdio.h>

int main()
{
    // loop to receive 10 names
    for (int i = 0; i < 10; i++)
    {
        // declare a string to hold the name
        char name[20];
        // prompt user for name
        printf("Enter name %d: ", i + 1);
        // read name from user
        scanf("%s", name);
    }
    return 0;
}