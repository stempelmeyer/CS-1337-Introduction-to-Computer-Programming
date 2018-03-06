// This program uses bubble sort and selection sort to order 8 values inputted by the user
// into ascending order

#include <iostream>
#include <cmath>

using namespace std;

// function prototypes and declare global constant
void bubbleSort(int bubble[], int maximum);
void selectionSort(int selection[], int maximum);
const int MAX_NUMS = 8;

int main()
{
   // declare arrays
   int bubble[MAX_NUMS];
   int selection[MAX_NUMS];

   // prompt the user to enter 8 integers
   cout << "Please enter 8 integers: ";

   // read in the input to the first and second arrays
   for (int i = 0; i < MAX_NUMS; i++) {
      cin >> bubble[i];
      selection[i] = bubble[i];
   }

   // display the contents of the first bubble array
   cout << endl << "Now displaying the contents of the bubble array:" << endl;
   for (int i = 0; i < MAX_NUMS; i++) {
      cout << bubble[i] << " ";
   }

   cout << endl << "Now organizing the array with bubble sorting" << endl;
   // function call the bubble sort
   bubbleSort(bubble, MAX_NUMS);

   // display the contents of the second selection array
   cout << endl << "Now displaying the contents of the selection array:" << endl;
   for (int i = 0; i < MAX_NUMS; i++) {
      cout << selection[i] << " ";
   }

   cout << endl << "Now organizing the array with selection sorting" << endl;
   // function call the bubble sort
   selectionSort(selection, MAX_NUMS);

   return 0;
}

// This function uses the bubble sort to order the array in ascending order
void bubbleSort(int bubble[], int maximum)
{
   // declare local variables
   bool flip = true;
   int minimum;

   // use do-while to continue sorting the array until nothing is moved
   while (flip)
   {
      // initialize swap to false
      flip = false;
      // for loop goes through array unless minimum is not the smallest number in the array
      // if it is not, the number will swap places with the smaller number and set swap to true
      for (int i = 1; i < maximum; i++) {
         minimum = bubble[i - 1];
         if (bubble[i] < minimum) {
            bubble[i - 1] = bubble[i];
            bubble[i] = minimum;
            flip = true;

            for (int i = 0; i < maximum; i++)
               cout << bubble[i] << " ";
            cout << endl;
         }
      }
   }
} // end function bubble sort

// This function uses selection sort to organize the array into ascending order
void selectionSort(int selection[], int maximum)
{
    // this outer for loop moves the minimum through the array
    for (int i = 0; i < (maximum-1); i++) {
        int minValue = selection[i];
        int minIndex = i;
        int temp;
        bool flip = false;
        // this inner for loop compares the current minimum with the rest of the array
        for (int j = i+1; j < maximum; j++){
           if (selection[j] < minValue){
           minValue = selection[j];
           minIndex = j;
           flip = true;
           }
        }
        temp = selection[i];
        selection[i] = minValue;
        selection[minIndex] = temp;
        // if the inner array found a new minimum, display the newly sorted array
        if (flip){
            for (int k = 0; k < maximum; k++)
                cout << selection[k] << " ";
            cout << endl;
        }
    }
} // end function selection sort
