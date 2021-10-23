#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int i, n, sum = 0;
    scanf("%d", &n); // scan the number of elements of the dynamic array
    int * arr = (int *) malloc(n * sizeof(int)); // create dynamic array in heap using malloc
    for(i = 0; i < n; i++) // for loop to scan each element of the array from the user
    {
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < n; i++) // for loop to produce the sum of all elements of dynamic array
    {
        sum += arr[i];
    }
    free(arr); // free the spaces reserved by array elements to be used for another purposes
    printf("%d", sum); // print the sum of all elements of dynamic array
    return 0;
}
