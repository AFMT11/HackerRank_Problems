# Objective

An array is a container object that holds a fixed number of values of a single type. To create an array in C, we can do int arr[n];. Here, arr, is a variable array which holds up to 10 integers. The above array is a static array that has memory allocated at compile time. A dynamic array can be created in C, using the malloc function and the memory is allocated on the heap at runtime. To create an integer array, arr of size n, int *arr = (int*)malloc(n * sizeof(int)), where arr points to the base address of the array. When you have finished with the array, use free(arr) to deallocate the memory.

# Task

In this challenge, create an array of size n dynamically, and read the values from stdin. Iterate the array calculating the sum of all elements. Print the sum and free the memory where the array is stored.

# Link of Challenge

https://www.hackerrank.com/challenges/1d-arrays-in-c/problem