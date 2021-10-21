#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n, i, sum = 0;
    scanf("%d", &n);
    //Complete the code to calculate the sum of the five digits on n.

    // for loop to loop for five times, as for each iteration
    // it get the last right digit of the number n, add its
    // value to variable sum then remove that digit from n, and
    // and do the same steps but with number n after removing the
    // last right digit from the previous iteration,as after five
    // iterations the value of n would be 0 and we will successfully
    // get the sum of all digits of the number n
    for(i = 0; i < 5; i++)
    {
        sum += n % 10; // get the last right digit and add its value to sum
        n /= 10; // remove that last right digit from n
    }
    printf("%d", sum); // print the total sum of all digits of n
    return 0;
}
