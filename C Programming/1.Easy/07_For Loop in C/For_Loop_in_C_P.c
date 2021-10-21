#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



int main()
{
    int a, b, i;
    scanf("%d\n%d", &a, &b); // scan two integers
  	// Complete the code.
    char *arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    // within the range between the numbers a, b print the string
    // that represent each number if that number is bigger than or equal to 1
    // and less than or equal to 9, and if the number is bigger than 9 then
    // print if it is even or odd number
    for(i = a; i <= b; i++)
    {
        if(i >= 1 && i <= 9) // the first case that checks if the number is in the range
        {
            printf("%s\n", arr[i]); // print the value of indexes from 1 to 9
        }
        else if (i % 2 == 0) // check if it is even
        {
            printf("even\n");
        }
        else // if the number is not in the range (1, 9) and not even, then it's odd
        {
            printf("odd\n");
        }
    }

    return 0;
}

