// Author:          Sarah G. Tempelmeyer
// Net ID:          sgt 170030
// Course:          CS 1337.007
// Date:            2/14/2018
// Assignment:      Review Homework #4
// Compiler:        Code::Blocks

// Description: This C program uses dynamic memory allocation and pointer arithmetic
// to validate a correct Sudoku solution

// function prototype
char* descending(char*);

#include <iostream>

using namespace std;

int main()
{
    // declare and initialize a pointer to a dynamic char array of size 10
    char* location = new char[10];

    cout << "This program will organize your numbers (or letters) in descending order." << endl << "Please enter 10 characters." << endl;

    // read in 10 characters into the dynamic array
    for(int i = 0; i < 10; i++, location++)
        cin >> *location;

    // move the pointer back to the beginning of the array to output the array using pointer arithmetic
    location -=10;
    cout << "This is the unsorted array: ";
    for (int i = 0; i < 10; i++, location++)
        cout << *location << " ";
    cout << endl;

    // send the pointer (at the beginning of the array) to function descending
    location = descending(location - 10);

    // output the sorted array
    cout << "This is the sorted array: ";
    for (int i = 1; i <= 10; i++, location++)
        cout << *location << " ";
    cout << endl;

    // move the pointer to the beginning of the array to delete
    location -= 10;
    delete [] location;

    return 0;
}

// This function returns a pointer back to the sorted dynamic char array
// It's parameter is a char pointer to the array that must be sorted
char* descending(char* ptr){
    // declare and initialize local variables and pointers
    bool flip = true;
    char* after = ptr + 1;
    char temp;

    // while the array is still in incorrect order (or hasn't checked one last time)
    while(flip){
        flip = false;
        // enter for loop to compare each element with the one after it
        for(int i = 1; i < 10; i++, ptr++, after++){
            // if the element after one of the elements is bigger, than swap them and set bool flip to true
            if (*ptr < *after){
                temp = *ptr;
                *ptr = *after;
                *after = temp;
                flip = true;
            }
        }
        // move pointers back to the beginning, and beginning plus one to compare in while loop again
        ptr -= 9;
        after -= 9;
    }
    // return the pointer which should be at the beginning of the array
    return ptr;
}
