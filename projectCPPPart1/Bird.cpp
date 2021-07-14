#include "Bird.h"

Bird::~Bird(){
    delete []name;
}
Bird::Bird(const Bird &other) : Animal(other.serialNumber, other.name, other.height, other.weight, other.type) {

    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);

}
Bird::Bird(Bird &&other) : Animal(other.serialNumber, other.name, other.height, other.weight, other.type) {
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);
    other.name = nullptr;
}

ostream& operator<<(ostream& o, const Bird& a)
{
    o << (Animal&)a << "\nserial number: " << a.serialNumber
      << "\nname: " << a.name
      << "\nheight: " << a.height
      << "\nweight: " << a.weight
      << "\ncolor of feathers: " << a.getColorOfFeathers()
      << "\nsize of beak: " << a.getSizeOfBeak();
    return o;
}