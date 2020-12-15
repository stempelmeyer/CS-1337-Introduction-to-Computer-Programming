// Author:          Sarah G. Tempelmeyer
// Student ID:      sgt170030
// Course:          CS 1337.007
// Date:            2/17/2018
// Assignment:      Project #2
// Compiler:        Code::Blocks

// Description: This program converts validates a sudoku puzzle
// using dynamic arrays and pointer arithmetic.

#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

// function prototypes
int checkColumns(char*);
int checkRows(char*);
int checkGrid(char*);

int main()
{
    // declare file streams, arrays, and variables
    ifstream ifile("puzzles.txt");
    ofstream ofile("solutions.txt");
    // grid names should be dynamic...
    string gridNames[9] = { "Upper left", "Upper middle", "Upper right", "Middle left", "Center", "Middle right", "Lower left", "Lower middle", "Lower right" };
    string* gridptr = gridNames;
    char* ptr = new char[81];
    char* ptr2 = ptr;
    bool solved, invalid;
    int result;
    string puzzleNum, line;

    if (!ifile){
        cout << "File could not be opened" << endl;
        return 1;
    }

    //while able to read in a number for the next puzzle
    while (getline(ifile, puzzleNum))
    {
        // assign solved and invalid to "default" values
        solved = true;
        invalid = false;

        // read the puzzle into a dynamic array
        for (int elements = 1; elements <= 9; elements++)
        {
            // read in each line and assign the line elements to the array with a dereferenced pointer
            getline(ifile, line);
            for (int i = 0; i < 9; i++, ptr++)
            {
                *ptr = line.at(i);
                // check if the puzzle has spaces (not solved) or newlines (read in another)
                if (*ptr == ' ')
                    solved = false;
            }
        }

        // move pointer back before sending through for loop which function calls to check each 9 rows
        ptr = ptr2;
        for (int i = 1; i <= 9; i++)
        {
            result = checkRows(ptr);
            // if the function returns that there are multiple numbers of something (not -1). Invalid is now true
            if (result != -1)
            {
                ofile << left << setw(8) << puzzleNum << "invalid         multiple " << result-48 << "s in row " << i << endl;
                invalid = true;
            }
            // move pointer to next row
            ptr += 9;
        }

        // move pointer back before sending through for loop which checks each column 9 times through the function
        ptr = ptr2;
        for (int i = 1; i <= 9; i++, ptr++)
        {
            result = checkColumns(ptr);
            // if the function returns that there are multiple numbers of something (not -1). Change invalid to true
            if (result != -1)
            {
                ofile << left << setw(8) << puzzleNum << "invalid         multiple " << result-48 << "s in column " << i << endl;
                invalid = true;
            }
        }

        // move pointer back before sending through for loop to check for each 9 grids
        ptr = ptr2;
        for (int i = 1; i <= 9; i++, gridptr++)
        {
            // this will move the pointer to the next grid if it is at the 3rd or 6th grid it is sending to the function
            if ((i - 1) % 3 == 0 && (i - 1) != 0)
                ptr += 18;
            result = checkGrid(ptr);
            // if the function returns that there are multiple numbers of something (not -1). Invalid is now true
            if (result != -1)
            {
                ofile << left << setw(8) << puzzleNum << "invalid         multiple " << result-48 << "s in " << *gridptr << endl;
                invalid = true;
            }
            // this moves the pointer to the grid to the right of it
            ptr += 3;
        }

        // this will set the pointer for the grid names back at the beginning
        gridptr -= 9;

        // if puzzle is invalid and has no spaces, it is solved
        if (!invalid && solved)
        {
            ofile << left << setw(8) << puzzleNum << "solved" << endl;
        }
        // if puzzle is not invalid and has spaces, it is valid
        else if (!invalid && !solved)
        {
            ofile << left << setw(8) << puzzleNum << "valid" << endl;
        }

        // move pointer back to the beginning of the array
        ptr = ptr2;
        // this getline reads in the newline
        getline(ifile, puzzleNum);
    } // end while iteration of that puzzle
    ofile.close();

    // delete the dynamically allocated array
    delete [] ptr2;

    return 0;
} // end function main

// this function will check each of the sudoku rows by reading in the char pointer at the beginning
// of each row as the argument. it will return the repeated number or a -1
int checkRows(char* rows)
{
    // this is the compare pointer
    char* compare = nullptr;

    // outer for loop will move rows and compare it with columns multiple times before incrementing
    for (int columns = 1; columns < 9; columns++, rows++)
    {
        compare = rows;
        // the inner for loop is comparing the compare pointer to all the elements after the row pointer
        for (int i = columns; i < 9; i++)
        {
            compare++;
            // if the elements are equal and are not spaces, then return the repeated number
            if (*rows == *compare && *rows != ' ')
                return *compare;
        }
    }
    // if no numbers repeated, return -1
    return -1;
} // end function checkRows

// this function will check each of the sudoku columns by reading in the char pointer at the beginning
// of each column as the argument. it will return the repeated number or a -1
int checkColumns(char* columns)
{
    // this is the compare pointer
    char* compare = nullptr;

    // outer for loop will move columns and compare it with columns multiple times before incrementing
    for (int rows = 1; rows < 9; rows++)
    {
        compare = columns;
        // the inner for loop is comparing the compare pointer to all the elements after the column pointer
        for (int i = rows; i < 9; i++)
        {
            compare += 9;
            // if the elements are equal and are not spaces, then return the repeated number
            if (*columns == *compare && *columns != ' ')
                return *compare;
        }
        columns += 9;
    }
    // if no numbers repeated, return -1
    return -1;
} // end function checkColumns

// this function will check each of the sudoku grids by reading in the char pointer at the beginning
// of each grid as the argument. it will return the repeated number or a -1
int checkGrid(char* grid)
{
    // this is the compare pointer
    char* compare = nullptr;

    // outer for loop will move through the grid and compare it with compare multiple times before incrementing
    for (int i = 1; i < 9; i++, grid++)
    {
        // this will move the pointer to the next row if reached the 4th row it is analyzing
        if ((i - 1) % 3 == 0 && (i - 1) != 0)
            grid += 6;
        compare = grid;
        compare++;
        // the inner for loop is comparing the compare pointer to all the elements in the grid after the grid pointer
        for (int j = i; j < 9; j++, compare++)
        {
            // this will move the pointer to the next row if reached the 4th row it is analyzing
            if (j % 3 == 0 && j != 0)
                compare += 6;
                // if the elements are equal and are not spaces, then return the repeated number
            if (*grid == *compare && *compare != ' ')
                return *compare;
        }
    }
    // if no numbers repeated, return -1
    return -1;
} // end function checkGrid
