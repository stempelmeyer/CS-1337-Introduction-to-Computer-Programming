#include <iostream>
#include <string>

using namespace std;

// function prototype
int palindrome(string, int, int);

int main()
{
    string word = "avid diva";

    if(palindrome(word,0,word.length()-1))
        cout << "The word: " << word << " is a palindrome!" << endl;
    else
        cout << "The word: " << word << " is not a palindrome" << endl;
}

int palindrome(string word, int forwards, int backwards){
    if (forwards >= word.length() || backwards <= 0)
        return 1;
    else if (word[forwards]==word[backwards])
        return palindrome(word,forwards+1,backwards-1);
    else
        return 0;
}
