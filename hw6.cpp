// Author:          Sarah G. Tempelmeyer
// Net ID:          sgt 170030
// Course:          CS 1337.007
// Date:            3/24/2018
// Assignment:      Homework 6
// Compiler:        Code::Blocks

// Description: This program uses functions to rearrange and concatenate character arrays,
//              and to validate a password by using character-testing functions

#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

// function prototypes
char* name(char*, char*, char*);
int validatePassword();

int main()
{
    // declare variables
    int option, password;
    // declare character arrays for name option
    char first [100];
    char middle [100];
    char last [100];

    do
    {
        // display menu and read in user option
        cout << "1. Rearrange name" << endl;
        cout << "2. Validate Password" << endl;
        cout << "3. Exit" << endl;
        cout << "Please select an option from the menu above: ";

        cin >> option;
        // input validation for user option
        while (option < 1 || option > 3)
        {
            cout << "Please enter a valid option" << endl;
            cin >> option;
        }

        // switch statement for the options the user selects
        switch (option)
        {
        // if option 1, rearrange the name
        case 1:
            // function call to name and read out the character array return value
            cout << name(first, middle, last) << endl;
            break;
        // if option 2, validate the password
        case 2:
            // function call and assign return value to int
            password = validatePassword();
            if (password == 1)
                cout << "Your password is not in between 6 and 14 characters long." << endl;
            else if (password == 2)
                cout << "Your password needs at least one uppercase and one lowercase character" << endl;
            else if (password == 3)
                cout << "Your password needs at least 1 digit." << endl;
            else if (password == 4)
                cout << "Your password needs at least one punctuation symbol." << endl;
            // if none password is not 1, 2, 3, or 4, it is valid
            else
                cout << "Your password is valid!" << endl;
            break;
        }
    }
    while (option == 1 || option == 2);

    return 0;
} // end function main

// this function will rearrange the character arrays
char* name(char* first, char* middle, char* last)
{
    // declare variable for size of string
    int maxChars;

    // prompt the user to enter name and read into array
    cout << "Please enter your first, middle, and last name in this order: ";
    cin >> first >> middle >> last;

    // concatenate in order of last, first middle
    strcat(last, ", ");
    strcat(last, first);
    strcat(last, " ");
    strcat(last, middle);

    // max chars is the length of the array
    maxChars = strlen(last);

    // dynamically allocate a new array with exactly the size of the name entered and copy
    char *name = new char[maxChars + 1];
    strcpy(name,last);

    // return concatenated char array pointer
    return name;
}

int validatePassword()
{
    // declare character array
    char password[50];
    // display the password criteria and prompt/read in the user password
    cout << " - between 6 and 14 characters long" << endl;
    cout << " - at least one uppercase and one lowercase character" << endl;
    cout << " - at least 1 digit" << endl;
    cout << " - at least one punctuation symbol" << endl;

    cout << "Please enter a password that meets the previous criteria." << endl;
    cin >> password;

    // check that password is in between 6 and 14 characters
    if (strlen(password) < 6 || strlen(password) > 14)
        return 1;

    // check each element of the password with a for loop
    for (int upper = 0; upper < strlen(password); upper++){
        for (int lower = 0; lower < strlen(password); lower++){
            // if element is lowercase and uppercase, break from both for loops
            if(islower(password[lower]) && isupper(password[upper]))
                goto finish;
        }
    }
    // if completed both of the for loops, the answer is invalid
    return 2;
    // skip over return value if passed the uppercase and lowercase criteria
    finish:

    // check each element of the password with a for loop
    for (int i = 0; i < strlen(password); i++){
        // if the element is a digit, break from for loop because this criteria is met
        if (isdigit(password[i]))
            break;
        // if i is at the last element and is not a digit still, it is invalid
        if (i == strlen(password) - 1)
            return 3;
    }

    // check each element of the password with a for loop
    for (int i = 0; i < strlen(password); i++){
        // if the element is punctuation, break from for loop because this criteria is met
        if (ispunct(password[i]))
            break;
        // if i is at the last element and is not a digit still, it is invalid
        if (i == strlen(password) - 1)
            return 4;
    }

    // the password is valid
    return 0;
}
