// This program uses bubble and selection sorting algorithms
#include <iostream>

using namespace std;

int main()
{
    const int SIZE = 10;
    int array1[SIZE] = {3, 5, 4, 1, 6, 9, 8, 2, 7, 10};
    int array2[SIZE] = {3, 5, 4, 1, 6, 9, 8, 2, 7, 10};
    bool flip = true;
    int temp;

    cout << "Now organizing the first array with the bubble sort" << endl;
    cout << "Displaying the unsorted first array before the selection sort" << endl;
    for(int i = 0; i < SIZE; i++)
        cout << array1[i] << " ";
    cout << endl;
    while (flip)
    {
        flip = false;
        for (int i = 0; i < SIZE - 1; i++)
        {
            if (array1[i] > array1[i+1]) // just flip the conditional to change the sorting order
            {
                flip = true;
                temp = array1[i];
                array1[i] = array1[i+1];
                array1[i+1] = temp;
            }
        }
    }
    cout << "Displaying the sorted first array after the bubble sort" << endl;
    for(int i = 0; i < SIZE; i++)
        cout << array1[i] << " ";
    cout << endl;

    cout << "Now organizing the second array with the selection sort" << endl;
    cout << "Displaying the unsorted second array before the selection sort" << endl;
    for(int i = 0; i < SIZE; i++)
        cout << array2[i] << " ";
    cout << endl;
    int minimum;
    int minimumIndex;
    int smallest;
    for (smallest = 0; smallest < SIZE - 1; smallest++)
    {
        minimum = array2[smallest];
        minimumIndex = smallest;
        for (int i = smallest + 1; i < SIZE; i++)
        {
            if (array2[i] < minimum)
            {
                minimum = array2[i];
                minimumIndex = i;
            }
        }
        temp = array2[smallest];
        array2[smallest] = array2[minimumIndex];
        array2[minimumIndex] = temp;
    }

    cout << "Displaying the sorted second array after the selection sort" << endl;
    for(int i = 0; i < SIZE; i++)
        cout << array2[i] << " ";
    cout << endl;

    return 0;
}
