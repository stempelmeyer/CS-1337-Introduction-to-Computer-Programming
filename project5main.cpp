// Author:          Sarah G. Tempelmeyer
// Student ID:      sgt170030
// Course:          CS 1337.007
// Date:            4/17/2018
// Assignment:      Project #5
// Compiler:        Code::Blocks

// Description: This program converts roman numerals to Arabic
// numbers and vice versa using linked lists, nodes, and classes.
// It will give the user the option to sort, add, or delete a node.

// overload operators used in lines: 101 (>>) , 103 (+=), 108(--), 110(--), linkedlist.cpp 233(<<)

#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <iomanip>

#include "basenode.h"
#include "doublelinknode.h"
#include "linkedlist.h"

using namespace std;

// function prototypes
void sortFunction(LinkedList&);
bool compare(DoubleLinkNode*, DoubleLinkNode*);

const string FILE_NAME = "numbers3.txt";

int main()
{
    // declare variables and open file
    ifstream ifile(FILE_NAME);
    double userOption;
    string searchValue;

    // if the file doesn't open, display error and end program
    if(!ifile)
    {
        cout << "The file could not be opened" << endl;
        return 1;
    }

    // function call to initialize linked list
    LinkedList ParsedList;
    ParsedList.initialize(ifile);
    sortFunction(ParsedList);

    do // output menu options to the user
    {

        cout << "1. Search" << endl;
        cout << "2. Add" << endl;
        cout << "3. Delete head" << endl;
        cout << "4. Delete tail" << endl;
        cout << "5. Exit" << endl;
        cout << "6. Delete specific node" << endl;
        cout << "Please select an option from the menu above: ";
        cin >> userOption;

        // if user wants to search
        if(userOption == 1)
        {
            // prompt user for value and send into search function
            cout << "Please enter a search value: ";
            cin >> searchValue;

            // if the search value is an arabic number, validate it
            if (isdigit(searchValue.at(0)))
            {
                if (!ParsedList.validate("\0", stoi(searchValue)))
                {
                    cout << "Please enter a valid search value: " << endl;
                    continue; // output menu option again if invalid
                }
            }
            // if the search value is a roman number, validate it
            else
            {
                if (!ParsedList.validate(searchValue, -1))
                {
                    cout << "Please enter a valid search value: " << endl;
                    continue; // output menu option again if invalid
                }
            }
            // function call to search for the value and output if it was found or not
            if (ParsedList.searchMethod(searchValue) != -1)
                cout << searchValue << " was found in the linked list" << endl;
            // search method returned -1 meaning not found
            else
                cout << searchValue << " was not found in the linked list" << endl;
        }

        // if user wants to sort
        else if (userOption == 2)
        {
            DoubleLinkNode* newNode = new DoubleLinkNode;

            cin >> *(dynamic_cast<Node*>(newNode));

            ParsedList += newNode;

            sortFunction(ParsedList);
        }
        else if (userOption == 3)
            --ParsedList; // delete first node in the list
        else if (userOption == 4)
            ParsedList--;
        else if (userOption == 6)
        {
            int found;
            // prompt user for value and send into search function
            cout << "Please enter a value for the node you would like to delete: ";
            cin >> searchValue;

            found = ParsedList.searchMethod(searchValue);

            if(found != -1) // if the value is found
                ParsedList.deleteMethod(found);
            else
                cout << "The node you are attempting to delete does not exist" << endl;
        }
        for(DoubleLinkNode* current = ParsedList.getHead(); current!= nullptr; current = current->getNext())
            cout << setw(16) << left << current->getRoman() << " " << setw(4) << left << current->getArabic() << endl;
    } while(userOption != 5);

    ifile.close();
    ofstream ofile(FILE_NAME);

    if(!ofile)
    {
        cout << "The file could not be opened" << endl;
        return 1;
    }

    ParsedList.printList(ofile, ParsedList.getHead());

    // close file
    ofile.close();

    return 0;
} // end function main

// this function will sort the linked list based on the option chosen by the user
void sortFunction(LinkedList& ParsedList)
{
    // declare and initialize flip variable for while condition
    bool flipped = true;

    DoubleLinkNode* ptr = ParsedList.getHead();

    // sort through linked list until reaching the nullptr and until none of the values are flipped
    while(flipped)
    {
        ptr = ParsedList.getHead();
        // handle trivial cases if there is an empty list or only one node
        if(ptr == nullptr || ptr->getNext() == nullptr)
            return;
        flipped = false;
        // if first node must be switched
        if (compare(ptr, ptr->getNext()))
        {
            // swap the nodes and now have a new head
            ParsedList.setHead(ptr->getNext());
            flipped = true;
        }
        for(DoubleLinkNode* current = ptr->getNext(); current != nullptr; current = current->getNext())
        {
            // if the the values sent in the function need to be switched
            if(compare(current, current->getNext()))
            {
                // create temporary pointer and swap the nodes
                DoubleLinkNode* temp = current->getNext();
                current->setNext(temp->getNext());
                temp->setNext(current);
                temp->setPrev(current->getPrevious());
                current->setPrev(temp);
                if (current->getNext() != nullptr) // make sure current is not pointing to null
                    current->getNext()->setPrev(current);
                temp->getPrevious()->setNext(temp);
                flipped = true;
            }
            if(current->getNext() == nullptr)
                ParsedList.setTail(current);
        }
    }
} // end sort function

// this function will compare two values of nodes and send back true if they must be swapped, or false if they are in
bool compare(DoubleLinkNode* left, DoubleLinkNode* right)
{
    // if the nodes are null pointers, don't compare
    if(left == nullptr || right == nullptr)
        return false;
    else if(left->getArabic() > right->getArabic())
        return true;
    else
        return false;
}
