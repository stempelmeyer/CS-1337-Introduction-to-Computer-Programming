// Author:          Sarah G. Tempelmeyer
// Student ID:      sgt170030
// Course:          CS 1337.007
// Date:            3/16/2018
// Assignment:      Project #3
// Compiler:        Code::Blocks
// INPUT VALIDATION

// Description: This program converts roman numerals to Arabic
// numbers and vice versa using linked lists. It will give the
// user the option to sort, search, or display the list.

#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

// node structure
struct Node
{
    string roman;
    int arabic;
    Node* next = nullptr;
};

// create a structure for ptrs to the head and tail of the linked list
struct LinkedList
{
    Node* head = nullptr;
};

// function prototypes
LinkedList initializeLinkedList(ifstream&);
int romanToArabic(string);
string arabicToRoman(int);
bool validate(string, int);
bool searchFunction(string, LinkedList);
void sortFunction(int, Node*&);
bool compare(int, Node*, Node*);

const string FILE_NAME = "numbersXC.txt";

int main()
{
    // declare variables and open file
    ifstream ifile(FILE_NAME);
    double userOption;
    string userInput;
    string searchValue;

    // if the file doesn't open, display error and end program
    if(!ifile)
    {
        cout << "The file could not be opened" << endl;
        return 1;
    }

    // function call to initialize linked list
    LinkedList ParsedList = initializeLinkedList(ifile);

    do // output menu options to the user
    {

        cout << "1. Search" << endl;
        cout << "2. Sort" << endl;
        cout << "3. Exit" << endl;
        cin >> userInput;

        // if not a number it is not a valid option
        for (int i = 0; i < userInput.length(); i ++){
                if (!isdigit(userInput.at(i)))
                    userInput = "0";
        }

        userOption = stoi(userInput);

        // input validation loop which reads in and validates string from the user
        while(userOption > 3 || userOption < 1){
            cout << "Please select a valid option from the menu" << endl;
            cin >> userInput;

            // if not a number it is not a valid option
            for (int i = 0; i < userInput.length(); i ++){
                    if (!isdigit(userInput.at(i)))
                        userInput = "0";
            }

            userOption = stoi(userInput);
        }

        // if user wants to search
        if(userOption == 1)
        {
            // prompt user for value and send into search function
            cout << "Please enter a search value: ";
            cin >> searchValue;
            // if the search value is an arabic number, validate it
            if (isdigit(searchValue.at(0)))
            {
                if (!validate("\0", stoi(searchValue)))
                {
                    cout << "Please enter a valid search value: " << endl;
                    continue; // ouput menu option again if invalid
                }
            }
            // if the search value is a roman number, validate it
            else
            {
                if (!validate(searchValue, -1))
                {
                    cout << "Please enter a valid search value: " << endl;
                    continue; // output menu option again if invalid
                }
            }
            // function call to search for the value and output if it was found or not
            if (searchFunction(searchValue, ParsedList))
                cout << searchValue << " was found in the linked list" << endl;
            else
            {
                cout << searchValue << " was not found in the linked list" << endl;
            }
        }

        // if user wants to sort
        else if (userOption == 2)
        {
            cout << "1. Sort by Roman numeral" << endl;
            cout << "2. Sort by Arabic numeral" << endl;
            cin >> userOption;

            // input validation for user input
            while (userOption < 1 || userOption > 2)
            {
                cout << "Please enter a valid option (1 or 2): " << endl;
                cin >> userOption;
            }
            // function call to sort function
            sortFunction(userOption, ParsedList.head);

            // output sorted linked list to console
            for (Node* current = ParsedList.head; current != nullptr; current = current->next)
                cout << setw(16) << left << current->roman << " " << setw(4) << left << current->arabic << endl;
        }
    }
    while(userOption == 1 || userOption == 2);

    ifile.close();
    ofstream ofile(FILE_NAME);

    if(!ofile)
    {
        cout << "The file could not be opened" << endl;
        return 1;
    }

    // output linked list to file
    for(Node* current = ParsedList.head; current != nullptr; current = current->next)
        ofile << setw(16) << left << current->roman << " " << setw(4) << left << current->arabic << endl;

    // close file
    ofile.close();

    // delete dynamically allocated memory
    Node* temp = ParsedList.head;
    for(Node* current = ParsedList.head; temp != nullptr; current = current->next){
        current = temp;
        temp = current->next;
        delete current;
    }

    return 0;
} // end function main


