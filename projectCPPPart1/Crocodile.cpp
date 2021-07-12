#include "Crocodile.h"

Crocodile::Crocodile(int sn, const char *nme, float h, float w, int sps, const Crocodile &other) :
Reptile(sn, nme, h,w), CanSwin(sps) {
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);

}
Crocodile::Crocodile(int sn, const char *nme, float h, float w, int sps, Crocodile &&other) :
Reptile(sn, nme, h, w), CanSwin(sps) {
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);
    other.name = nullptr;
}

Crocodile::~Crocodile(){
    delete []name;
}
void Crocodile::makeSound() const
{
    cout << "Crocodile " << name << " says crack.";
}

void Crocodile::eat()
{
    cout << "Lion " << name << " is eating meat." << endl;
    this->operator++();
}

const Crocodile& Crocodile::operator++()
{
    weight = weight + 1;
    return *this;
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
