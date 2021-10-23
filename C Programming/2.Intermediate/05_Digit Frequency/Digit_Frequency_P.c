#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    // array of 10 elements to store how many times each index of this array has been repeated
    // as each index of this array represent the number we want to check how many times it has
    // been repeated
    char nums[10] = {0};
    int i,j;
    char * arr = (char *) malloc(1024 * sizeof(char)); // create a dynamic array of characters of size 1024 byte
    scanf("%[^\n]%*c", arr); // scan the whole string from the user
    arr = realloc(arr, strlen(arr) + 1); // reallocate the new actual size of the array at the same address (arr)

    // for loop to check for every character first if that character is even
    // represent a number or it is just an English letter, and if that character
    // represent one number from (0, 9) then loop for ten iterations to check
    // if the current character represent each number from 0 to 9 and if so then
    // increment the index of the same number at nums array and break that loop
    // to go directly check for the next character without wasting some time to
    // any remaining iterations of the second loop.
    for(i = 0; i < strlen(arr); i++)
    {
        if(arr[i] >= 48 && arr[i] <= 57)
        {
            for(j = 0; j < 10; j++)
            {
                if(arr[i] == 48 + j)
                {
                    nums[j]++;
                    break;
                }
            }
        }
    }
    // for loop to print how many digit from 0 to 9 has been repeated through the whole string
    for(i = 0; i < 10; i++)
    {
        printf("%d ", nums[i]);
    }
    return 0;
}
