// Author:          Sarah G. Tempelmeyer
// Net ID:          sgt 170030
// Course:          CS 1337.007
// Date:            4/24/2018
// Assignment:      Homework 9
// Compiler:        Code::Blocks

// Description: This program uses classes and inheritance filter the
// characters in a file. It will use three separate derived classes for
// manipulation by encryption, conversion to uppercase, and copying

#include <iostream>
#include <fstream>

#include "abstract.h"
#include "filter1.h"
#include "filter2.h"
#include "filter3.h"

using namespace std;

int main()
{
    // create objects from classes and file streams
    Encryption obj1;
    Uppercase obj2;
    Copy obj3;
    ifstream ifile("sample.txt");
    ofstream ofile;

    // if files are not opened properly
    if (!ifile)
    {
        cout << "Input file could not be opened" << endl;
        return 1;
    }

    if (!ofile)
    {
        cout << "Output file could not be opened" << endl;
        return 1;
    }

    // open the output file, call the filter method, and close both files
    ofile.open("output1.txt");
    obj1.doFilter(ifile, ofile);
    ifile.close();
    ofile.close();

    // open the input and output file, call the filter method, and close both files
    ifile.open("sample.txt");
    ofile.open("output2.txt");
    obj2.doFilter(ifile, ofile);
    ifile.close();
    ofile.close();

    // open the input and output file, call the filter method, and close both files
    ifile.open("sample.txt");
    ofile.open("output3.txt");
    obj3.doFilter(ifile, ofile);
    ifile.close();
    ofile.close();

    return 0;
}
