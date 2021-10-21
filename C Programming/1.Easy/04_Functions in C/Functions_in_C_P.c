#include <stdio.h>
/*
Add `int max_of_four(int a, int b, int c, int d)` here.
*/
int max_of_four(int n1, int n2, int n3, int n4)
{
    int arr[] = {n1, n2, n3, n4}; // An array of the four inputs of the function
    int max = arr[0]; // Initiate the value of max variable to the first element of the array
    int i;
    for(i = 1; i < 4; i++) // Iterate over the elements of the array
    {
        /*
        Check if the current element of the array is greater than the value of max variable,
        and if so, then assign the value of that element to the variable max.
        */
        if(arr[i] > max)
        max = arr[i];
    }
    return max; // Return the max value between all inputs
}

int main()
{
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);

    return 0;
}
