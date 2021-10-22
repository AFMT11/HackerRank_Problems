#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int n, i, j, count, displayed_digit;
    scanf("%d", &n); // scan the number from the user

  	// So, to print patterns, i created two for loops
  	// one for the rows and the other one for the columns

  	//but now to explain the code let's discuss it when
  	// trying to print the pattern with number 4 at the outer edge

  	// 4 4 4 4 4 4 4
  	// 4 3 3 3 3 3 4
  	// 4 3 2 2 2 3 4
  	// 4 3 2 1 2 3 4
  	// 4 3 2 2 2 3 4
  	// 4 3 3 3 3 3 4
  	// 4 4 4 4 4 4 4

  	// So, if we split that pattern into four duplicated shapes
  	// they will be as following

    // *Upper_Left         |           *Upper_Right
    //   4 4 4 4           |             4 4 4 4
    //   4 3 3 3           |             3 3 3 4
    //   4 3 2 2           |             2 2 3 4
    //   4 3 2 1           |             1 2 3 4
    //   --------------------------------------
  	//   4 3 2 1           |             1 2 3 4
  	//   4 3 2 2           |             2 2 3 4
  	//   4 3 3 3           |             3 3 3 4
  	//   4 4 4 4           |             4 4 4 4
    // *Lower_Left         |           *Lower_Right

    // So, now let's work on the upper-left part
    // and if we could do it then it will be much easier to
    // do the three remaining parts
    // So, we make a condition that if the current index of rows
    // is smaller than or equal to (n - 1) which is the index that
    // split the pattern horizontally by half, then the variable
    // count will be equal to i (the current index of rows) and the
    // condition will always be true for the upper-left part of the pattern
    // and we will use that variable count in addition to the value of
    // the index of columns in order to decide where to decrement the
    // value of the outer edge of the pattern!

    // So, as we notice that all the values of the first row and
    // the first column, are the same and equal to the input number from
    // the user, so, in the first condition inside the second for loop,
    // we check if the values of count, and j are bigger than 0, and as
    // the case of the first row or the first column that condition will
    // be false, and let's skip the second if! and jump to the function
    // printf which will print 4 for all the elements of the first row
    // and the first column!

    // but now to the second row of index 1, actually i made the code
    // where the number of the index of rows ill determine how many
    // times we will decrement the value of the elements

    // So, for the second row with index 1, and inside the second for
    // loop and the first condition to check which if the count (count = 1)
    // and j (index of columns) their values are bigger than 0, and for the
    // first column (j = 0) as one operand of the condition is false then the
    // whole condition is false, then it will skip that condition and print
    // the value of n which is 4, but with the second column (j = 1) both
    // operands of && in the first condition of the second loop are true
    // as both value are bigger than 0, so it will execute its body which
    // decrement the value of n by 1 to be 3 and decrement the count to be 0
    // so, for the third column (j = 2) the value of count decremented
    // by the previous iteration and its value currently is 0, so it will go
    // to check for the condition which will be false as the count is not bigger
    // than 0 so it will skip the condition and print the current value of
    // displayed_digit variable as it is which is 3

    // So, for each row it will begin with 4 and decrement that number or not
    // based on the what row we are in?! as row 0 there will be no decrement
    // of any number, row 1 there will be only one decrement (4 3), for row 2
    // there will be 2 decrements (4 3 2), for row 3 there will be 3 decrements
    // (4 3 2 1) until the value of count reach 0.

    // So, now how we mirror these number to the upper-right corner, well with
    // a very simple condition that set that if the value of columns index is equal
    // to the current value of displayed_digit plus the value of n minus 1, then
    // the value of that element shall be incremented by one, that's it!

    // And now how to mirror the upper-left corner to the lower-left corner
    // well all the idea is at the value of count from 0 to 3, but as the rows
    // index goes from 0 to 6 the value of count will go also from 0 to 6 but
    // the right value the variable count should has are from 0 to 3 then we want
    // a simple equation in order to mirror the value of the higher indexes into
    // the corresponding index value that is smaller that middle index 3 so, the indexes
    // (4 5 6) must be converted to the indexes (2 1 0)

    //So, now we want the following:
    // count = 4 to be count = 2
    // count = 5 to be count = 1
    // count = 6 to be count = 0

    // And we can do it with a simple equation:
    // count  = i - ((i - (n - 1)) * 2)
    // where: i index of rows

    // So, if i = 4, 5, 6, then
    // count = 4 - ((4 - (4 - 1)) * 2) = 2
    // count = 5 - ((5 - (4 - 1)) * 2) = 1
    // count = 6 - ((6 - (4 - 1)) * 2) = 0
    // Mission Accomplished!

    // and with the same way of mirroring the upper-left to the upper-right corners
    // we will mirror the lower-left to the lower-right corners

    for(i = 0 ; i < n+n-1 ; i++)
    {
        count = i <= (n - 1) ? i : i - ((i - (n-1)) * 2);
        displayed_digit = n;
        for(j = 0; j < n+n-1 ; j++)
        {
            if((count > 0) && (j > 0))  // that condition controls the upper/lower left corners
            {
                displayed_digit--;
                count--;
            }
            else if (j == displayed_digit + n - 1)  // that condition controls the upper/lower right corners
            {
                displayed_digit++;
            }
            printf("%d ", displayed_digit);
        }
        printf("\n");
    }
    return 0;
}
