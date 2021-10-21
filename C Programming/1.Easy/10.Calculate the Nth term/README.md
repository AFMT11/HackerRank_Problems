# Objective

- This challenge will help you learn the concept of recursion.

- A function that calls itself is known as a recursive function. The C programming language supports recursion. But while using recursion, one needs to be careful to define an exit condition from the function, otherwise it will go into an infinite loop.

- To prevent infinite recursion, if...else statement (or similar approach) can be used where one branch makes the recursive call and other doesn't.

void recurse() 
{
    .....
    recurse()  //recursive call
    .....
}
int main() 
{
    .....
    recurse(); //function call
    .....
}

# Task

There is a series,S, where the next term is the sum of pervious three terms. Given the first three terms of the series,a,b, and c respectively, you have to output the nth term of the series using recursion.

# Link of Challenge

https://www.hackerrank.com/challenges/recursion-in-c/problem