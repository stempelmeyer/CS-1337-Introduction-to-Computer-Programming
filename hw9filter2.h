// Author:          Sarah G. Tempelmeyer
// Net ID:          sgt 170030
#ifndef FILTER2_H
#define FILTER2_H

#include <fstream>
#include "abstract.h"

class Uppercase : public Abstract
{
public:
    char transform(char ch);
    void doFilter(std::ifstream&, std::ofstream&); // overridden function
};

#endif // FILTER2_H
