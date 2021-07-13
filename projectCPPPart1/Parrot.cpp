#include "Parrot.h"

Parrot::Parrot(int sn, const string& nme, float h, float w, const string& coth, float sob, int spOf) : Bird(sn, nme, h, w, coth, sob, PARROT_TYPE), Canfly(spOf) {}


/*
Parrot::Parrot(const Parrot& other) : Bird(other.serialNumber, other.name, other.height, other.weight, other.colorOfFeathers, other.sizeOfBeak, other.type), Canfly(10) {}

Parrot::Parrot(Parrot&& other) : Bird(other.serialNumber, other.name, other.height, other.weight, other.colorOfFeathers, other.sizeOfBeak, other.type), Canfly(10)
{
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);
    other.name = nullptr;
}
*/
void Parrot::fly() const
{
    cout << "Parrot is flying with a speed of " << speedOfFlyt << endl;
}

const Parrot& Parrot::operator++()
{
    speedOfFlyt++;
    return *this;
}

void Parrot::eat()
{
    cout << "Parrot is eating" << endl;
}

void Parrot::makeSound() const
{
    cout << "Yeee I am Parrot" << endl;
}