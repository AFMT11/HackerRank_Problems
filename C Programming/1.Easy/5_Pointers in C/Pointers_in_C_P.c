#include <stdio.h>

void update(int *a,int *b)
{
    // Complete this function
    *a = *a + *b; // Add the value of the variables a & b, assign that value to the variable a
    *b = *a - *b - *b > 0 ? *a - *b - *b : -1 * (*a - *b - *b);
    /*
    now the variable a has the sum of variables a, b.
    so, to calculate the difference between variable a, b we
    subtract the the current value of a (which is now the sum
    of both variables) from the value of b which will result to
    the original value of variable a, then subtract that value
    from the value of b again, and now to find the difference
    between these two variables.
    And then make ternary operator to check the result value
    of the subtraction, if the value is bigger than 0 then assign
    that value to the variable b, if not, then multiply that value
    to -1 then assign the final result to the variable b!
    That's it...
    */
}

int main()
{
    int a, b;
    int *pa = &a, *pb = &b;

    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
