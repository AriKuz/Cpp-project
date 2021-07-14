#include "Crocodile.h"

void Crocodile::makeSound() const
{
    cout << "Crocodile " << name << " says crack.";
}

void Crocodile::eat()
{
    cout << "Crocodile " << name << " is eating meat." << endl;
    this->operator++();
}

const Crocodile& Crocodile::operator++()
{
    weight = weight + 1;
    return *this;
}

void Crocodile::swim() const
{
    cout << "Crocodile is swimming" << endl;
}

ostream& operator<<(ostream& o, const Crocodile& a)
{
    o << (Animal&)a << "\nserial number: " << a.serialNumber
      << "\nname: " << a.name
      << "\nheight: " << a.height
      << "\nweight: " << a.weight
      << "\nswim speed: " << a.speedSwim
      << "\ntemperature:" << a.getTemp();
    return o;
}