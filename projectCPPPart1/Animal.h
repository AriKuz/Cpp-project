#pragma warning(disable: 4996)
#ifndef __ANIMAL_H
#define __ANIMAL_H

#include <stdio.h>
#include<string>
#include <string.h>
#include <iostream>
using namespace std;


class Animal
{
protected:
	int serialNumber;
	int type; // Bat: 0, Bird: 1, Crocodile : 2, Lion: 3, Ostrich: 4, Parrot: 5.
	string name;
	float height;
	float weight;

	Animal(int sn, const string& nme, float height1, float weight1, int type);

	virtual ~Animal();
	
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
	const string& getName() const { return name; }
};

#endif 