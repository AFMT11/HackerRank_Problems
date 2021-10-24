#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
void sort_by_area(triangle* tr, int n)
{
	/**
	* Sort an array a of the length n
	*/
    int i, j;
    float P_i, S_i, P_j, S_j;

    // to sort an array we will use selection sort algorithm
    // So, for every triangle element of tr dynamic array, we
    // will calculate the area of that element and calculate the
    // areas for every single element after it and compare the
    // two areas, and if the first area is larger than the second
    // one, then we will assign the second area to be the area
    // of the first element and swap the values of (a, b, c)
    // of those two elements
    for(i = 0; i < n-1; i++)
    {
        P_i = (float)(tr[i].a + tr[i].b + tr[i].c) / 2;
        // S_i is a temporary place to store the area of the current i element
        S_i = sqrt(P_i * (P_i - tr[i].a) * (P_i - tr[i].b) * (P_i - tr[i].c));
        for(j = i+1; j < n; j++)
        {
            P_j = (float)(tr[j].a + tr[j].b + tr[j].c) / 2;
            // S_j is a temporary place to store the area of the current j element
            S_j = sqrt(P_j * (P_j - tr[j].a) * (P_j - tr[j].b) * (P_j - tr[j].c));

            // if the area of the first element is bigger than
            // the area of the second one, execute the following:
            if(S_i > S_j)
            {
                S_i = S_j; // assign the area of the second element to be the area of the first one

                //Swap the values of (a) side of the triangles of the two elements
                tr[i].a = tr[i].a + tr[j].a;
                tr[j].a = tr[i].a - tr[j].a;
                tr[i].a = tr[i].a - tr[j].a;

                //Swap the values of (b) side of the triangles of the two elements
                tr[i].b = tr[i].b + tr[j].b;
                tr[j].b = tr[i].b - tr[j].b;
                tr[i].b = tr[i].b - tr[j].b;

                //Swap the values of (c) side of the triangles of the two elements
                tr[i].c = tr[i].c + tr[j].c;
                tr[j].c = tr[i].c - tr[j].c;
                tr[i].c = tr[i].c - tr[j].c;
            }
        }
    }
}

int main()
{
	int n, i;
	scanf("%d", &n); // scan the number of triangles from the user
	triangle *tr = malloc(n * sizeof(triangle)); // create a dynamic array of n triangle objects
	for (i = 0; i < n; i++) // take
    {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n); // sort the triangles by ascending order
	for (i = 0; i < n; i++) // print the triangles by ascending order, each one at a separate line
	{
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
