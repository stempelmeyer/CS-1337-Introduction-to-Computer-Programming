// Author:          Sarah G. Tempelmeyer
// Net ID:          sgt 170030
// Course:          CS 1337.007
// Date:            3/31/2018
// Assignment:      Homework 7
// Compiler:        Code::Blocks

// Description: This program uses classes to dynamically allocate an array,
// store and retrieve numbers at a certain index, and return the highest,
// lowest, and average numbers in an array.

#include <iostream>
#include "array.h"

using namespace std;

int main()
{
    int index;
    int option;
    float value;
    Arrays arr;

    do {
        cout << "1. Store a number in the array" << endl;
        cout << "2. Retrieve a number from the array" << endl;
        cout << "3. Find the highest number from the array" << endl;
        cout << "4. Find the lowest number from the array" << endl;
        cout << "5. Find the average number from the array" << endl;
        cout << "6. Exit" << endl;
        cout << "Please choose an option from the menu above" << endl;
        cin >> option;

        while (option < 1 || option > 6){
            cout << "Please choose a valid option from the menu above" << endl;
            cin >> option;
        }

        switch (option)
        {
        case 1:
            cout << "What number would you like to add to the array: ";
            cin >> value;
            cout << "At what index would you like to add to the array: ";
            cin >> index;
            arr.initialize(value, index);
            break;
        case 2:
            cout << "At what index would you like to retrieve a number from the array: ";
            cin >> index;
            value = arr.retrieve(index);
            if (value != 100000000)
                cout << "The number at " << index << " is " << value << endl;
            break;
        case 3:
            cout << "The highest number in the array is " << (arr.highest()) << endl;
            break;
        case 4:
            cout << "The lowest number in the array is " << (arr.lowest()) << endl;
            break;
        case 5:
            cout << "The average of the array is " << (arr.average()) << endl;
            break;
        }
    } while (option != 6);
    return 0;
}
