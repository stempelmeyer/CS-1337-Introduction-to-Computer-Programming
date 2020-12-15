#ifndef WORKDAY_H
#define WORKDAY_H

class Numdays
{
private:
    double hours;
    double days;
public:
    NumDays() {hours = 0; days = 0;}
    NumDays(double hrs) {hours = hrs; days = hours/8;}//constructor
    Numdays (const Numdays &obj);       // copy constructor
    double getHours() const {return hours;}
    double getDays() const {return days;}
    void setHours(double hrs) {hours = hrs;}
    void setDays(double dys) {days = dys;}
    void updateDays(double hrs);
    double operator + (const Numdays &obj);
    double operator - (const Numdays &obj);
    Numdays& operator ++ ();            // prefix
    Numdays operator ++ (int);          // postfix
    bool operator > (const Numdays &obj);
    bool operator < (const Numdays &obj);
    friend std::ostream& operator << (std::ostream &out, const Numdays &obj);
};

#endif // WORKDAY_H
