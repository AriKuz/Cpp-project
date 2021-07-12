#pragma warning(disable: 4996)
#ifndef __BIRD_H
#define __BIRD_H
#include "Animal.h"
#include <stdio.h>
#include <string.h>
class Bird : public Animal
{
private:
	char* colorOfFeathers;
	float sizeOfBeak;

public:
	Bird(int sn, const char* nme, float h, float w,const char* cof, float sob, int type) : Animal(sn, nme, h, w, type)
	{
        sizeOfBeak = sob;
		colorOfFeathers = new char[strlen(cof) + 1];
		strcpy(colorOfFeathers, cof);
	}
    Bird(int sn, const char *nme, float height1, float weight1, const Bird &other, int type);
    Bird(int sn, const char *nme, float height1, float weight1, Bird &&other, int type);
	~Bird();
    friend ostream& operator<< (ostream& o, const Bird& a);
	char* getColorOfFeathers() const { return colorOfFeathers; }
	float getSizeOfBeak() const { return sizeOfBeak; }


};
#endif

