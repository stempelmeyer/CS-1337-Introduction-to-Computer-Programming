// Author:          Sarah G. Tempelmeyer
// Net ID:          sgt 170030
#ifndef ABSTRACT_H
#define ABSTRACT_H
#include <fstream>

class Abstract
{
public:
    virtual void doFilter(std::ifstream &in, std::ofstream &out) = 0; // pure virtual function
};

#endif
