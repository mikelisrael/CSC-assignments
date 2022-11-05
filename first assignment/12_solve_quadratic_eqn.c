#include <stdio.h>
#include <math.h>

int main()
{
    // declare variables
    double a, b, c, x1, x2, discriminant, realPart, imaginaryPart;
    // prompt user for a
    printf("Enter a: ");
    scanf("%lf", &a);

    // prompt user for b
    printf("Enter b: ");
    scanf("%lf", &b);

    // prompt user for c
    printf("Enter c: ");
    scanf("%lf", &c);

    // calculate discriminant
    discriminant = b * b - 4 * a * c;

    // check if discriminant is greater than 0
    if (discriminant > 0)
    {
        // two real and distinct roots
        x1 = (-b + sqrt(discriminant)) / (2 * a);
        x2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Roots are: %.2lf and %.2lf", x1, x2);
    }
    else if (discriminant == 0)
    {
        // two real and equal roots
        x1 = x2 = -b / (2 * a);
        printf("Roots are: %.2lf and %.2lf", x1, x2);
    }
    else
    {
        // roots are complex and distinct
        realPart = -b / (2 * a);
        imaginaryPart = sqrt(-discriminant) / (2 * a);
        printf("Roots are: %.2lf + %.2lfi and %.2lf - %.2lfi", realPart, imaginaryPart, realPart, imaginaryPart);
    }
    return 0;
}