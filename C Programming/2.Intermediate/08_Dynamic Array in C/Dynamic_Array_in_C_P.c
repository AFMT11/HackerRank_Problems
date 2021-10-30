#include <stdio.h>
#include <stdlib.h>

/*
 * This stores the total number of books in each shelf.
 */
int* total_number_of_books;

/*
 * This stores the total number of pages in each book of each shelf.
 * The rows represent the shelves and the columns represent the books.
 */
int** total_number_of_pages;

/**
    In this challenge all we need to do is to deal with
    multi-dimension dynamic arrays, arrays that are not
    stored in the Stack but in the Heap where their size
    is determined during the runtime.
*/


int main()
{
    int total_number_of_shelves, i, counter = 0;
    scanf("%d", &total_number_of_shelves); // scan the number of shelves from the user

    /*
        Here we created a pointer to integer one dimension
        dynamic array to store the number of books on each
        shelve in the library.
    */
    total_number_of_books = (int*) malloc(sizeof(int) * total_number_of_shelves);

    // in this for loop we zeros all the elements of the previously created dynamic array
    for(counter = 0; counter < total_number_of_shelves; counter++)
    {
        total_number_of_books[counter] = 0;
    }

    /*
        and here we created a pointer to pointer to integer
        two dimension array to store the address that represent
        each shelve in the library, that address will be further
        carry the address of pointer to integer one dimension
        dynamic array its size will be the number of maximum
        number of books allowed on each shelve, and that array
        is supposed to store the number of pages of each book
        which mean of each element of that one dimension dynamic array.
    */
    total_number_of_pages = (int**) malloc(sizeof(int*) * total_number_of_shelves);

    for(counter = 0; counter < total_number_of_shelves; counter++)
    {
        total_number_of_pages[counter] = (int*) malloc(sizeof(int) * 1100);
    }
    int total_number_of_queries;
    scanf("%d", &total_number_of_queries);

    while (total_number_of_queries--)
    {
        int type_of_query;
        scanf("%d", &type_of_query);

        if (type_of_query == 1)
        {
            /*
             * Process the query of first type here.
             */
            int x, y;
            scanf("%d %d", &x, &y);
            *(*(total_number_of_pages + x) + total_number_of_books[x]) = y;
            total_number_of_books[x]++;

        }
        else if (type_of_query == 2)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", *(*(total_number_of_pages + x) + y));
        }
        else
        {
            int x;
            scanf("%d", &x);
            printf("%d\n", *(total_number_of_books + x));
        }
    }

    if (total_number_of_books)
    {
        free(total_number_of_books);
    }

    for (i = 0; i < total_number_of_shelves; i++)
    {
        if (*(total_number_of_pages + i))
        {
            free(*(total_number_of_pages + i));
        }
    }

    if (total_number_of_pages)
    {
        free(total_number_of_pages);
    }

    return 0;
}
