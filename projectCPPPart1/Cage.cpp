#include "Cage.h"

Cage::Cage(int type): cageType(type)
{
    this->maxAnimals = 20;
}
Cage::Cage(const Cage& other)
{
    this->cageType = other.cageType;
    this->animals = other.animals;
}
Cage::Cage(Cage&& other)
{
    //TODO: delete other's vector instead of copying the pointers
    this->cageType = other.cageType;
    this->animals = other.animals;
}
Cage::~Cage()
{
}
ostream& operator<< (ostream& o, const Cage& cage)
{
    cout << "The cage type is " << cage.cageType << " and the number of animals is " <<  cage.animals.size() << endl;
    int counter = 1;
    for (auto it = cage.animals.begin(); it != cage.animals.end(); ++it, counter++)
    	cout << "\nAnimal number #" << counter << ":\n" << **it << endl;
    return o;
}
void Cage::addAnimal(Animal* animal)
{
    animals.push_back(animal);
}
int Cage::removeAnimal(int sn)
{
    for (auto it = animals.begin(); it != animals.end(); ++it)
    	if ((*it)->getSerialNumber() == sn)
        {
            animals.erase(it);
            return 1;
        }
    return 0;
}
Cage* Cage::operator+=(const Cage& other)
{
    for (auto it = other.animals.begin(); it != other.animals.end(); ++it)
        addAnimal(*it);
    return this;
}

Cage* Cage::operator+=(Animal* other)
{
    addAnimal(other);
    return this;
}
void Cage::feedAllAnimalsInCage()
{
    for (auto it = animals.begin(); it != animals.end(); ++it)
        (*it)->eat();
}