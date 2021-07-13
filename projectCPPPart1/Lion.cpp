#include "Lion.h"
#include <iostream>
using namespace std;

void Lion::makeSound() const
{
    cout << "Lion " << name << " makes roarrrrr.";
}

void Lion::eat()
{
    cout << "Lion " << name << " is eating food." << endl;
    this->operator++();
}

const Lion& Lion::operator++()
{
    weight = weight + 1;
    return *this;
}

ostream& operator<<(ostream& o, const Lion& a)
{
    o << (Animal&)a << "\nserial number: " << a.serialNumber
                    << "\nname: " << a.name
                    << "\nheight: " << a.height
                    << "\nweight: " << a.weight
                    << "\number of legs: " << a.numberOfLegs << endl;
    return o;
}