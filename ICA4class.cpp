// Ethan Nichols and Sarah Tempelmeyer
#include "class.h"
#include <cmath>

// default constructor
Bank::Bank()
{
    payment = 0;
    loan = 0;
    interestRate = 0;
    years = 0;
}
// overload constructor
Bank::Bank(double l, double ir, int yrs)
{
    // if interest rate is a percentage, turn into a decimal
    if (ir >= 1)
        ir /= 100;
    loan = l;
    // change annual into monthly interest rate
    interestRate = ir / 12;
    years = yrs;
}
// interest rate mutator
void Bank::setInterestRate(double ir)
{
    // if interest rate is a percentage, turn into a decimal
    if (ir >= 1)
        ir /= 100;
    interestRate = ir / 12;
}
// calculate payment function
void Bank::calculatePayment()
{
    double term;
    term = pow((1 + interestRate), (years *12));
    payment = (loan * interestRate * term) / (term - 1);
}
