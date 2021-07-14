#ifndef __CROCODILE_H
#define __CROCODILE_H
#include "Reptile.h"
#include "CanSwin.h"
#include <string>

#define CROCODILE_TYPE 2

class Crocodile : public Reptile , public CanSwin
{
public:
	Crocodile(int sn, const string& nme, float h, float w) :Reptile(sn, nme, h, w, CROCODILE_TYPE), CanSwin(20) {}
	Crocodile(const Crocodile &other);
	Crocodile(Crocodile&& other);
	friend ostream& operator<< (ostream& o, const Crocodile& a);
	const Crocodile& operator++();
	void swim() const override;
	void makeSound() const override;
	void eat() override;
	
};
#endif
