#include <iostream>
#include <cstdlib>
#include "array.h"
using namespace std;

// default constructor function
Arrays::Arrays()
{
    ptr = new float[10];
    for (int i = 0; i < 10; i++)
        ptr[i] = 0;
    numElements = 10;
}
Arrays::Arrays(unsigned int size)
{
    ptr = new float[size];
    for (int i = 0; i < size; i++)
        ptr[i] = 0;
    numElements = size;
}
bool Arrays::isValid(int location)
{
    if (location > (numElements - 1) || location < 0){
        cout << "Invalid Subscript" << endl;
        return false;
    }
    return true;
}
Arrays::~Arrays()
{
    // free the dynamically allocated memory
    delete [] ptr;
}
void Arrays::initialize(float num, int location)
{
    // if the function call to isValid returns true
    if (isValid(location))
        ptr[location] = num;
}
float Arrays::retrieve(int get)
{
    // if the function call to isValid returns true
    if(isValid(get))
        return ptr[get];
    // else
        return 100000000;
}

float Arrays::highest()
{
    float highest = ptr[0];
    for (int i = 1; i < numElements; i++){
        if (ptr[i] > highest)
            highest = ptr[i];
    }
    return highest;
}

float Arrays::lowest()
{
    float lowest = ptr[0];
    for (int i = 1; i < numElements; i++){
        if (ptr[i] < lowest)
            lowest = ptr[i];
    }
    return lowest;
}

float Arrays::average()
{
    float sum;
    for (int i = 0; i < numElements; i++){
        sum += ptr[i];
    }
    return sum / numElements;
}
