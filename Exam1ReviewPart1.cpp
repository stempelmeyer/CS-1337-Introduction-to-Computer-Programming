#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    const int SIZE = 25;
    fstream file("names.txt", ios::in);
    string nameArray[SIZE];
    int numNames = 0;
    bool flip = true;
    string temp;
    char space;

    if (!file)
    {
        cout << "The file \"names.txt\" could not be opened" << endl;
        return 0;
    }

    // read in the names into an array
    while (!file.eof())
    {
        getline(file, nameArray[numNames], ',');
        file.get(space);
        numNames++;
    }
    file.close();

    // sort the array, from Z to A, pushing 0 to very end (high to low ASCII number)
    while (flip)
    {
        flip = false;
        for (int i = 0; i < numNames - 1; i++)
        {
            if (nameArray[i] < nameArray[i+1])
            {
                flip = true;
                temp = nameArray[i+1];
                nameArray[i+1] = nameArray[i];
                nameArray[i] = temp;
            }
        }
    }

    file.open("names.txt", ios::out);
    // get ready to output names at the beginning of the file
    file.seekp(0,ios::beg);
    // display non-zero elements of array
    for (int i = 0; i < numNames; i++)
        file << nameArray[i] << endl;
    file.close();

    cout << "Done!" << endl;

    return 0;
}
