#include "Animal.h"


void Animal::setHeight(float h){
    this->height = h;
}
void Animal::setWeight(float w){
    this->weight = w;
}

std::ostream &operator<<(std::ostream &o, const Animal &animal){
    return o << "Serial number: " << animal.serialNumber << "\nName: " << animal.name << "\nHeight: " << animal.height
    << "\nWeight: " << animal.weight;
}