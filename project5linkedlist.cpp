// Author:          Sarah G. Tempelmeyer
// Student ID:      sgt170030

#include "linkedlist.h"
#include "doublelinknode.h"
#include "basenode.h"
#include <cctype>
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
}

LinkedList::~LinkedList() // destructor
{
    DoubleLinkNode* current = head;
    while(head != nullptr){
        current = head;
        head = head->getNext();
        delete current;
    }
}

void LinkedList::setHead(DoubleLinkNode* ptr) // head mutator
{       // if head is not nullptr
        head->setNext(ptr->getNext());
        ptr->getNext()->setPrev(head);
        head->setPrev(ptr);
        ptr->setNext(head);
        head = ptr;
}

// this method validates if the roman or arabic number is correct
bool LinkedList::validate(std::string rom, int arab)
{
    Node* temp = nullptr;
    if(arab != -1){ // check arabic number
        if (arab > 4999 || arab < 1)
            return false;
    }
    else if(arab == -1) { // check roman numeral
        for (unsigned int i = 0; i < rom.length(); i++)
        {
            if (rom.at(i) != 'I' && rom.at(i) != 'V' && rom.at(i) != 'X' && rom.at(i) != 'L' && rom.at(i) != 'C' && rom.at(i) != 'D' && rom.at(i) != 'M')
                return false;
        }
        // send the roman string to the conversion method and compare to what the number should actually read
        int correctArab = temp->romanToArabic(rom);
        if (temp->arabicToRoman(correctArab) != rom)
            return false;
    }
    return true; // if reaches the end of the method
}

// sets next of the ptr
void LinkedList::addNext(DoubleLinkNode* ptr)
{
    if(tail == nullptr)
        tail = ptr;
    else {
    tail->setNext(ptr);
    ptr->setNext(nullptr);
    ptr->setPrev(tail);
    tail = ptr;
    }
}

void LinkedList::initialize(std::ifstream &file)
{
    // move file pointer to the end, and tellg location for file size, send pointer back to beginning
    file.seekg(0,std::ios::end);
    int fileSize = file.tellg();
    file.clear();
    file.seekg(0,std::ios::beg);

    // read in the file to the linked list while not at the end of the file
    while (!file.eof() && file.tellg() < fileSize)
    {
        nextIteration:
        // if not space, read in roman numeral
        if (file.peek() != ' ')
        {
            // read in the roman numeral, ignore the spaces, and validate it
            std::string temp;
            getline(file,temp);
            // make sure file isn't blank
            if (temp == "")
                continue;
            temp = temp.substr(0,temp.find(' '));
            // if the number is valid then increment pointer to assign to the next structure
            if(validate(temp, -1))
            {
                // create new node if valid and add it to the list
                DoubleLinkNode* newNode = new DoubleLinkNode();
                newNode->setRoman(temp);
                if(head == nullptr){ // if the list is empty
                    head = newNode;
                    tail = newNode;
                }
                else
                    addNext(newNode);
                // find linked list arabic number by function call
                newNode->setArabic(newNode->romanToArabic(newNode->getRoman()));
            }
        }
        else
        {
            std::string line;
            int temp;
            // read in the arabic integer string and convert to an integer
            getline(file, line);
            // if line is at end
            if (line.length() < 17)
                continue;
            // cut off extra spaces at beginning
            line = line.substr(17);
            // cut off extra space at end
            line = line.substr(0, line.find(" "));
            // input validation to make sure arabic number is number
            for (unsigned int i = 0; i < line.length(); i ++){
                if (!isdigit(line.at(i)))
                    goto nextIteration;
            }
            temp = stoi(line);
            // if the number is valid then increment pointer to assign to the next structure
            if(validate("", temp))
            {
                // create new node if valid and attach to linked list
                DoubleLinkNode* newNode = new DoubleLinkNode();
                newNode->setArabic(temp);
                if(head == nullptr){ // if the list is empty
                    head = newNode;
                    tail = newNode;
                }
                else
                    addNext(newNode);
                // assign roman member of linked list by function calling the conversion
                newNode->setRoman(newNode->arabicToRoman(newNode->getArabic()));
            }
        }
    }
}

int LinkedList::searchMethod(std::string searchValue)
{
    // create a node to search through the linked list
    DoubleLinkNode* current = head;
    int location = 0;

    // searching for roman numeral
    if(isupper(searchValue.at(0)))
    {
        // search through linked list until reaching the nullptr
        while(current != nullptr)
        {
            // if the linked list string equals the search value
            if(current->getRoman() == searchValue)
                return location;
            current = current->getNext();
            location++;
        }
    }
    // searching for arabic number
    else
    {
        // convert the search string to an int if searching for the arabic number
        int searchInt = stoi(searchValue);
        // search through linked list until reaching the nullptr
        while(current != nullptr)
        {
            // if linked list arabic int equals the integer of the string
            if(current->getArabic() == searchInt)
                return location;
            current = current->getNext();
            location++;
        }
    }
    // return -1 if the search value is not found in the linked list
    return -1;
}

void LinkedList::operator += (DoubleLinkNode* ptr)
{
    if(tail != nullptr && ptr != nullptr)
    {
    tail->setNext(ptr);
    ptr->setNext(nullptr);
    ptr->setPrev(tail);
    tail = ptr;
    }
}

void LinkedList::deleteMethod(int location)
{
    DoubleLinkNode* temp = nullptr;
    if(location == -1){ // delete the tail
        temp = tail;
        temp->setNext(nullptr);
        tail = tail->getPrevious();
        tail->setNext(nullptr);
        delete temp; // delete tail node
    }
    else{ // delete other than tail
        temp = head;
        if (location == 0) // if deleting head
        {
            head = temp->getNext();
            delete temp;
        }
        else
        {
            for(int i =  0; i < location; i++)
                temp = temp->getNext();
            temp->getPrevious()->setNext(temp->getNext());
            if(temp->getNext() != nullptr)
                temp->getNext()->setPrev(temp->getPrevious());
            temp->setPrev(nullptr);
            delete temp;
        }
    }
}

void LinkedList::printList(std::ostream& ofile, DoubleLinkNode* ptr)
{
    if(ptr == nullptr)
        return;
    else {
        ofile << dynamic_cast<Node*>(ptr);
        printList(ofile, ptr->getNext());
    }
}
