// quick sort explanation program

#include <iostream>

using namespace std;

void quickSort(int [], int, int);
int partitionn(int[], int, int);
void swapp(int&, int &);

int main()
{
    const int SIZE = 10;
    int num;
    int array1[SIZE] = {13, 43, 74, 34, 21, 12, 9, 52, 27, 11};

    // display array contents
    cout << "Displaying array contents in main... " << endl;
    for(num = 0; num < SIZE; num++)
        cout << array1[num] << " ";
    cout << endl;

    // sort the array
    cout << "Sending to quickSort array..." << endl;
    quickSort(array1, 0, SIZE-1);

    // display array contents
    cout << "Displaying array contents in main... " << endl;
    for(num = 0; num < SIZE; num++)
        cout << array1[num] << " ";
    cout << endl;

    return 0;
}

void quickSort(int arr[], int start, int endd)
{
    cout << "Now in quickSort function" << endl;
    int pivotPoint;

    if (start < endd)
    {
        // Get the pivot point
        pivotPoint = partitionn(arr, start, endd);
        // sort the first sublist
        cout << "Now sorting the first sublist with pivot point: " << pivotPoint << endl;
        quickSort(arr, start, pivotPoint - 1);
        // sort the second sublist
        cout << "Now sorting the second sublist with pivot point: " << pivotPoint << endl;
        quickSort(arr, pivotPoint + 1, endd);
    }
} // end function quickSort

int partitionn(int arr[], int start, int endd)
{
    int pivotIndex = start;
    for(int scan = start; scan <= endd - 1; scan++)
    {
        if(arr[scan] < arr[endd])
        {
            cout << arr[scan] << " is less than " << arr[endd] << " so swapping these elements... " << endl;
            swapp(arr[pivotIndex], arr[scan]);
            pivotIndex++;
            cout << "The array is now" << endl;
            for (int i = 0; i < 10; i++)
                cout << arr[i] << " ";
            cout << endl << "And the pivot index has been incremented to " << pivotIndex << endl;
        }
    }
    cout << "Now swapping the last element of the partition with the pivot index: " << pivotIndex << endl;
    swapp(arr[endd], arr[pivotIndex]);
    cout << "The array is now" << endl;
    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    cout << endl;
    return pivotIndex;
} // end function partition

void swapp(int &value1, int &value2)
{
    int temp = value1;

    value1 = value2;
    value2 = temp;
} // end function swap