LinkedList initializeLinkedList(ifstream& file)
{
    LinkedList ParsedList;

    // move file pointer to the end, and tellg location for file size, send pointer back to beginning
    file.seekg(0,ios::end);
    int fileSize = file.tellg();
    file.clear();
    file.seekg(0,ios::beg);

    // read in the file to the linked list while not at the end of the file
    while (file && file.tellg() < fileSize)
    {
        nextIteration:

        // if not space, read in roman numeral
        if (file.peek() != ' ')
        {
            // read in the roman numeral, ignore the spaces, and validate it
            string temp;
            getline(file,temp);
            // make sure file isn't blank
            if (temp == "")
                continue;
            temp = temp.substr(0,temp.find(' '));
            // if the number is valid then increment pointer to assign to the next structure
            if(validate(temp, -1))
            {
                // create new node if valid and add it to the list
                Node* newNode = new Node();
                newNode->roman = temp;
                newNode->next = ParsedList.head;
                ParsedList.head = newNode;
                // find linked list arabic number by function call
                newNode->arabic = romanToArabic(newNode->roman);
            }
        }
        else
        {
            string line;
            int temp;
            // read in the arabic integer string and convert to an integer
            getline(file,line);
            // if line is at end
            if (line.length() < 17)
                continue;
            // cut off extra spaces at beginning
            line = line.substr(17);
            // cut off extra space at end
            line = line.substr(0, line.find(" "));
            // input validation
            for (int i = 0; i < line.length(); i ++){
                if (!isdigit(line.at(i)))
                    goto nextIteration;
            }
            temp = stoi(line);
            // if the number is valid then increment pointer to assign to the next structure
            if(validate(to_string(temp), temp))
            {
                // create new node if valid and attach to linked list
                Node* newNode = new Node();
                newNode->arabic = temp;
                newNode->next = ParsedList.head;
                ParsedList.head = newNode;
                // assign roman member of linked list by function calling the conversion
                newNode->roman = arabicToRoman(newNode->arabic);
            }
        }
    }

    return ParsedList;
} // end function linked list

// this function will validate the file input
bool validate(string roman, int arabic)
{
    // if string default unchanged, check arabic number
    if (arabic != -1)
    {
        if (arabic > 4999 || arabic < 1)
            return false;
    }
    // if int default unchanged, check roman string
    else if (arabic == -1)
    {
        for (int i = 0; i < roman.length(); i++)
        {
            if (roman.at(i) != 'I' && roman.at(i) != 'V' && roman.at(i) != 'X' && roman.at(i) != 'L' && roman.at(i) != 'C' && roman.at(i) != 'D' && roman.at(i) != 'M')
                return false;
        }
        // send the roman string to the conversion functions and compare to what the number should actually read
        int correctArab = romanToArabic(roman);
        if (arabicToRoman(correctArab) != roman)
            return false;
    }
    return true;
} // end function validate

// this function uses the roman numeral string as a parameter and returns the converted arabic number
int romanToArabic(string roman)
{
    // declare the accumulator which will add up to the arabic number
    int accumulator = 0;

    for (int i = 0; i < roman.length(); i++)
    {
        // this if statement makes sure that it compares the elements within valid subscripts
        // if any of these if statements are true, continue to the next iteration
        if (i < roman.length()-1)
        {
            // if CM add 900 to arabic number, and increment i (to now avoid reading the second letter twice)
            if (roman.at(i)=='C' && roman.at(i+1)=='M')
            {
                accumulator+=900;
                i++;
                continue;
            }
            // if CD add 400 to arabic number, and increment i (to now avoid reading the second letter twice)
            else if (roman.at(i)=='C' && roman.at(i+1)=='D')
            {
                accumulator+=400;
                i++;
                continue;
            }
            // if XC add 90 to arabic number, and increment i (to now avoid reading the second letter twice)
            else if (roman.at(i)=='X' && roman.at(i+1)=='C')
            {
                accumulator+=90;
                i++;
                continue;
            }
            // if XL add 40 to arabic number, and increment i (to now avoid reading the second letter twice)
            else if (roman.at(i)=='X' && roman.at(i+1)=='L')
            {
                accumulator+=40;
                i++;
                continue;
            }
            // if IX add 9 to arabic number, and increment i (to now avoid reading the second letter twice)
            else if (roman.at(i)=='I' && roman.at(i+1)=='X')
            {
                accumulator+=9;
                i++;
                continue;
            }
            // if IV add 4 to arabic number, and increment i (to now avoid reading the second letter twice)
            else if (roman[i]=='I' && roman.at(i+1)=='V')
            {
                accumulator+=4;
                i++;
                continue;
            }
        }
        // if M, D, C, L, X, V, I add 1000, 500, 100, 50, 10, 5, 1 respectively
        if (roman.at(i) == 'M')
            accumulator += 1000;
        if (roman.at(i) == 'D')
            accumulator += 500;
        if (roman.at(i) == 'C')
            accumulator += 100;
        if (roman.at(i) == 'L')
            accumulator += 50;
        if (roman.at(i) == 'X')
            accumulator += 10;
        if (roman.at(i) == 'V')
            accumulator += 5;
        if (roman.at(i) == 'I')
            accumulator += 1;
    }
    return accumulator;
} // end function roman to arabic and return the accumulator

