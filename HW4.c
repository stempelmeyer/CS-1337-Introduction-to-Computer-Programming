// Author:          Sarah G. Tempelmeyer
// Net ID:          sgt 170030
// Course:          CS 1337.007
// Date:            2/14/2018
// Assignment:      Review Homework #4
// Compiler:        Code::Blocks

// Description: This C program uses dynamic memory allocation and pointer arithmetic
// to organize a 10 char array in descending order with a bubble sort

// function prototype
char* descending(char*);

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // declare and initialize a pointer to a dynamic char array of size 10
    char* location = (char*)calloc(10, sizeof(char));

    printf("This program will organize your numbers (or letters) in descending order.\n");
    printf("Please enter 10 characters.\nIf you enter more than 10, it will only analyze the first 10\n");

    // read in 10 characters into the dynamic array
    for(int i = 0; i < 10; i++, location++)
    {
        scanf("%c", location);
        if (*location == ' ' || *location == '\n')
        {
            location --;
            i--;
        }
    }

    // move the pointer back to the beginning of the array to output the array using pointer arithmetic
    location -=10;
    printf("This is the unsorted array: ");
    for (int i = 0; i < 10; i++, location++)
        printf("%c ",*location);
    printf("\n");

    // send the pointer (at the beginning of the array) to function descending
    location = descending(location - 10);

    // output the sorted array
    printf("This is the sorted array: ");
    for (int i = 1; i <= 10; i++, location++)
        printf("%c ", *location);
    printf("\n");

    // move the pointer to the beginning of the array to delete
    location -= 10;
    free(location);

    return 0;
}

// This function returns a pointer back to the sorted dynamic char array
// It's parameter is a char pointer to the array that must be sorted
char* descending(char* ptr)
{
    // declare and initialize local variables and pointers
    int flip = 1;
    char* after = ptr + 1;
    char temp;

    // while the array is still in incorrect order (or hasn't checked one last time)
    while(flip)
    {
        flip = 0;
        // enter for loop to compare each element with the one after it
        for(int i = 1; i < 10; i++, ptr++, after++)
        {
            // if the element after one of the elements is bigger, than swap them and set flip to true
            if (*ptr < *after)
            {
                temp = *ptr;
                *ptr = *after;
                *after = temp;
                flip = 1;
            }
        }
        // move pointers back to the beginning, and beginning plus one to compare in while loop again
        ptr -= 9;
        after -= 9;
    }
    // return the pointer which should be at the beginning of the array
    return ptr;
}
