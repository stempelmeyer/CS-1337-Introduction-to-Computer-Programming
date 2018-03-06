// Author:          Sarah G. Tempelmeyer
// Course:          CS 1337.007
// Date:            1/23/2018
// Assignment:      Review Homework #2
// Compiler:        Code::Blocks

// Description: This program extracts and displays all vowels
// in a file using a single filestream.

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    // declare variables
    string iFileName;
    string oFileName = "vowels_";
    fstream file;
    char letter;
    int position = 0;
    bool eof = false;

    // read in file name
    cout << "Please enter the name of the file: ";
    cin >> iFileName;

    // new name for output file
    oFileName += iFileName;

    // open input file
    file.open(iFileName, ios::in | ios::binary);

    // if the file doesn't open, display error and end program
    if(file.fail()){
        cout << "File could not be opened" << endl;
        return 0;
    }

    // use get to read elements into character by character
    file.get(letter);

    // while the last read operation was successful, continue
    while (!file.eof()){
        //eof = file.eof();
        position++;
        file.close();
        // if the character read in was a vowel or new line, open output file and display vowel
        if (letter == 'A' || letter == 'a' || letter == 'E'|| letter == 'e'|| letter == 'I'|| letter == 'i'|| letter == 'O'|| letter == 'o'|| letter == 'U'|| letter == 'u'|| letter == 'Y'|| letter == 'y' || letter == '\n'){
                file.open(oFileName, ios::out | ios::app);
                file << letter;
                file.close();
        }
        // open input file again and begin reading from where last finished by using seekg and position
        file.open(iFileName, ios::in | ios :: binary);
        file.seekg(position, ios::beg);
        file.get(letter);
}
    //close input file
    file.close();

return 0;
}
