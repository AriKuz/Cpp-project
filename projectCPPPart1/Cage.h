#ifndef __CAGE_H
#define __CAGE_H
#include <vector>
#include "Animal.h"
class Cage
{

private:
	vector<Animal*> animals;
	int maxAnimals;
	int cageType;

public:
	Cage(int type);
	Cage(const Cage& other);
	Cage(Cage&& other);
	~Cage();
	friend ostream& operator<< (ostream& o, const Cage& a);
	void addAnimal(Animal* animal);
	void removeAnimal(int sn);
	Cage* operator+=(const Cage& other);
	Cage* operator+=(Animal* other);
	int getType() const { return cageType;};
	vector<Animal*> getAnimals() const { return animals;};
	void feedAllAnimalsInCage();
};
#endif