#ifndef __CAGE_H
#define __CAGE_H
#include <vector>
#include "Animal.h"

class Cage
{

/*	
	Cage Mediator

	This class contains all the animals vector, which are controlled by the Cage rules.

	It implements the Mediator design pattern, as a client (or user) doesn't have to deal with
	controlling the animals.
	
	E.g. feedAllAnimalsInCage: Zoo contains a cages vector, but if we would like to feed all Zoo 
	animals, we won't have to enter each cage and feed the animals one by one (we won't have to iterate
	over the animals in each cage).
	We could just iterate over the cages vector and call the feedAllAnimalsInCage method,
	as each Cage is being used as a mediator.
*/

private:
	vector<Animal*> animals;
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
	vector<Animal*> getAnimals() const { return animals;};
	void feedAllAnimalsInCage();
};
#endif