#ifndef ABSTRACT_H
#define ABSTRACT_H

class BasicShape
{
    double area;
    double perimeter;
public:
    double getArea();
    double getPerimeter();
    virtual void calcArea() = 0; // pure virtual function
    virtual void calcPerimeter() = 0; // pure virtual function
};

#endif // ABSTRACT_H
