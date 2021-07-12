#ifndef __CROCODILE_H
#define __CROCODILE_H
#include "Reptile.h"
#include "CanSwin.h"
class Crocodile : public Reptile , public CanSwin
{
public:
	Crocodile(int sn, const char* nme, float h, float w) :Reptile(sn, nme, h, w), CanSwin(20) {}
	Crocodile(int sn, const char *nme, float h, float w, int sps, const Crocodile &other);
	Crocodile(int sn, const char *nme, float h, float w, int sps, Crocodile &&other);
	~Crocodile();
	friend ostream& operator<< (ostream& o, const Crocodile& a);
	const Crocodile& operator++();
	void swim() const override;
	void makeSound() const override;
	void eat() override;
	
};
#endif
