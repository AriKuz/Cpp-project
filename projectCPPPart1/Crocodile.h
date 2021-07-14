#ifndef __CROCODILE_H
#define __CROCODILE_H
#include "Reptile.h"
#include "CanSwim.h"

#define CROCODILE_TYPE 2

class Crocodile : public Reptile , public CanSwim
{
public:
	Crocodile(int sn, const char* nme, float h, float w) :Reptile(sn, nme, h, w, CROCODILE_TYPE), CanSwim(20) {}
	Crocodile(const Crocodile &other);
	Crocodile(Crocodile &&other);
	~Crocodile();
	friend ostream& operator<< (ostream& o, const Crocodile& a);
	const Crocodile& operator++();
	void swim() const override;
	void makeSound() const override;
	void eat() override;
	
};
#endif
