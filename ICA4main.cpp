// Ethan Nichols and Sarah Tempelmeyer
#include <iostream>
#include <iomanip>
#include "class.h"

using namespace std;

int main()
{
    // declare variables
    double loanAmount, AinterestRate;
    int year;

    // prompt the user to enter a loan amount, interest rate, and years
    // read in to variables
    cout << "Please enter the loan amount: ";
    cin >> loanAmount;

    cout << "Please enter the annual interest rate: ";
    cin >> AinterestRate;

    cout << "Please enter the years for the loan: ";
    cin >> year;

    // create class object and initialize using overload constructor
    Bank B1(loanAmount, AinterestRate, year);

    // calculate and display the payment amount
    B1.calculatePayment();
    cout << fixed << setprecision(2) << "Monthly payment: " << B1.getPayment() << endl;
    cout << "Total amount paid back: " << (B1.getPayment()*12*B1.getYears()) << endl;

    // prompt user for new annual interest rate
    cout << "Please enter the adjusted annual interest rate: ";
    cin >> AinterestRate;

    // change that private member of the bank class B1 object
    B1.setInterestRate(AinterestRate);
    // calculate and display the new payment amount
    B1.calculatePayment();

    // output the new monthly payment and adjusted total amount paid back to the console
    cout << "Adjusted monthly payment: " << B1.getPayment() << endl;
    cout << "Adjusted total amount paid back: " << (B1.getPayment()*12*B1.getYears()) << endl;

    return 0;
} // end function main
