#include "Parrot.h"

Parrot::Parrot(int sn, const string& nme, float h, float w, const string& coth, float sob, int spOf) : Bird(sn, nme, h, w, coth, sob, PARROT_TYPE), Canfly(spOf) {}

void Parrot::fly() const
{
    cout << "Parrot is flying with a speed of " << speedOfFlight << endl;
}

const Parrot& Parrot::operator++()
{
    speedOfFlight++;
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