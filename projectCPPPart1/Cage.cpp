#include "Cage.h"

Cage::Cage(int type): cageType(type){}
Cage::Cage(const Cage& other)
{
    this->cageType = other.cageType;
    this->animalsCount = other.animalsCount;

    this->animals = new Animal*[animalsCount];
    for (int i = 0; i < animalsCount; i++)
        animals[i] = other.animals[i];
}
Cage::Cage(Cage&& other)
{
    this->cageType = other.cageType;
    this->animalsCount = other.animalsCount;
    std::swap(animals, other.animals);
}
Cage::~Cage()
{
    delete[] this->animals;
}
ostream& operator<< (ostream& o, const Cage& a);
void Cage::addAnimal(Animal& animal);
void Cage::removeAnimal(int sn);
const Cage::Cage& operator+=(const Cage& other);
const Cage::Cage& operator+=(const Animal& other);
int Cage::getType() const { return cagetype;};