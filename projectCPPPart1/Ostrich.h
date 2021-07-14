#ifndef __OSTRICH_H
#define __OSTRICH_H
#include <ostream>
#include "Bird.h"
#include <string>

#define OSTRICH_TYPE 4

class Ostrich: public Bird
{

public:
	Ostrich(int sn, const string& nme, float h, float w, const string& color) : Bird(sn, nme, h, w, color, 9, OSTRICH_TYPE) {}
	Ostrich(const Ostrich &other);
	Ostrich(Ostrich &&other);
	void eat() override;
	void makeSound() const override;

	friend ostream& operator<< (ostream& o, const Ostrich& a);
	const Ostrich& operator++();
};
#endif

