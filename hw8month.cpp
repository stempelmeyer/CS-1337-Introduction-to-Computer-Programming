#include "month.h"
#include <cctype>
#include <string>
#include <iostream>

Month::Month(std::string month) // overload constructor sets month name and number based on string argument
{
    // convert all letters to lowercase to compare
    for(int i = 0; i < month.length(); i++)
        month[i] = tolower(month[i]);
    // assign to january if the month argument is invalid
    if (month != "january" && month != "february" && month != "march" && month != "april" && month != "may" && month != "june" && month != "july" && month != "august" && month != "september" && month != "october" && month != "november" && month != "december")
    {
        std::cout << "Invalid month name, initializing month to january" << std::endl;
        month = "january";
    }
    // capitalize the first letter
    month[0] = toupper(month[0]);
    monthName = month;
    updateMonthNum(); // update the month number
}
Month::Month(int month) // overload constructor sets month name and number based on int argument
{
    if (month > 12 || month < 1)
        month = 1;
    monthNum = month;
    updateMonthName(); // update the month name
}
// this method updates the month number
void Month::updateMonthNum()
{
    if (monthName == "January")
        monthNum = 1;
    else if (monthName == "February")
        monthNum = 2;
    else if (monthName == "March")
        monthNum = 3;
    else if (monthName == "April")
        monthNum = 4;
    else if (monthName == "May")
        monthNum = 5;
    else if (monthName == "June")
        monthNum = 6;
    else if (monthName == "July")
        monthNum = 7;
    else if (monthName == "August")
        monthNum = 8;
    else if (monthName == "September")
        monthNum = 9;
    else if (monthName == "October")
        monthNum = 10;
    else if (monthName == "November")
        monthNum = 11;
    else if (monthName == "December")
        monthNum = 12;
}

// this method updates the month name
void Month::updateMonthName()
{
    switch (monthNum)
    {
    case 1:
        monthName = "January";
        break;
    case 2:
        monthName = "February";
        break;
    case 3:
        monthName = "March";
        break;
    case 4:
        monthName = "April";
        break;
    case 5:
        monthName = "May";
        break;
    case 6:
        monthName = "June";
        break;
    case 7:
        monthName = "July";
        break;
    case 8:
        monthName = "August";
        break;
    case 9:
        monthName = "September";
        break;
    case 10:
        monthName = "October";
        break;
    case 11:
        monthName = "November";
        break;
    case 12:
        monthName = "December";
        break;
    }
}

void Month::setMonthName(std::string month)
{
    // convert all letters to lowercase to compare
    for(int i = 0; i < month.length(); i++)
        month[i] = tolower(month[i]);
    // assign to january if the month argument is invalid
    if (month != "january" && month != "february" && month != "march" && month != "april" && month != "may" && month != "june" && month != "july" && month != "august" && month != "september" && month != "october" && month != "november" && month != "december")
    {
        std::cout << "Invalid month name" << std::endl;
        return;
    }
    // capitalize the first letter
    month[0] = toupper(month[0]);
    monthName = month;
    updateMonthNum(); // update the month number
}

void Month::setMonthNum(int month)
{
    if (month > 12 || month < 1)
        return;
    monthNum = month;
    updateMonthName(); // update the month name
}
// prefix operator
Month Month::operator++()
{
    if (monthNum == 12)
        monthNum = 1;
    else
        monthNum++;
    updateMonthName(); // update the month name
    return *this;
}
// postfix operator
Month Month::operator++(int)
{
    Month temp(monthName);
    // or Month temp(monthNum);
    if (monthNum == 12)
        monthNum = 1;
    else
        monthNum++;
    updateMonthName();
    return temp;
}
// prefix operator
Month Month::operator--()
{
    if (monthNum == 1)
        monthNum = 12;
    else
        monthNum--;
    updateMonthName(); // update the month name
    return *this;
}
// postfix operator
Month Month::operator--(int)
{
    Month temp(monthName);
    // or Month temp(monthNum);
    if (monthNum == 1)
        monthNum = 12;
    else
        monthNum--;
    updateMonthName();
    return temp;
}
std::ostream &operator << (std::ostream &stream, const Month &obj)
{
    stream << obj.getMonthName() << ": " << obj.getMonthNum() << std::endl;
    return stream;
}
std::istream &operator >> (std::istream &stream, Month& obj)
{
    int number;
    std::string name;

    std::cout << "Month name: ";
    std::cin >> name;
    // convert all letters to lowercase to compare
    for(int i = 0; i < name.length(); i++)
        name[i] = tolower(name[i]);
    // validate that the month name is valid
    while (name != "january" && name != "february" && name != "march" && name != "april" && name != "may" && name != "june" && name != "july" && name != "august" && name != "september" && name != "october" && name != "november" && name != "december")
    {
        std::cout << "Please enter a valid month name" << std::endl;
        std::cin >> name;
        for(int i = 0; i < name.length(); i++)
            name[i] = tolower(name[i]);
    }
    // capitalize the first letter
    name[0] = toupper(name[0]);
    obj.setMonthName(name);
    obj.updateMonthNum(); // update the month number

    std::cout << "Month number: ";
    std::cin >> number;

    while (number != obj.monthNum)
    {
        std::cout << "Please enter a matching number to the month you entered: ";
        std::cin >> number;
    }
    obj.setMonthNum(number);

    return stream;
}
