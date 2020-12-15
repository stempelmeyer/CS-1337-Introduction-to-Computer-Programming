// Author:          Sarah G. Tempelmeyer
// Student ID:      sgt170030

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "basenode.h"
#include "doublelinknode.h"
#include <string>
#include <fstream>
#include <istream>

class LinkedList
{
private:
    DoubleLinkNode* head = nullptr;
    DoubleLinkNode* tail = nullptr;
public:
    LinkedList(); // default constructor
    LinkedList(DoubleLinkNode* ptr) { head = ptr; } // assigns head to node passed in
    ~LinkedList(); // destructor
    DoubleLinkNode* getHead() const { return head; } // head accessor
    DoubleLinkNode* getTail() const { return tail; } // tail accessor
    void setHead(DoubleLinkNode*);                    // head mutator
    void setTail(DoubleLinkNode* ptr) { tail = ptr; } // tail mutator
    void addNext(DoubleLinkNode*);
    bool validate(std::string, int);
    void initialize(std::ifstream&);
    int searchMethod(std::string);
    void operator += (DoubleLinkNode*);
    void operator -- () { deleteMethod(0); } // prefix overload deletes first node
    void operator -- (int) { deleteMethod(-1); } // postfix operator overload deletes last node
    void deleteMethod(int);
    void printList(std::ostream&, DoubleLinkNode*);
};
#endif // LINKEDLIST_H
