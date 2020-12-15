// Author:          Sarah G. Tempelmeyer
// Student ID:      sgt170030
#include <iostream>
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"

class Linkedlist;
std::ostream &operator << (std::ostream &, Linkedlist&);

class Linkedlist
{
private:
    Node *head = nullptr;
    Node *next = nullptr;
    double solution = 0;
    double evaluateAt;
public:
    Linkedlist();               // default constructor
    Linkedlist(Node *ptr);      // overload constructor
    ~Linkedlist()               // delete the list recursively
        { delete next; }        // will continue destructing until next is a nullptr
    void setEvaluate(double xVal)
        { evaluateAt = xVal; }
    void setSolution(double sol)
        { solution = sol; }
    Node* getLinkedlist()
        { return head; }
    void addNode(Node *&);
    Node* getListHead()
        { return head; }
    double getEvaluate()
        { return evaluateAt; }
    double getSolution()
        { return solution; }
    void insertNode(Node*, int);
    void combineTerms(Node*);
    void splitTerms(std::string, Node*);
    void sortLinkedlist(Node*);
    void calculate();
    friend std::ostream &operator << (std::ostream &, Linkedlist&);
};

#endif // LINKEDLIST_H
