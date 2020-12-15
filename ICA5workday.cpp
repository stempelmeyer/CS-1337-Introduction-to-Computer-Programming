#include "workday.h"
#include <iostream>

Numdays::Numdays (const Numdays &obj)       // copy constructor
{
    days = obj.days;
    hours = obj.hours;
}
void Numdays::updateDays(double hrs)
{
    days = hrs / 8;
}
double Numdays::Numdays operator + (const Numdays &obj1, const Numdays &obj2)
{
    return obj1.hours + obj2.hours;
}
double Numdays::Numdays operator - (const Numdays &obj1, const Numdays &obj2)
{
    if (obj1.hours > obj2.hours)
        return obj1.hours - obj2.hours;
    if (obj2.hours > obj1.hours)
        return obj2.hours - obj1.hours;
}
Numdays& Numdays::operator ++ ()            // prefix
{
    hours++;
    updateDays(hours);
    return *this;
}
Numdays Numdays::operator ++ (int)          // postfix
{
    Numdays t = *this;
    ++*this;
    updateDays(hours);
    return t;
}
bool Numdays::operator > (const Numdays &obj)
{
    if(hours > obj.hours)
        return true;
    else
        return false;
}
bool Numdays::operator < (const Numdays &obj)
{
    if(hours < obj.hours)
        return true;
    else
        return false;
}
std::ostream& operator << (ostream &out, const Numdays &obj)
{
    out << "Hours: " << obj.hours << std::endl;
    out << "Days: " << obj.days << std::endl;
    return out;
}
