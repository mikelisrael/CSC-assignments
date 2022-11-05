#include <stdio.h>

int main()
{
    // reverse a string
    // declare a string
    char str[100];
    // prompt user for string
    printf("Enter a string: ");
    // read string from user using fgets
    fgets(str, 100, stdin);
    // print string in reverse
    for (int i = 99; i >= 0; i--)
    {
        printf("%c", str[i]);
    }
    printf("\n");
    return 0;
}