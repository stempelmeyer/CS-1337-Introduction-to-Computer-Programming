// Author:          Sarah G. Tempelmeyer
// Net ID:          sgt 170030
// Course:          CS 1337.007
// Date:            4/15/2018
// Assignment:      Homework 8
// Compiler:        Code::Blocks

// Description: This program uses classes to store a month name and number
// and gives the user the ability to increment and decrement the month
// by using overload operators.

#include <iostream>
#include "month.h"

using namespace std;

int main()
{
    Month month;
    int userOption;

    cout << "This is the month created by using an overload constructor which includes the name" << endl;
    Month month2("fEbRuArY");
    cout << month2.getMonthName() << ": " << month2.getMonthNum() << endl;
    cout << "Changing the month back to january and then to february... " << endl;
    month2.setMonthName("JANUARY");
    cout << month2.getMonthName() << ": " << month2.getMonthNum() << " and ";
    month2.setMonthNum(2);
    cout << month2.getMonthName() << ": " << month2.getMonthNum() << endl;
    cout << "This is the month created by using an overload constructor which includes the number" << endl;
    Month month3(3);
    cout << month3;
    cout << "This is a copy of the previous month declared" << endl;
    Month copy1 = month3;
    cout << copy1;

    cout << "This is the month created by using a default constructor: " << month;

    do{
        cout << "1. Enter a month" << endl;
        cout << "2. Display month and increment the month" << endl;
        cout << "3. Increment month and display the month" << endl;
        cout << "4. Display month and decrement the month" << endl;
        cout << "5. Decrement month and display the month" << endl;
        cout << "6. View current month name and month number" << endl;
        cout << "7. Exit" << endl;
        cout << "Please enter an option from the menu above: ";
        cin >> userOption;

        if (userOption == 1)
        {
            cin >> month;
        }
        if (userOption == 2)
        {
            cout << (month++);
        }
        if (userOption == 3)
        {
            cout << (++month);
        }
        if (userOption == 4)
        {
            cout << (month--);
        }
        if (userOption == 5)
        {
            cout << (--month);
        }
        if (userOption == 6)
        {
            cout << month;
        }
    } while(userOption != 7);

    return 0;
}