// this function will convert an arabic number to a roman numeral string and return that string
string arabicToRoman(int arabic)
{
    // declare variables
    string roman;
    int remainder = 0;

    // if arabic is more than or equal to 1000, add M to each 1000
    if ((arabic/1000) > 0)
    {
        for (int i = 0; i < (arabic/1000); i++)
            roman += 'M';
    }
    // assign remainder and arabic to remainder of 1000
    remainder = arabic % 1000;
    arabic %= 1000;
    // use switch statement comparing result of amount of hundreds place of remainder
    switch(remainder/100)
    {
    // add CM to string if hundreds place is 9
    case 9:
        roman += "CM";
        break;
    // add D to string if hundreds place is 8, 7, 6, 5 and C to each 6, 7, 8
    case 8:
    case 7:
    case 6:
    case 5:
        roman += 'D';
        for (int i = 0; i < ((remainder/100)-5); i++)
            roman += 'C';
        break;
    // add CD if hundreds place is 4
    case 4:
        roman += "CD";
        break;
    // add C for each hundreds under 4
    case 3:
    case 2:
    case 1:
        for (int i = 0; i < (remainder/100); i++)
            roman += 'C';
        break;
    }
    // assign remainder and arabic to remainder of 100
    remainder = arabic % 100;
    arabic %= 100;
    // use switch statement comparing result of amount of tens place of remainder
    switch(remainder/10)
    {
    // add XC to string if tens place is 9
    case 9:
        roman += "XC";
        break;
    // add L to string if tens place is 8, 7, 6, 5 and X to each 6, 7, 8
    case 8:
    case 7:
    case 6:
    case 5:
        roman += 'L';
        for (int i = 0; i < ((remainder/10)-5); i++)
            roman += 'X';
        break;
    // add XL if tens place is 4
    case 4:
        roman += "XL";
        break;
    // add C for each hundreds under 4
    case 3:
    case 2:
    case 1:
        for (int i = 0; i < (remainder/10); i++)
            roman += 'X';
        break;
    }
    // assign remainder and arabic to remainder of 10
    remainder = arabic % 10;
    arabic %= 10;
    // use switch statement comparing result of remainder
    switch(remainder)
    {
    // add IX if remainder is 9
    case 9:
        roman += "IX";
        break;
    // add V if remainder is 8, 7, 6, 5 and I to each 6, 7, 8
    case 8:
    case 7:
    case 6:
    case 5:
        roman += 'V';
        for (int i = 0; i < (remainder-5); i++)
            roman += 'I';
        break;
    // add IV if remainder is 4
    case 4:
        roman += "IV";
        break;
    // add I to each remainder under 4
    case 3:
    case 2:
    case 1:
        for (int i = 0; i < remainder; i++)
            roman += 'I';
        break;
    }// end switch statement
    return roman;
} // end function arabic to roman and return string for the roman numeral

// this function will return if the search value is found or not in the linked list
bool searchFunction(string searchValue, LinkedList ParsedList)
{
    // create a node to search through the linked list
    Node* current = ParsedList.head;

    // searching for roman numeral
    if(isupper(searchValue.at(0)))
    {
        // search through linked list until reaching the nullptr
        while(current != nullptr)
        {
            // if the linked list string equals the search value
            if(current->roman == searchValue)
                return true;
            current = current->next;
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
            if(current->arabic == searchInt)
                return true;
            current = current->next;
        }
    }
    // return false if the search value is not found in the linked list
    return false;
} // end function bool searchFunction

// this function will sort the linked list based on the option chosen by the user
void sortFunction(int option, Node*& ptr)
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
        if (compare(option, ptr, ptr->next))
        {
            // create a temporary pointer and swap the nodes
            Node* temp = ptr;
            ptr = ptr->next;
            temp->next = ptr->next;
            ptr->next = temp;
            flipped = true;
        }

        for(Node* current = ptr; current->next != nullptr; current = current->next)
        {
            // if the the values sent in the function need to be switched
            if(compare(option, current->next, current->next->next))
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

// this function will compare two values of nodes and send back true if they must be swapped, or false if they are in
bool compare(int option, Node* left, Node* right)
{
    // if the nodes are null pointers, don't compare
    if(left == nullptr || right == nullptr)
        return false;
    // return true or false, using short circuitting and the fact that there will be either option 1 or option 2
    return ((option ==1 && (left->roman > right->roman)) || (option == 2 && left->arabic > right->arabic));
}
