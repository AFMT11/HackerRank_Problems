#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();



int main()
{
    char* n_endptr;
    char* n_str = readline();
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    // Write Your Code Here
    char *arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    // So, here we created an array of 9-literals (Strings)
    // then we make a condition to check if the entered number
    // by the user is within a range from 1 to 9, if so then
    // print the corresponding string of an index equal to n
    // as if the entered number is 6 then the corresponding element
    // of index 6 is "six", and so on! but if the enter number is not
    // in the range then simply print "Greater than 9"

    if(n >= 1 && n <= 9)
    {
        printf("%s", arr[n]); // print the value of indexes from 1 to 9
    }
    else
    {
        printf("Greater than 9");
    }

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}
