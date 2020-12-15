#include <iostream>
#include <string>

using namespace std;

class PersonData
{
private:
    string first;
    string last;
    string address;
public:
    PersonData(){first = "", last = ""; address = "";}
    PersonData(string f, string l, string a){first = f; last = l; address = a;}
};

class CustomerData : public PersonData
{
private:
    int customerNum;
public:
    CustomerData():PersonData(){customerNum = 0;}
    CustomerData(string f, string l, string a, int n):PersonData(f,l,a){customerNum = n;}
    bool operator < (CustomerData &);
};

bool CustomerData::operator < (CustomerData &obj)
{
    if (customerNum < obj.customerNum)
        return true;
    else
        return false;
}

int main()
{
    CustomerData obj1("Sarah", "Tempelmeyer","1529 Primrose", 200);
    CustomerData obj2("Haley", "Nowak", "3179 Mockingbird", 300);

    if (obj2 < obj1)
        cout << "Haley has a smaller customer number than Sarah" << endl;
    if (obj1 < obj2)
        cout << "Sarah has a smaller customer number than Haley" << endl;
    else
        cout << "Haley and Sarah have equal customer numbers" << endl;

    system("pause");
    return 0;
}
