// Author:          Sarah Tempelmeyer and Nooreen Ahmad
// Course:          CS 1337.007
// Date:            4/17/2018
// Assignment:      ICA 5
// Compiler:        Code::Blocks

#include <iostream>
#include "workday.h"

using namespace std;

int main()
{
    Numdays object1(12.0);
    Numdays object2 (object1);

    object1.setHours(18);
    cout << "The first object contains " << object1.getHours() << " hours" << endl;
    cout << "The first object contains " << object1.getDays() << " days" << endl;

    cout << "Addition of object hours " << object1 + object2 << endl;
    cout << "Subtraction of object1 - object2 " << object1 - object2 << endl;
    cout << "Subtraction of object2 - object1 " << object2 - object1 << endl;
    cout << "Prefix increment of object 1 " << ++object1 << endl;
    cout << "Postfix increment of object 2 " << object2++ << endl;
    cout << "Object 1 < object 2? " << (object1 < object2) << endl;
    cout << "Object 1 > object 2? " << (object1 < object2) << endl;
    cout << "Object 1 " << object1 << endl;
    cout << "Object 2 " << object2 << endl;

    return 0;
}
