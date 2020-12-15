// Author:          Sarah G. Tempelmeyer
// Student ID:      sgt170030
#ifndef NODE_H
#define NODE_H

class Node{
private:
    double coefficient;
    int exponent;
    char operation;
public:
    Node *next = nullptr;
    Node();                     // default constructor
    Node(double, int);          // overload constructor
    void setExponent(int exp)
        { exponent = exp; }
    void setCoefficient(double coeff)
        { coefficient = coeff; }
    void setOperation(char op)
        { operation = op; }
    int getExponent()
        { return exponent; }
    double getCoefficient()
        { return coefficient; }
    char getOperation()
        { return operation; }
};
#endif // NODE_H
