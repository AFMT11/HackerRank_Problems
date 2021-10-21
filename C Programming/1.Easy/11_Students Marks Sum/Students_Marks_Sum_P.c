#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//Complete the following function.

int marks_summation(int* marks, int number_of_students, char gender)
{
  // variable gg will store the initializing index of marks
  // based on what character is entered by the user
  // So, if the character is 'b' then gg will store 0,
  // otherwise it will store 1
  int sum = 0, gg = gender == 'b' ? 0 : 1;

  // for loop to loop over the indexes of boys (0,2,4) or
  // girls (1,3,5) and sum the values of their marks stored
  // in marks array and return that total sum!
  for(; gg < number_of_students ; gg += 2)
      sum += marks[gg];

  return sum;
}

int main() {
    int number_of_students;
    char gender;
    int sum, student;

    scanf("%d", &number_of_students);
    int *marks = (int *) malloc(number_of_students * sizeof (int));

    for (student = 0; student < number_of_students; student++) {
        scanf("%d", (marks + student));
    }

    scanf(" %c", &gender);
    sum = marks_summation(marks, number_of_students, gender);
    printf("%d", sum);
    free(marks);

    return 0;
}
