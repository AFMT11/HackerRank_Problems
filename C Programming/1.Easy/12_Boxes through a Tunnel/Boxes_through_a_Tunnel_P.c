#include <stdio.h>
#include <stdlib.h>
#define MAX_HEIGHT 41

struct box // object (struct box)
{
	/**
	* Define three fields of type int: length, width and height
	*/
    int length;
    int width;
    int height;
};

typedef struct box box; // rename the name of the struct from (struct box) into (box)

int get_volume(box b) // A function to return the volume of the input struct box
{
	/**
	* Return the volume of the box
	*/
    int V_box = b.height * b.length * b.width;
    return V_box;
}

int is_lower_than_max_height(box b) // A function to check if the height of the box is smaller than 41
{
	/**
	* Return 1 if the box's height is lower than MAX_HEIGHT and 0 otherwise
	*/
    int check = b.height >= 41 ? 0 : 1;
    return check;
}

int main()
{
	int n, i;
	scanf("%d", &n);
	box *boxes = malloc(n * sizeof(box)); // create an array of n box in the heap memory

	// for loop to take from the user the dimensions (length, width, height) of each box
	for (i = 0; i < n; i++)
    {
		scanf("%d%d%d", &boxes[i].length, &boxes[i].width, &boxes[i].height);
	}

	//for loop to check for every box height if its height is lower
	// than the maximum height of the tunnle, and if so, then
	// print the volume of that box!
	for (i = 0; i < n; i++)
    {
		if (is_lower_than_max_height(boxes[i]))
        {
			printf("%d\n", get_volume(boxes[i]));
        }
    }
	return 0;
}
