#include "Ostrich.h"

void Ostrich::makeSound() const
{
    cout << "Ostrich " << name << " sticks head in the sand.";
}

void Ostrich::eat()
{
    cout << "Ostrich " << name << " is eating worms." << endl;
    this->operator++();
}

const Ostrich& Ostrich::operator++()
{
    weight = weight + 1;
    return *this;
}

ostream& operator<<(ostream& o, const Ostrich& a)
{
    o << (Animal&)a << "\nserial number: " << a.serialNumber
      << "\nname: " << a.name
      << "\nheight: " << a.height
      << "\nweight: " << a.weight
      << "\ncolor of feathers: " << a.getColorOfFeathers()
      << "\nsize of beak: " << a.getSizeOfBeak();
    return o;
}