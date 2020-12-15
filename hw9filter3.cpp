// Author:          Sarah G. Tempelmeyer
// Net ID:          sgt 170030
#include <fstream>
#include "filter3.h"

void Copy::doFilter(std::ifstream &in, std::ofstream &out) // overridden function
{
    char ch;
    while(!in.eof())
    {
        in.get(ch);
        if(!in.eof()) // if not at the end of the input file
            out << ch;
    }
}
