// Author:          Sarah G. Tempelmeyer
// Net ID:          sgt 170030
#ifndef FILTER1_H
#define FILTER1_H

#include <fstream>
#include "abstract.h"

class Encryption : public Abstract
{
private:
    int key = 5; // this variable will change the ascii value by this amount
public:
    Encryption(){ key = 5; } // default constructor
    Encryption(int k){ key = k; } // overload constructor
    void doFilter(std::ifstream&, std::ofstream&); // overridden function
};

#endif // FILTER1_H
