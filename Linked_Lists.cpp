// Author:          Sarah G. Tempelmeyer
// Net ID:          sgt 170030
// Course:          CS 1337.007
// Date:            3/3/2018
// Assignment:      Sample Program Linked Lists
// Compiler:        Code::Blocks

// Description: This program uses linked lists to read students names, IDs, and 5 tests.
// It will calculate the average of the test grades and sort the names in alphabetical order.
// It will also output the graduating students.

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// declare structure
struct student
{
    string name;
    string ID;
    int *tests;
    float avg = 0.0;
    char grade = ' ';
    student* next = nullptr;
};

// function prototypes
void getStudents(student*&);
void calcAvg(student*);
void outputStudents(student*);
student* graduate(student*&, string);

int main()
{
    student *head = nullptr;

    getStudents(head);
    calcAvg(head);
    cout << "Student Roster" << endl;
    outputStudents(head);

    student* grad = graduate(head, "Cyclops");

    if (grad)
    {
        cout << endl << endl << "Graduating Students: " << endl << grad->name;
        cout << endl << endl << grad->avg << endl << grad->grade << endl << endl;
        delete [] grad->tests;
        delete grad;
    }

    cout << endl << "Student Roster" << endl;
    outputStudents(head);

    while (head)
    {
        student* hold = head;
        head = head->next;
        delete [] hold->tests;
        delete hold;
    }

    cin >> head->ID;
    return 0;
} // end function main

void getStudents(student *&h)
{
    // declare string and file which is opened
    ifstream input("students.txt");
    string first, last;
    // while not at the end of the file, read in the next student
    while (!input.eof())
    {
        // create a pointer to a new student structure
        student* newNode = new student;
        // the tests ptr member will be a new array of 5 elements
        newNode->tests = new int[5];

        // read in the first and last names and combine
        input >> first >> last;
        first = first + " " + last;
        // the name is assigned to the structure using a ptr
        newNode->name = first;
        // read in the next string to ID using a ptr
        input >> newNode->ID;
        // read in 5 tests to the dynamic array
        for (int j =0; j < 5; j++)
        {
            input >> *newNode->tests;
            (newNode->tests)++;
        }
        newNode->tests -= 5;

        // if this is the first student, header should point to it
        if (!h)
            h = newNode;
        // if the name belongs before the first student structure
        else if(newNode->name < h->name)
        {
            // point new node next to where h is pointing at
            newNode->next = h;
            // the header now points at the student at the front
            h = newNode;
        }
        // if student goes in the middle or end
        else
        {
            // declare new pointer and
            student *p2;
            p2 = h;
            // if ptr2 is not the last and the the name of the student after ptr2 is less than the read in name
            while(p2->next && p2->next->name < newNode->name)
                // move ptr forward
                p2 = p2->next;
            // point the newnode to what ptr is pointing to
            newNode->next = p2->next;
            // ptr next should point to the new node
            p2->next = newNode;
        }
    } // end while loop
} // end function get students

void calcAvg(student *ptr)
{
    int sum;
    while (ptr)
    {
        sum = 0;
        for (int j = 0; j < 5; j++)
            sum += ptr->tests[j];
        ptr->avg = sum / 5;

        if (ptr->avg >= 90)
            ptr->grade = 'A';
        else if (ptr->avg >= 80)
            ptr->grade = 'B';
        else if (ptr->avg >= 70)
            ptr->grade = 'C';
        else if (ptr->avg >= 60)
            ptr->grade = 'D';
        else
            ptr->grade = 'F';
        ptr = ptr->next;
    }
}
void outputStudents(student *ptr)
{
    // while the ptr is not null
    while (ptr)
    {
        // output info and move pointer to the next one
        cout << ptr->name << endl << ptr->ID << endl << ptr->avg << endl << ptr->grade << endl << endl;
        ptr = ptr->next;
    }
} // end function outputStudents

student* graduate(student* &h, string id)
{
    // if the list is empty
    if (!h)
        return nullptr;
    // if the search name is pointed at by head
    else if (h->ID == id)
    {
        // create pointer that holds the first structure
        student* hold = h;
        // move the head forward
        h = h->next;
        // make sure found structure is disconnected from rest
        hold->next = nullptr;
        // return found structure
        return hold;
    }
    // if search name is in the middle or end
    else
    {
        // create pointer to head
        student* p1 = h;
        // if not at the null ptr and the next id is not equal to the search name, increment ptr
        while (p1->next && p1->next->ID != id)
            p1 = p1->next;
        // if ptr next id is the search name
        if(p1->next->ID == id)
        {
            // hold that structure
            student* hold = p1->next;
            // connect to next id
            p1->next = p1->next->next;
            // make sure found structure is disconnected from rest
            hold->next = nullptr;
            // return the found structure
            return hold;
        }
    }
    // if search name is not found
    return nullptr;
}
