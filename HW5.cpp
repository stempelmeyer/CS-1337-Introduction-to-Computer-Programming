// Author:          Sarah G. Tempelmeyer
// Net ID:          sgt 170030
// Course:          CS 1337.007
// Date:            3/3/2018
// Assignment:      Homework 5
// Compiler:        Code::Blocks

// Description: This program uses linked lists to enter numbers and take out numbers from a
// queue. It uses recursive functions to print out values to the console.

#include <iostream>

using namespace std;

// declare structure with int value and pointer to next structure
struct queue
{
    int value;
    queue* next = nullptr;
};

// function prototypes
int enQueue(int, queue*);
int deQueue(queue*&);
char recursive(char, queue*);

int main()
{
    // declare variables create a dynamically allocated array with elements 1-5
    queue* head = new queue[5];

    queue* p2;
    p2 = head;
    for (int i = 1; i <= 5; i++)
    {
        head++;
        // point the structures to the next ones
        if (i != 5)
            p2->next = head;
        // assign the values in the queue with 1-5
        p2->value = i;
        p2++;
    }
    head -= 5;

    // output what is in the array before the user reads into the queue
    cout << "These are the initial contents in the queue: ";
    for (int i = 0; i < 5; i++)
    {
        cout << head->value << " ";
        head++;
    }
    cout << endl;
    head -= 5;

    // recursive function call
    recursive('N', head);

    // dynamically allocated memory should be deleted when program ends
    system("pause");
    return 0;
}

// this function creates new node for the new value that is entered into the queue
int enQueue(int newValue, queue* h)
{
    // declare pointer to dynamic array structure
    queue* newNode = new queue;
    // move the head to the end
    while(h->next != nullptr)
        h = h->next;
    // point to the new node and assign the value to the new node
    h->next = newNode;
    newNode->value = newValue;
    // return the value added to the new node
    return newNode->value;
}

// this function disconnects first node from the queue
int deQueue(queue* &h)
{
    // create a pointer to the first structure
    queue* hold = h;
    // point the head to the second element in the queue
    h = h->next;
    // the first element will point to a null pointer (disconnect)
    hold->next = nullptr;
    // return the dequeued value
    return hold->value;
}

// this recursive function will function call enqueue and dequeue
char recursive(char again, queue* head)
{
    // prompt and read in the user value
    int userValue;
    cout << "Please enter the number you wish to enter into the queue: ";
    cin >> userValue;

    // function call to enQueue and deQueue and output values
    cout << "The value being entered into the queue is " << enQueue(userValue,head) << endl;
    cout << "The value being taken out of the queue is " << deQueue(head) << endl;

    // prompt and read in if the user wants to enter more into the queue
    cout << "Do you want to enter another value into the queue? (Y/N)" << endl;
    cin >> again;

    // function call the recursive function again if the user wants
    if(again == 'Y' || again == 'y')
        recursive(again,head);

    // return the again variable of that function call
    return again;
}
