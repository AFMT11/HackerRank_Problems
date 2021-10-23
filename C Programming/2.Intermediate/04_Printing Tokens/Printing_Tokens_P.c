#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char *s;
    int i;
    s = malloc(1024 * sizeof(char)); // create a dynamic array of characters of size 1024 byte
    scanf("%[^\n]%*c", s); // scan the whole string from the user
    s = realloc(s, strlen(s) + 1); // reallocate the new actual size of the array at the same address (s)
    //Write your logic to print the tokens of the sentence here.

    // for loop to check for every character if that character is not a space then
    // print that character, otherwise print a new line. that's it!
    for(i = 0; i < strlen(s); i++) // for loop to check for every character
    {
        printf("%c", s[i]);
        s[i] == ' ' ? printf("\n") : printf("");
    }

    return 0;
}
