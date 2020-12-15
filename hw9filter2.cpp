// Author:          Sarah G. Tempelmeyer
// Net ID:          sgt 170030
#include <fstream>
#include "filter2.h"
#include <iostream>

char Uppercase::transform(char ch)
{
    int ascii = (int)ch;
    if(ascii > 96 && ascii < 123) // the letter is lowercase
    {
        ch = (char)(ascii-32);
    }
    return ch;
}

void Uppercase::doFilter(std::ifstream &in, std::ofstream &out) // overridden function
{
    char ch;
    while(!in.eof())
    {
        in.get(ch);
        if(!in.eof())
            out << transform(ch);
    }
}
