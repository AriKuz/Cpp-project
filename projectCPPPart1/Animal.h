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
	char* name;
	float height;
	float weight;
	Animal(int sn,const char* nme,float height1, float weight1) {
		serialNumber = sn;
		name = new char[strlen(nme)+1];
		strcpy(name, nme);
		height = height1;
		weight = weight1;
		
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
	float getHeigt() const { return height; }
	float getWeight() const { return weight; }
	
	

};

#endif 