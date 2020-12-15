// Author:          Sarah G. Tempelmeyer
// Net ID:          sgt 170030
#ifndef FILTER3_H
#define FILTER3_H

#include <fstream>
#include "abstract.h"

class Copy : public Abstract
{
public:
    void doFilter(std::ifstream&, std::ofstream&); // overridden function
};

#endif // FILTER3_H
