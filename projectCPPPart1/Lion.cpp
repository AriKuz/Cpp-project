#include "Lion.h"
#include <iostream>
using namespace std;


Lion::Lion(const Lion &other) : Mammal(other.serialNumber, other.name, other.height, other.weight, other.numberOfLegs) {
    this->serialNumber = other.serialNumber;
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);
    this->height = other.height;
    this->weight = other.weight;
    this->numberOfLegs = other.numberOfLegs;
}
Lion::Lion(Lion&& other) : Mammal(other.serialNumber, other.name, other.height, other.weight, other.numberOfLegs){
    this->serialNumber = other.serialNumber;
    this->height = other.height;
    this->weight = other.weight;
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);
    other.name = nullptr;
    this->numberOfLegs = other.numberOfLegs;
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
                    << "\nnumber of legs: " << a.numberOfLegs;
    return o;
}