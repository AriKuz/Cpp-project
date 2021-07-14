#ifndef __REPTILE_H
#define __REPTILE_H
#include "Animal.h"
#include <string>
class Reptile :public Animal
{
private:
	float temp =0;
public:
	Reptile(int sn, const string& nme, float h, float w, int type) : Animal(sn, nme, h, w, type) {}
	/*~Reptile();*/
	void setTemp(float tem) { temp = tem; }
	float getTemp() const { return temp; }
};
#endif
