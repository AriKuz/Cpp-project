#include "Lion.h"
#include <iostream>
using namespace std;


Lion::Lion(const Lion &other) : Mammal(other.serialNumber, other.name, other.height, other.weight, other.numberOfLegs, other.type) {
    cout << "inside Lion:Lion(copy) ";
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);
}
Lion::Lion(Lion&& other) : Mammal(other.serialNumber, other.name, other.height, other.weight, other.numberOfLegs, other.type){
    cout << "inside Lion:Lion(move) ";
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);
    other.name = nullptr;
}

Lion::~Lion(){
    delete []name;
}
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