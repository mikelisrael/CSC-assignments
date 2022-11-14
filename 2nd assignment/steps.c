#include <stdio.h>

int main()
{
    // collect input
    printf("Enter a string with Us and Ds: ");
    char s[100];
    scanf("%s", s);

    // convert string to lowercase
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = s[i] + 32;
        }
    }

    int number_of_steps = 0;

    // while s[i] is not D, increment number_of_steps
    for (int i = 0; s[i] != 'd'; i++)
    {
        number_of_steps++;
    }

    // print the result
    printf("Adam walked %i step(s) \n", number_of_steps);

    return 0;
}
