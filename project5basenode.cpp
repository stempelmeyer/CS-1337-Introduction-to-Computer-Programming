// Author:          Sarah G. Tempelmeyer
// Student ID:      sgt170030

#include "basenode.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

// copy constructor
Node::Node(const Node &obj)
{
    roman = obj.roman;
    arabic = obj.arabic;
}

int Node::romanToArabic(std::string rom)
{
    // declare the accumulator which will add up to the arabic number
    int accumulator = 0;

    for (unsigned int i = 0; i < rom.length(); i++)
    {
        // this if statement makes sure that it compares the elements within valid subscripts
        // if any of these if statements are true, continue to the next iteration
        if (i < rom.length()-1)
        {
            // if CM add 900 to arabic number, and increment i (to now avoid reading the second letter twice)
            if (rom.at(i)=='C' && rom.at(i+1)=='M')
            {
                accumulator+=900;
                i++;
                continue;
            }
            // if CD add 400 to arabic number, and increment i (to now avoid reading the second letter twice)
            else if (rom.at(i)=='C' && rom.at(i+1)=='D')
            {
                accumulator+=400;
                i++;
                continue;
            }
            // if XC add 90 to arabic number, and increment i (to now avoid reading the second letter twice)
            else if (rom.at(i)=='X' && rom.at(i+1)=='C')
            {
                accumulator+=90;
                i++;
                continue;
            }
            // if XL add 40 to arabic number, and increment i (to now avoid reading the second letter twice)
            else if (rom.at(i)=='X' && rom.at(i+1)=='L')
            {
                accumulator+=40;
                i++;
                continue;
            }
            // if IX add 9 to arabic number, and increment i (to now avoid reading the second letter twice)
            else if (rom.at(i)=='I' && rom.at(i+1)=='X')
            {
                accumulator+=9;
                i++;
                continue;
            }
            // if IV add 4 to arabic number, and increment i (to now avoid reading the second letter twice)
            else if (rom.at(i)=='I' && rom.at(i+1)=='V')
            {
                accumulator+=4;
                i++;
                continue;
            }
        }
        // if M, D, C, L, X, V, I add 1000, 500, 100, 50, 10, 5, 1 respectively
        if (rom.at(i) == 'M')
            accumulator += 1000;
        if (rom.at(i) == 'D')
            accumulator += 500;
        if (rom.at(i) == 'C')
            accumulator += 100;
        if (rom.at(i) == 'L')
            accumulator += 50;
        if (rom.at(i) == 'X')
            accumulator += 10;
        if (rom.at(i) == 'V')
            accumulator += 5;
        if (rom.at(i) == 'I')
            accumulator += 1;
    }
    return accumulator;
}
std::string Node::arabicToRoman(int arab)
{
    // declare variables
    int remainder = 0;
    std::string rom;

    // if arabic is more than or equal to 1000, add M to each 1000
    if ((arab/1000) > 0)
    {
        for (int i = 0; i < (arab/1000); i++)
            rom += 'M';
    }
    // assign remainder and arabic to remainder of 1000
    remainder = arab % 1000;
    arab %= 1000;
    // use switch statement comparing result of amount of hundreds place of remainder
    switch(remainder/100)
    {
    // add CM to string if hundreds place is 9
    case 9:
        rom += "CM";
        break;
    // add D to string if hundreds place is 8, 7, 6, 5 and C to each 6, 7, 8
    case 8:
    case 7:
    case 6:
    case 5:
        rom += 'D';
        for (int i = 0; i < ((remainder/100)-5); i++)
            rom += 'C';
        break;
    // add CD if hundreds place is 4
    case 4:
        rom += "CD";
        break;
    // add C for each hundreds under 4
    case 3:
    case 2:
    case 1:
        for (int i = 0; i < (remainder/100); i++)
            rom += 'C';
        break;
    }
    // assign remainder and arabic to remainder of 100
    remainder = arab % 100;
    arab %= 100;
    // use switch statement comparing result of amount of tens place of remainder
    switch(remainder/10)
    {
    // add XC to string if tens place is 9
    case 9:
        rom += "XC";
        break;
    // add L to string if tens place is 8, 7, 6, 5 and X to each 6, 7, 8
    case 8:
    case 7:
    case 6:
    case 5:
        rom += 'L';
        for (int i = 0; i < ((remainder/10)-5); i++)
            rom += 'X';
        break;
    // add XL if tens place is 4
    case 4:
        rom += "XL";
        break;
    // add C for each hundreds under 4
    case 3:
    case 2:
    case 1:
        for (int i = 0; i < (remainder/10); i++)
            rom += 'X';
        break;
    }
    // assign remainder and arabic to remainder of 10
    remainder = arab % 10;
    arab %= 10;
    // use switch statement comparing result of remainder
    switch(remainder)
    {
    // add IX if remainder is 9
    case 9:
        rom += "IX";
        break;
    // add V if remainder is 8, 7, 6, 5 and I to each 6, 7, 8
    case 8:
    case 7:
    case 6:
    case 5:
        rom += 'V';
        for (int i = 0; i < (remainder-5); i++)
            rom += 'I';
        break;
    // add IV if remainder is 4
    case 4:
        rom += "IV";
        break;
    // add I to each remainder under 4
    case 3:
    case 2:
    case 1:
        for (int i = 0; i < remainder; i++)
            rom += 'I';
        break;
    } // end switch statement
    return rom;
}

// overload operator
std::istream& operator >> (std::istream& in, Node& obj)
{
    std::string input;
    std::cout << "Please enter a value for a roman numeral or arabic number: ";
    in >> input;
    if (isupper(input[0])){ // input is roman
        obj.setRoman(input); // set roman of new node
        obj.setArabic(obj.romanToArabic(input)); // set arabic of new node
    }
    else{ // input is arabic
        obj.setArabic(stoi(input)); // set arabic of new node
        obj.setRoman(obj.arabicToRoman(stoi(input))); // set roman of new node
    }
    return in;
}

std::ostream& operator << (std::ostream& out, const Node* obj)
{
    out << std::setw(16) << std::left << obj->getRoman() << " " << std::setw(4) << std::left << obj->getArabic() << std::endl;
    return out;
}
