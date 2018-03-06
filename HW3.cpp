// Author:          Sarah G. Tempelmeyer
// Course:          CS 1337.007
// Date:            1/29/2018
// Assignment:      Review Homework #3
// Compiler:        Code::Blocks

// Description: This program uses recursion to display every odd
//  subscript of an array, and displays a string in reverse order

#include <iostream>
#include <string>

using namespace std;

// function prototype with default arguments
int oddSum(int arr1[], int arraySize = 0);
void reverseString(string forwards, int subscript = -5);

// declare global constant of the max array size
const int ARRAY_SIZE = 11;

int main()
{
    // declare array, function call and output the sum of odd array subscripts
    int array1[ARRAY_SIZE] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55};
    cout << "Sum of odd elements in integer array: " << oddSum(array1) << endl;

    // declare the string that will be displayed in reverse and function call
    string forwards = "Backwards";
    reverseString(forwards);

    return 0;
} // end function main

// this function uses the array and 0 as argument
int oddSum(int arr1[], int i){
    // recursive call until not less than size -1
    if (i < ARRAY_SIZE-1)
        return arr1[i] + oddSum(arr1, i+2);
    // if the array size is odd and at last element, return element
    else if ((i = ARRAY_SIZE - 1)&& (ARRAY_SIZE % 2 == 1))
        return arr1[i];
    // if equal to size, there won't be a number so return 0
    else
        return 0;
} // end function odd sum and return sum of odd subscripts in integer array

// this function uses a string argument to display the reverse string
void reverseString(string forwards,int subscript){
    // using sentinel default parameter, initialize max subscript once
    if (subscript == -5)
    subscript = (forwards.length()-1);
    // using recursion, display element and decrement subscript
    if (subscript > 0){
        cout << forwards.at(subscript);
        reverseString(forwards, subscript-1);
    }
    // output first element. don't call function again when at first subscript
    if (subscript == 0)
    cout << forwards.at(subscript);
} // end function reverse string
