// Ethan Nichols and Sarah Tempelmeyer
#ifndef CLASS_H
#define CLASS_H

// declare a class for a bank account
class Bank
{
private:
    double payment;
    double loan;
    double interestRate;
    int years;
public:
    Bank();                         // default constructor
    Bank(double, double, int);      // overload constructor
    void setLoan(double l)          // loan mutator
        { loan = l; }
    void setInterestRate(double);   // interest rate mutator
    void setYears(int yrs)          // years mutator
        { years = yrs; }
    double getLoan()                // loan accessor
        { return loan; }
    double getInterestRate()        // interest rate accessor
        { return interestRate; }
    int getYears()                  // years accessor
        { return years; }
    double getPayment()             // payment accessor
        { return payment; }
    void calculatePayment();        // calculate payment function
};

#endif // CLASS_H
