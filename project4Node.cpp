// Author:          Sarah G. Tempelmeyer
// Student ID:      sgt170030
#include <iostream>
#include <string>
#include "Node.h"

// default constructor function
Node::Node()
{
    coefficient = 1;
    exponent = 1;
}
// overload constructor function
Node::Node(double coeff, int exp)
{
    coefficient = coeff;
    exponent = exp;
}
