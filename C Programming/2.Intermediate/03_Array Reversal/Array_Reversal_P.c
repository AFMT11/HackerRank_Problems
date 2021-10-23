#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *arr, i;
    scanf("%d", &num); // scan the number of element of the array from the user
    arr = (int*) malloc(num * sizeof(int)); // create a dynamic array of (num) elements
    for(i = 0; i < num; i++) // for loop to take the value of each element of the array from the user
    {
        scanf("%d", arr + i);
    }
    /* Write the logic to reverse the array. */
    for(i = 0; i < num / 2; i++) // for loop to reverse the elements values of the array
    {
        arr[i] = arr[i] + arr[num - i - 1];
        arr[num - i - 1] = arr[i] - arr[num - i - 1];
        arr[i] = arr[i] - arr[num - i - 1];
    }

    for(i = 0; i < num; i++) // for loop to print the element of the array after the reversal of the element
        printf("%d ", *(arr + i));
    return 0;
}
