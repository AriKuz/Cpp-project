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
ostream& operator<< (ostream& o, const Cage& cage)
{
    //TODO oschwart -> change the typeto ENUM
    cout << "The cage type is " << cage.cageType << " and the number of animals is " <<  cage.animalsCount << endl;
    for (int i = 0; i < cage.animalsCount; i++)
        cout << "Animal number #" << i << ": " << cage.animals[i];
    
    return o;
}
void Cage::addAnimal(Animal& animal)
{
    animals[animalsCount++] = &animal;
}
void Cage::removeAnimal(int sn)
{
    for (int i = 0; i < animalsCount; i++) {
        if (animals[i]->getSerialNumber() == sn)
            delete &animals[i];
    }
}
Cage* Cage::operator+=(const Cage& other)
{
    for (int i = 0; i < other.animalsCount; i++)
        addAnimal(*(other.animals[i]));

    return this;
}
Cage* Cage::operator+=(Animal& other)
{
    // TODO check if correct
    addAnimal(other);
    return this;
}