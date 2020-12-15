// Author:          Sarah G. Tempelmeyer
// Student ID:      sgt170030
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <cmath>
#include "Linkedlist.h"
#include "Node.h"

Linkedlist::Linkedlist()
{
    head = nullptr;
}
// adds node as the head of the linked list
Linkedlist::Linkedlist(Node* ptr)
{
    ptr->next = head->next;
    head->next = ptr;
}
// adds node to the end of the linked list
void Linkedlist::addNode(Node *&ptr)
{
    // if base case
    if (head == nullptr)
    {
        head = ptr;
        return;
    }
    Node *current = head;
    while (current->next != nullptr) // something is wrong with this loop?
        current = current->next;
    ptr->next = current->next;
    current->next = ptr;
}

// this method inserts a node at a given position
void Linkedlist::insertNode(Node* add, int index)
{
    Node *current = head;
    for (int i = 0; i < index - 1 && current->next != nullptr; i++)
        current = current->next;
    add->next = current->next;
    current->next = add;
}

// this method combines the terms using a linear search which compares the exponents
void Linkedlist::combineTerms(Node* ptr)
{
    bool flipped = true;
    Node *compare = nullptr;
    Node *beginning = ptr;
    while (flipped)
    {
        flipped = false;
        ptr = beginning;
        while(ptr != nullptr)
        {
            compare = ptr;
            while (compare != nullptr && compare->next != nullptr)
            {
                if (ptr->getExponent() == compare->next->getExponent())
                {
                    flipped = true;
                    // add the coefficients together if the have the same exponents
                    if (ptr->getOperation() == '+' && compare->next->getOperation() == '+')                // add normally if operations are both positive
                        ptr->setCoefficient(ptr->getCoefficient() + compare->next->getCoefficient());
                    else if (ptr->getOperation() == '+' && compare->next->getOperation() == '-')
                    {
                        if (ptr->getCoefficient() == compare->next->getCoefficient())                       // if coefficients cancel
                            ptr->setCoefficient(0);
                        else if (ptr->getCoefficient() > compare->next->getCoefficient())                        // subtract normally if first has bigger coefficient than second
                            ptr->setCoefficient(ptr->getCoefficient() - compare->next->getCoefficient());
                        else if (ptr->getCoefficient() < compare->next->getCoefficient())                        // change operation if subtracting by a bigger number than the first
                        {
                            ptr->setCoefficient(compare->next->getCoefficient() - ptr->getCoefficient());
                            ptr->setOperation('-');
                        }
                    }
                    else if (ptr->getOperation() == '-' && compare->next->getOperation() == '+')
                    {
                        if (ptr->getCoefficient() > compare->next->getCoefficient())                        // keep operation and subtract numbers if first coefficient smaller than the second
                            ptr->setCoefficient(ptr->getCoefficient() - compare->next->getCoefficient());
                        else if (ptr->getCoefficient() <= compare->next->getCoefficient())                        // change operation if adding by bigger number than subtracting
                        {
                            ptr->setCoefficient(compare->next->getCoefficient() - ptr->getCoefficient());
                            ptr->setOperation('+');
                        }
                    }
                    else if (ptr->getOperation() == '-' && compare->next->getOperation() == '-')           // add and keep sign if subtracting both
                        ptr->setCoefficient(ptr->getCoefficient() + compare->next->getCoefficient());
                    // delete the node not added to
                    Node* hold = compare->next;
                    if (hold->next != nullptr)
                    {
                        compare->next = hold->next;
                        hold->next = nullptr;
                    }
                    else
                        compare->next = nullptr;
                    delete hold;
                }
                compare = compare->next;
            }
            ptr = ptr->next;
        }
    }
}
// this method was an overload operator << to print the list
std::ostream &operator << (std::ostream &stream, Linkedlist& object)
{
    Node *current = object.getListHead();
    object.calculate();
    stream << "f(" << object.getEvaluate() << ") = ";
    // this bunch of if statements is because the first term will be outputted differently if it has a negative
    if (current->getOperation() == '-')
        stream << "-";
    if ((current->getCoefficient()) != 1)
        stream << current->getCoefficient();
    if ((current->getExponent()) != 0)
        stream << "x";
    if ((current->getExponent()) != 1 && current->getExponent() != 0)
        stream << "^" << std::to_string(current->getExponent());
    current = current->next;

    while (current != nullptr)
    {
        stream << " " << current->getOperation() << " ";
        if ((current->getCoefficient()) != 1)
            stream << current->getCoefficient();
        if ((current->getExponent()) != 0)
            stream << "x";
        if ((current->getExponent()) != 1 && (current->getExponent()) != 0)
            stream << "^" << std::to_string(current->getExponent());
        current = current->next;
    }
    stream << " = " << std::fixed << std::setprecision(3) << object.getSolution() << "\n";
    return stream;
}

// this method parses the terms into coefficients and exponents
void Linkedlist::splitTerms(std::string term, Node* nodePtr)
{
    int indx = term.find('x');
    if (indx != -1)  // if x is found
    {
        if (indx != 0)  // if x has coefficient
            nodePtr->setCoefficient(stod(term.substr(0, indx)));
        else if (indx == 0) // there is no coefficient
            nodePtr->setCoefficient(1);
        int indspace = term.find('^');
        if (indspace != -1)  // if an exponent exists
            nodePtr->setExponent(stoi(term.substr(indspace + 1)));
        else // if an exponent doesn't exist but x is found
            nodePtr->setExponent(1);
    }
    else  // if x is not found
    {
        nodePtr->setCoefficient(stod(term));
        nodePtr->setExponent(0);
    }
}

// this function will sort the linked list based on the option chosen by the user
void Linkedlist::sortLinkedlist(Node* ptr)
{
    // declare and initialize flip variable for while condition
    bool flipped = true;

    // handle trivial cases if there is an empty list or only one node
    if(ptr == nullptr || ptr->next == nullptr)
        return;

    // sort through linked list until reaching the nullptr and until none of the values are flipped
    while(flipped)
    {
        flipped = false;
        // if first node must be switched
        if (ptr->getExponent() < ptr->next->getExponent())
        {
            // create a temporary pointer and swap the nodes
            Node* temp = ptr;
            ptr = ptr->next;
            head = ptr;
            temp->next = ptr->next;
            ptr->next = temp;
            flipped = true;
        }

        for(Node* current = ptr; current->next->next != nullptr; current = current->next)
        {
            // if the the values sent in the function need to be switched
            if(current->next->getExponent() < current->next->next->getExponent())
            {
                // create temporary pointer and swap the nodes
                Node* temp = current->next;
                current->next = temp->next;
                temp->next = current->next->next;
                current->next->next = temp;
                flipped = true;
            }
        }
    }
} // end sort function

// this method calculates the solution for each expression line in the file
void Linkedlist::calculate()
{
    Node *ptr = head;
    while (ptr != nullptr)
    {
        // check to make sure not dividing by a zero
        if (ptr->next != nullptr && ptr->next->getExponent() < 0 && evaluateAt == 0)
            std::cout << "Cannot divide by zero. This term will be evaluated to infinity." << std::endl;
        if (ptr->getOperation() == '+')
            solution += (ptr->getCoefficient() * pow(evaluateAt, ptr->getExponent()));
        if (ptr->getOperation() == '-')
            solution -= (ptr->getCoefficient() * pow(evaluateAt, ptr->getExponent()));
        ptr = ptr->next;
    }
}
