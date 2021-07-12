#include "Bird.h"

Bird::~Bird(){
    delete []name;
}
Bird::Bird(int sn, const char *nme, float height1, float weight1, const Bird &other, int type) : Animal(sn, nme, height1, weight1, type) {

    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);

}
Bird::Bird(int sn, const char *nme, float height1, float weight1, Bird &&other, int type) : Animal(sn, nme, height1, weight1, type) {
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