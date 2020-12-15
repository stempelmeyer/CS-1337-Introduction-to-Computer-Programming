// Author:          Sarah G. Tempelmeyer
// Student ID:      sgt170030

#ifndef DOUBLELINKNODE_H
#define DOUBLELINKNODE_H

#include "basenode.h"
#include <string>

class DoubleLinkNode : public Node
{
private:
    DoubleLinkNode* next = nullptr;
    DoubleLinkNode* prev = nullptr;
public:
    DoubleLinkNode() : Node() {} // default constructor
    DoubleLinkNode(std::string rom, int arab): Node(rom, arab) {} // overload constructor
    DoubleLinkNode(const DoubleLinkNode &obj) : Node() { next = obj.next; prev = obj.prev; }// copy constructor
    virtual ~DoubleLinkNode(){}
    DoubleLinkNode* getNext() const { return next; } // next accessor
    DoubleLinkNode* getPrevious() const { return prev; } // previous accessor
    void setNext(DoubleLinkNode* ptr) { next = ptr; } // next mutator
    void setPrev(DoubleLinkNode* ptr) { prev = ptr; } // prev mutator
    std::string getRoman() const { return roman; } // overridden function
};
#endif // DOUBLELINKNODE_H
