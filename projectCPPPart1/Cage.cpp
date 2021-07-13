#include "Cage.h"

Cage::Cage(int type): cageType(type)
{
    //TODO find a different way to define the animalsCount and the animals
    this->maxAnimals = 20;
    this->animals = new Animal*[maxAnimals];
}
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
    //TODO change the type to ENUM
    cout << "The cage type is " << cage.cageType << " and the number of animals is " <<  cage.animalsCount << endl;
    for (int i = 0; i < cage.animalsCount; i++)
        cout << "\nAnimal number #" << i << ":\n" << *(cage.animals[i]) << endl;
    
    return o;
}
void Cage::addAnimal(Animal* animal)
{
    animals[animalsCount++] = animal;
}
void Cage::removeAnimal(int sn)
{
    for (int i = 0; i < animalsCount; i++) {
        if (animals[i]->getSerialNumber() == sn)
        {
            delete &animals[i];
            animalsCount--;
        }
    }
}
Cage* Cage::operator+=(const Cage& other)
{
    if(other.getType() == this->getType())
    {
        for (int i = 0; i < other.animalsCount; i++)
            addAnimal(other.animals[i]);
        return this;
    }
    cout<< " Cage type dont match, Its danguras to mixed them !!!!";
    return NULL;
}

Cage* Cage::operator+=(Animal* other)
{
    // TODO check if correct
    addAnimal(other);
    return this;
}