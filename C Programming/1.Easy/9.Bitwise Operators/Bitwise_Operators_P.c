#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k)
{
  // three variables to store the max accepted number from
  // the operations AND, OR, XOR
  int Max_AND = 0;
  int Max_OR = 0;
  int Max_XOR = 0;
  int i, j;

  // So, we want to make three operations (AND, OR, XOR)
  // between each possible number from 1 to n, as if n = 4
  //then, all the possible pairs are as following:
  // 1 , 2
  // 1 , 3
  // 1 , 4
  // 2 , 3
  // 2 , 4
  // 3 , 4

  // So, in order to include all the possible pairs we make
  // two for loops! the first one loops from 1 to n - 1, and the
  // second one loops from (the current index of loop one + 1) to n
  // So, for each index from loop one, loop two will loop from
  // (the index of loop one + 1) to n, which by this way we can include
  // all the possible pairs that we want to make operations on.
  //
  for(i = 1; i < n; i++)
  {
      for(j = i + 1; j <= n ; j++)
      {
           // checks if (i & j) is bigger than Max_AND and at the same time
           // is smaller than k (threshold) then accept that result, otherwise
           // store the last result stored in Max_AND
          Max_AND = ((i & j) > Max_AND) && ((i & j) < k) ? i & j : Max_AND;

           // checks if (i | j) is bigger than Max_OR and at the same time
           // is smaller than k (threshold) then accept that result, otherwise
           // store the last result stored in Max_OR
          Max_OR = ((i | j) > Max_OR) && ((i | j) < k) ? i | j : Max_OR;

           // checks if (i ^ j) is bigger than Max_XOR and at the same time
           // is smaller than k (threshold) then accept that result, otherwise
           // store the last result stored in Max_XOR
          Max_XOR = ((i ^ j) > Max_XOR) && ((i ^ j) < k) ? i ^ j : Max_XOR;
      }
  }
  printf("%d\n", Max_AND); // print the max accepted result from AND operation
  printf("%d\n", Max_OR); // print the max accepted result from OR operation
  printf("%d\n", Max_XOR); // print the max accepted result from XOR operation
}

int main() {
    int n, k;

    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);

    return 0;
}
