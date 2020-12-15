// Author:          Sarah G. Tempelmeyer
// Student ID:      sgt170030
// Course:          CS 1337.007
// Date:            1/30/2018
// Assignment:      Project #1
// Compiler:        Code::Blocks

// Description: This program converts roman numerals to Arabic
// numbers and vice versa using a single filestream.

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;

// function prototypes
int romanToArabic(string roman);
string arabicToRoman(int arabic);

int main()
{
    // declare variables and open file
    fstream file("numbers3.txt", ios::in | ios::out | ios::binary);
    string roman;
    int arabic;
    long position = 0;
    char firstLetter;

    // if the file doesn't open, display error and end program
    if(file.fail()){
        cout << "File could not be opened" << endl;
        return 0;
    }

    // move file pointer to the end, and tellg location for file size, send pointer back to beginning
    file.seekg(0,ios::end);
    int fileSize = file.tellg();
    file.clear();
    file.seekg(0,ios::beg);

    // while not end of file or past the position of the file size. use peek to see if the first character is a space(Arabic) or not(roman)
    while(!file.eof() && position < fileSize){
        firstLetter = file.peek();
        // if not space, read in roman, send to function, move forward, and read out arabic, move forward again to read in next first letter
        if (firstLetter != ' ') {
            file >> roman;
            arabic = romanToArabic(roman);
            file.clear();
            file.seekp(position+16,ios::beg);
            file << left << setw(4) << arabic;
            file.seekg(2,ios::cur);
            position += 22;
        }
        // if space, read in arabic, send to function, move back to beginning of line, output roman, move forward to read in next first letter
        else {
            file >> arabic;
            roman = arabicToRoman(arabic);
            file.clear();
            file.seekp(position, ios::beg);
            file << left << setw(15) << roman;
            file.seekg(7,ios::cur);
            position += 22;
        }
   }
   // close file
   file.close();
   return 0;
}

// this function will convert a roman numeral string to an arabic number and return that number
int romanToArabic(string roman)
{
    // declare the accumulator which will add up to the arabic number
    int accumulator = 0;

    for (int i = 0; i < roman.length(); i++){
        // this if statement makes sure that it compares the elements within valid subscripts
        // if any of these if statements are true, continue to the next iteration
        if (i < roman.length()-1){
            // if CM add 900 to arabic number, and increment i (to now avoid reading the second letter twice)
            if (roman.at(i)=='C' && roman.at(i+1)=='M'){
                accumulator+=900;
                i++;
                continue;
            }
            // if CD add 400 to arabic number, and increment i (to now avoid reading the second letter twice)
            else if (roman.at(i)=='C' && roman.at(i+1)=='D'){
                accumulator+=400;
                i++;
                continue;
            }
            // if XC add 90 to arabic number, and increment i (to now avoid reading the second letter twice)
            else if (roman.at(i)=='X' && roman.at(i+1)=='C'){
                accumulator+=90;
                i++;
                continue;
            }
            // if XL add 40 to arabic number, and increment i (to now avoid reading the second letter twice)
            else if (roman.at(i)=='X' && roman.at(i+1)=='L'){
                accumulator+=40;
                i++;
                continue;
            }
            // if IX add 9 to arabic number, and increment i (to now avoid reading the second letter twice)
            else if (roman.at(i)=='I' && roman.at(i+1)=='X'){
                accumulator+=9;
                i++;
                continue;
            }
            // if IV add 4 to arabic number, and increment i (to now avoid reading the second letter twice)
            else if (roman[i]=='I' && roman.at(i+1)=='V'){
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
    if ((arabic/1000) > 0){
        for (int i = 0; i < (arabic/1000); i++)
        roman += 'M';
    }
    // assign remainder and arabic to remainder of 1000
    remainder = arabic % 1000;
    arabic %= 1000;
    // use switch statement comparing result of amount of hundreds place of remainder
    switch(remainder/100){
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
        for (int i = 0; i < ((remainder/100)-5);i++)
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
        for (int i = 0; i < (remainder/100);i++)
        roman += 'C';
        break;
    }
    // assign remainder and arabic to remainder of 100
    remainder = arabic % 100;
    arabic %= 100;
    // use switch statement comparing result of amount of tens place of remainder
    switch(remainder/10){
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
        for (int i = 0; i < ((remainder/10)-5);i++)
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
        for (int i = 0; i < (remainder/10);i++)
        roman += 'X';
        break;
    }
    // assign remainder and arabic to remainder of 10
    remainder = arabic % 10;
    arabic %= 10;
    // use switch statement comparing result of remainder
    switch(remainder){
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
        for (int i = 0; i < (remainder-5);i++)
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
        for (int i = 0; i < remainder;i++)
        roman += 'I';
        break;
    }// end switch statement
    return roman;
} // end function arabic to roman and return string for the roman numeral
