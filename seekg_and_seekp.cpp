#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    char ch;
    fstream file("letters.txt", ios::in);

    cout << "abcdefghijklmnopqrstuvwxyz" << endl;
    file.seekg(-5L, ios::beg);
    file.get(ch);
    cout << "file.seekg(-5L, ios::beg)" << endl;
    cout << "5th byte from the beginning: " << ch << endl;

    file.seekg(-10, ios::end);
    file.get(ch);
    cout << "file.seekg(-10, ios::end)" << endl;
    cout << "10th byte from end: " << ch << endl;

    file.seekg(3, ios::cur);
    file.get(ch);
    cout << "file.seekg(3, ios::cur)" << endl;
    cout << "3rd byte from current: " << ch << endl;

    file.close();
    return 0;
}
