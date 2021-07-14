#include "Animal.h"

Animal::Animal(int sn, const string& nme, float height1, float weight1, int type):serialNumber(sn),name(nme), height(height1), weight(weight1),type(type){}
Animal::~Animal(){
    cout << "~Animal" << endl;
}

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