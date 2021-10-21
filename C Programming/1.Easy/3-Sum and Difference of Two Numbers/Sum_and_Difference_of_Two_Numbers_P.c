#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    int a,b;    // Creating two int variables
    float c,d;  // Creating two float variables

    scanf("%d %d", &a, &b); // Take the values of int variables
    scanf("%f %f", &c, &d); // Take the values of float variables

    printf("%d %d\n", a+b, a-b); // Print the sum & subtraction of int variables
    printf("%0.1f %0.1f", c+d, c-d); // Print the sum & subtraction of float variables

    return 0;
}
