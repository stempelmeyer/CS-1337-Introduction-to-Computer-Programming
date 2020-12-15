//Sarah Tempelmeyer and Cameron Sheffield
#include <iostream>

using namespace std;
//declaring node structure
struct Node
{
    int num;
    Node* next = nullptr;
};
//declaring prototypes
int searchNode(Node* head, int searchVal);
void insertNode(Node* &head, int nodeNum, int position);
Node* removeNode(Node* &head, int position);
void printList(Node* head);

int main()
{
    //declaring variables
    Node *head = nullptr, *ptrTrash = nullptr;
    int value, position, menuInput;
    do
    {
        //while the user picks a valid input option, continue looping
        //Output user prompt and ask for menu choice
        cout << "Please choose an option from the menu below. If a value that is not an option is entered, the code will end" << endl;
        cout << "1. Add a node to the list\n";
        cout << "2. Remove a node from the list \n";
        cout << "3. Search for a value in the list\n";
        cout << "4. Print out the list\n";
        cout << "Your input is ";
        cin >> menuInput;
        switch(menuInput)
        {
            case(1):
                //if they chose to add a number, ask for number to insert, the position, and insert it
                cout <<"Please input the number you want to insert\n";
                cin >> value;
                cout << "Please input the position you would like to place the number\n";
                cin >> position;
                insertNode(head, value, position);
                break;
            case(2):
                //if they chose to remove a node, ask for the position and remove it from the list
                cout << "Please input which position you would like to delete \n";
                cin >> position;
                ptrTrash = removeNode(head, position);
                //after it is removed, delete it
                delete[] ptrTrash;
                break;
            case(3):
                //if they chose to search, ask for what value they would like to search for and run the search function
                cout <<"Please input the value of the node you would like to search for, if it is not found, it will return -1\n";
                cin >> value;
                cout << "The user value was found at " << searchNode(head, value) << endl;
                break;
            case(4):
                //if they chose to print the list, print out each value
                printList(head);
                cout << endl;
                break;
        }
    }while(menuInput >=1 && menuInput <=4);
    cin.get();
    cin.get();
    return 0;
}

Node* removeNode(Node *&head, int position)
{
    //declaring variables
    Node* ptr2;
    Node* hold;
    ptr2 = head;
    //if the head is being deleted, move head to the next value then return it
    if(position == 0)
    {
        hold = head;
        head = head->next;
        hold->next=nullptr;
    }
    else
    {
        //otherwise go to the right position, unlink the node, and return it
        for(int i = 0; i < position-1; i ++)
        {
            ptr2=ptr2->next;
        }
        hold = ptr2->next;
        ptr2->next = hold->next;
        hold->next=nullptr;
    }
    return hold;
}

void insertNode(Node *&head, int nodeNum, int position)
{
    //declaring variables
    Node* insertPtr = new Node();
    insertPtr->num = nodeNum;
    Node* searchPtr = head;
    //if the head doesn't exist, the new node is the head
    if(!head)
        head = insertPtr;
    //if the head exists but the position is zero, the new node is the head, and it points to the old head
    else if(position == 0)
    {
        insertPtr->next = head;
        head = insertPtr;
    }
    //otherwise, go to the right position and insert the node into the correct position.
    else
    {

        for(int i = 0; i < position-1; i++)
        {
            searchPtr = searchPtr->next;
        }
        insertPtr->next = searchPtr->next;
        searchPtr->next = insertPtr;
    }
}

int searchNode(Node* head, int searchVal)
{
    //declaring variables
    int position = 0;
    Node* ptr2 = head;
    //if the first value is the search value return it
    if(ptr2->num == searchVal)
        return position;
        //while there is more things in the list, check the num of the current value, move to the next value
        //then repeat, incrementing position by one each time
    while(ptr2)
    {
        if(ptr2->num == searchVal)
        {
            return position;
        }
        ptr2=ptr2->next;
        position++;
    }
    //if it was not found, return -1 as a sentinel
    return -1;
}

void printList(Node* head)
{
    //if head exists, print out the int associated with it
    if(head)
    {
        cout << head->num << " ";
        //if head->next also exists, run the program again with it as head
        if(head->next)
            printList(head->next);
    }
}
