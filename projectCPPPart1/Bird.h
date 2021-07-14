#pragma warning(disable: 4996)
#ifndef __BIRD_H
#define __BIRD_H
#include "Animal.h"
#include <stdio.h>
#include <string.h>
#include <string>
class Bird : public Animal
{
protected:
	string colorOfFeathers;
	float sizeOfBeak;

public:
	Bird(int sn, const string& nme, float h, float w,const string& cof, float sob, int type) : Animal(sn, nme, h, w, type)
	{
		this->colorOfFeathers = cof;
        this->sizeOfBeak = sob;
	}
	Bird(const Bird& other) : Animal(other.serialNumber, other.name, other.height, other.weight, other.type) {}
	Bird(Bird&& other) : Animal(other.serialNumber, other.name, other.height, other.weight, other.type) {}
	friend ostream& operator<< (ostream& o, const Bird& a);
	const string& getColorOfFeathers() const { return colorOfFeathers; }
	float getSizeOfBeak() const { return sizeOfBeak; }


};
#endif

