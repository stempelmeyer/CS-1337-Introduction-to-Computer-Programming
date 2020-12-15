// Author:          Sarah G. Tempelmeyer
// Net ID:          sgt 170030
#include <fstream>
#include "filter1.h"

void Encryption::doFilter(std::ifstream &in, std::ofstream &out)
{
    char ch;
    int i;
    // while not at the end of the input file
    while(!in.eof())
    {
        in.get(ch);
        if(ch == '\n'){ // new line
            out << std::endl;
            continue;
        }
        i = (int)ch + key;
        // rollover the number if greater than 126
        if(i > 126)
            ch = (char)((i % 126) + 31);
        // rollover the number if less that 32
        else if(i < 32)
            ch = (char)(127 - (32 - i));
        else
            ch = (char)i;
        if(!in.eof()) // if not reached the end of file
            out << ch;
    }
}
