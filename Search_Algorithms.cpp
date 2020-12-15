// This program runs through the linear and binary search
#include <iostream>

using namespace std;

int main()
{
    const int SIZE = 10;
    int array1[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int searchValue = 9;
    bool found = false;

    //searching with linear search
    cout << "First we will look for the search value by using the inefficient linear search" << endl;
    for (int i = 0; i < SIZE; i++){
        if (array1[i] == searchValue){
            cout << "The search value " << searchValue << " was found at index " << i << endl;
            found = true;
        }
    }
    if (!found)
        cout << "The search value " << searchValue << " was not found in the array" << endl;

    // searching with binary search
    cout  << "Next we will look for the search value by using the binary search" << endl;

    found = false;
    int start = 0;
    int last = SIZE - 1;
    int middle;

    while (!found && start < last)
    {
        middle = (start+last)/2;
        if (array1[middle] == searchValue){
            found = true;
        }
        if (array1[middle] < searchValue)
            start = middle + 1;
        if (array1[middle] > searchValue)
            last = middle - 1;
    }

    if (found)
        cout << "The search value " << searchValue << " was found at index " << middle << endl;
    else
        cout << "The search value " << searchValue << " was not found in the array" << endl;

    return 0;
}
