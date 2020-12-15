// Author:          Sarah G. Tempelmeyer
// Student ID:      sgt170030
// Course:          CS 1337.007
// Date:            4/7/2018
// Assignment:      Project #4
// Compiler:        Code::Blocks
// DELETE THE LIST RECURSIVELY
// IMPLEMENT AN OVERLOAD << OPERATOR

// Description: Evaluate polynomial expressions from a file by
// using a linked list through classes, multiple classes that
// interact, and recursive procedures on a simple data structure

#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include "Node.h"
#include "Linkedlist.h"

using namespace std;

// function prototypes
void parseLine (string, Linkedlist);
double calculate(Node*, double);

int main()
{
    // declare variables and open input file
    ifstream ifile("poly1.txt");
    double evaluateAt;
    string line;

    // validate if the input file opened correctly
    if (!ifile)
    {
        cout << "The file \"poly.txt\" could not be opened" << endl;
        return 1;
    }
    // parse each line in the file with a while loop
    while(!ifile.eof())
    {
        Linkedlist linkedlist;                                   // dynamically allocate new linked list
        getline(ifile, line);
        // if at the last line
        if (line.length() == 0)
            continue;
        evaluateAt = stod(line.substr(2, line.find(')')));       // cuts line to assign double value of x
        linkedlist.setEvaluate(evaluateAt);                      // set the x-value for the linked list
        line = line.substr(line.find('=') + 2, line.length());   // line begins right after ") = "
        parseLine(line, linkedlist);                             // send line to function to be parsed
    }

    return 0;
} // end function main

// this function parses the line into node terms and prints it out
void parseLine (string line, Linkedlist linkedlist)
{
    // declare variables
    string term;
    int index;
    // while the line has more terms
    while (line.length() > 0)
    {
        Node *nodePtr = new Node;                       // dynamically allocate memory for new term
        linkedlist.addNode(nodePtr);
        if (isdigit(line.at(0)) || line.at(0) == 'x')        // if the sign of the first term is positive
            nodePtr->setOperation('+');
        else if (line.at(0) == '-' && line.at(1) != ' ')      // if the sign of the first term is negative
        {
            nodePtr->setOperation('-');
            line = line.substr(1);
        }
        else if (line.at(0) == '-' && line.at(1) == ' ')      // if the sign of the following terms is subtraction
        {
            nodePtr->setOperation('-');
            line = line.substr(2);
        }
        else if (line.at(0) == '+' && line.at(1) == ' ')    // if the sign of the following terms is addition
        {
            nodePtr->setOperation('+');
            line = line.substr(2);
        }
        index = line.find(' ');
        if (index != -1)  // if not at last term
        {
            term = line.substr(0, index);
            line = line.substr(index+1);
        }
        else  // at last term
        {
            term = line;
            line = "";
        }
        // function call to set the coefficients and the exponents
        linkedlist.splitTerms(term, nodePtr);
    }
    // open the output file to print out that line and the solution
    ofstream ofile("answers.txt", ios::app);
    linkedlist.combineTerms(linkedlist.getListHead()); // combine similar exponent
    linkedlist.sortLinkedlist(linkedlist.getListHead()); // sort into standard form
    ofile << linkedlist;
    ofile.close();
}
