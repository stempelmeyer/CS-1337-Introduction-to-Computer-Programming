// Sarah Tempelmeyer and Preetika Kondepudi

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // declare variables and fstreams
    ifstream file("Random.txt");
    int numArray = 0;
    int highest;
    int lowest;
    int sum = 0;
    int average;

    // if file is not opened or doesn't exist
    if (!file)
        cout << "File \"Random.txt\" could not be opened" << endl;

    // while the file can read in a number, increment the numArray variable
    while (file >> highest)
        numArray++;

    // declare int pointer to dynamic array
    int* ptr = new int[numArray];

    // close and open file to read in at the beginning again
    file.close();
    file.open("Random.txt");

    // read in the first number and set to initial highest and lowest, and add to sum
    file >> *ptr;
    lowest = *ptr;
    highest = *ptr;
    sum = *ptr;

    // while file can read in a number, compare to the highest and lowest values, and increment pointer to read in next element
    while (file >> *ptr){
        if (*ptr < lowest)
            lowest = *ptr;
        if (*ptr > highest)
            highest = *ptr;

        // add to sum
        sum += *ptr;
        ptr++;
    }
    // average is sum divided by total numbers in array
    average = sum / numArray;

    // output highest, lowest, sum, and average
    cout << "The highest value: " << highest << endl;
    cout << "The lowest value: " << lowest << endl;
    cout << "The sum value: " << sum << endl;
    cout << "The average value: " << average << endl;

    // move ptr back to beginning of array to delete
    ptr -= numArray;
    delete [] ptr;

    return 0;
} // end function main
