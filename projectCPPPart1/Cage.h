#ifndef __CAGE_H
#define __CAGE_H
#include "Animal.h"
class Cage
{

private:
	Animal** animals;
	int animalsCount = 0;
	int maxAnimals;
	int cageType;

public:
	Cage(int type);
	Cage(const Cage& other);
	Cage(Cage&& other);
	~Cage();
	friend ostream& operator<< (ostream& o, const Cage& a);
	void addAnimal(Animal* animal);
	int removeAnimal(int sn);
	Cage* operator+=(const Cage& other);
	Cage* operator+=(Animal* other);
	int getType() const { return cageType;};
	int getAnimalsCount() const { return animalsCount;};
	Animal** getAnimals() const { return animals;};
	
};
#endif

