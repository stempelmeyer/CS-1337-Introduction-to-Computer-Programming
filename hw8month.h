#ifndef MONTH_H
#define MONTH_H
#include <string>

class Month
{
private:
    std::string monthName;
    int monthNum;
public:
    Month() { monthName = "January"; monthNum = 1; } // default constructor
    Month(std::string); // overload constructor sets month name and number based on string argument
    Month(int); // overload constructor sets month name and number based on int argument
    Month(const Month& obj)
        { monthName = obj.monthName; monthNum = obj.monthNum; } // copy constructor
    void updateMonthName();
    void updateMonthNum();
    void setMonthName(std::string);
    void setMonthNum(int);
    std::string getMonthName() const
        { return monthName; }
    int getMonthNum() const
        { return monthNum; }
    Month operator++(); // prefix operator
    Month operator++(int); // postfix operator
    Month operator--(); // prefix operator
    Month operator--(int); // postfix operator

    friend std::ostream &operator << (std::ostream&, const Month&);
    friend std::istream &operator >> (std::istream&, Month&);
}; // class declaration

#endif
