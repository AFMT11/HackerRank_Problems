#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char ch = 0;
    char s[100], sen[100];

    scanf("%c", &ch); // Read a character from the user
    scanf("%s", s); // Read a string from the user
    scanf("\n"); // Read a new-line character from the user
    scanf("%[^\n]%*c", sen);
    /*
     As this statement will be terminated once
     the new-line character has been entered,
     and because every scanf terminates by new-line character
     then when we enter the string input in s variable any then
     hit enter then this new-line character will be added as
     an input to the current scanf function which is set
     to be terminated by (\n) so that this function won't
     take any inputs as the first input it takes is the character
     that it need to terminate, so it will terminate silently!
     so, to overcome that problem we set scanf function right above
     the current scanf function which will read that new-line character
    */
    printf("%c\n", ch);
    printf("%s\n", s);
    printf("%s\n", sen);

    return 0;
}
