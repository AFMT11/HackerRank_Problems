#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.

// in this problem we want to calculate the Nth term
// where 1th term S(1) = a, 2th term S(2) = b, 3th term S(3) = c,
// but terms bigger than 3 calculated using the following function
// S(n) = S(n - 1) + S(n - 2) + S(n - 3)

// So, here we have to make two conditions; the first one where the term is not
//bigger than 3, then it will return the corresponding value based on it is
// S(1), S(2), or S(3), the second condition is where the term is bigger than 3
// then we must apply the previous equation and for each operand of the equation
// it will check if the term is bigger than 3 or not

//So, for each operand of the equation we will call the function itself again
// but with the new term, well if the term is less than or equal to 3 then it will
// return only the value of three variables (a, b, c), else it will go for the
// equation in which each operand is actually another call to the same function
// but with a new therm, and so forth until we calculate all the terms,
// decreasing the terms over and over until we reach the basic three terms which by
// them we can put an end to these recursion functions!
int find_nth_term(int n, int a, int b, int c)
{
  //Write your code here.
  int result = 0;
  int arr[3] = {a, b, c};
  if(n > 3) // if the term is bigger than 3
  {
      result = find_nth_term(n - 1, a, b, c) + find_nth_term(n - 2, a, b, c) + find_nth_term(n - 3, a, b, c);
  }
  else // if the term is less than or equal to 3
  {
      result = arr[n - 1];
  }
  return result;
}

int main()
{
    int n, a, b, c;

    scanf("%d %d %d %d", &n, &a, &b, &c);
    int ans = find_nth_term(n, a, b, c);

    printf("%d", ans);
    return 0;
}
