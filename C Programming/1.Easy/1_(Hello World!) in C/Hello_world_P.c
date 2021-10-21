#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int main()
{
    char s[100]; // An array of 100 reserved element
    scanf("%[^sa]%*c", &s); // take a string as an input from the user
	                        // and it is done by that way as (%s) with scanf function
							// sees any spaces as a termination to that string
							// but with this way it will not terminate until we hit Enter

    printf("Hello, World!\n"); // print the string 'Hello World!' on the first line
    printf("%s", s); // print the input string from the user on the second line
    return 0;
}
