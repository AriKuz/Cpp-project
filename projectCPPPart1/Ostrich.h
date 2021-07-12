#ifndef __OSTRICH_H
#define __OSTRICH_H
#include <ostream>
#include "Bird.h"


class Ostrich: public Bird
{

public:
	Ostrich(int sn, const char* nme, float h, float w, const char* color) : Bird(sn, nme, h, w, color, 9) {}
	Ostrich(int sn, const char *nme, float h, float w, const char *cof, float sob, const Ostrich &other);
	Ostrich(int sn, const char *nme, float h, float w, const char *cof, float sob, Ostrich &&other);
	~Ostrich();

	void eat() override;
	void makeSound() const override;

	friend ostream& operator<< (ostream& o, const Ostrich& a);
	const Ostrich& operator++();

};
#endif

