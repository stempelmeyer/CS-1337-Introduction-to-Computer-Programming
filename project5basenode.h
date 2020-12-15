// Author:          Sarah G. Tempelmeyer
// Student ID:      sgt170030

#ifndef BASENODE_H
#define BASENODE_H

#include <string>
#include <fstream>
#include <string>
#include <iostream>

class Node
{
protected:
    std::string roman;
    int arabic;
public:
    Node() { roman = ""; arabic = -1; } // default constructor assigns empty string and -1 to arabic
    Node(std::string rom, int arab) { roman = rom; arabic = arab; } // overload constructor assigns string/int to roman/arabic
    Node(const Node &obj); // copy constructor
    virtual std::string getRoman() const = 0; // pure virtual function
    int getArabic() const { return arabic; } // arabic accessor
    void setRoman(std::string rom) { roman = rom; } // roman mutator
    void setArabic(int arab) { arabic = arab; } // arabic mutator
    friend std::ostream& operator << (std::ostream&, const Node*);
    friend std::istream& operator >> (std::istream&, Node&);
    int romanToArabic(std::string);
    std::string arabicToRoman(int);
};
#endif // BASENODE_H
