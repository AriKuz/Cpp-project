#pragma warning(disable: 4996)
#ifndef __ANIMAL_H
#define __ANIMAL_H

#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;


class Animal
{
protected:
	int serialNumber;
	int type; // Bat: 0, Bird: 1, Crocodile : 2, Lion: 3, Ostrich: 4, Parrot: 5.
	char* name;
	float height;
	float weight;

	Animal(int sn,const char* nme,float height1, float weight1, int type)
	{
		serialNumber = sn;
		name = new char[strlen(nme)+1];
		strcpy(name, nme);
		height = height1;
		weight = weight1;
		this->type = type;
	}

	virtual ~Animal()
	{
		delete []name;
	}
	
public:
	friend ostream& operator<< (ostream & o, const Animal & a);
	virtual void eat()  = 0;
	virtual void makeSound() const = 0;
	void setHeight(float h);
	void setWeight(float w);
	float getHeight() const { return height; }
	float getWeight() const { return weight; }
	int getSerialNumber() const { return serialNumber; }
	int getType() const { return type; }
	char* getName() const { return name; }
};

#endif 