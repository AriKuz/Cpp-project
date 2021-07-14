#ifndef __MAMMAL_H
#define __MAMMAL_H
#include "Animal.h"
class Mammal :public Animal
{
protected:
	
	int numberOfLegs=0;
	Mammal(int sn, const char* nm ,float h , float w ,int nol, int type) : Animal(sn, nm, h,w, type) {
		numberOfLegs = nol;
	}

public:
	


};

#endif 