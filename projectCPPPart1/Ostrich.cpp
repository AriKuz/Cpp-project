#include "Ostrich.h"

Ostrich::Ostrich(const Ostrich &other) : Bird(other.serialNumber, other.name, other.height, other.weight, other.colorOfFeathers, other.sizeOfBeak, other.type)
{
     this->name = new char[strlen(other.name) + 1];
     strcpy(this->name, other.name); 
}

Ostrich::Ostrich(Ostrich &&other) : Bird(other.serialNumber, other.name, other.height, other.weight, other.colorOfFeathers, other.sizeOfBeak, other.type)
{
     this->name = new char[strlen(other.name) + 1];
     strcpy(this->name, other.name);
     other.name = nullptr;
} 

Ostrich::~Ostrich(){
    delete []name;
}
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
