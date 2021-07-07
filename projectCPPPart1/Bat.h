#ifndef __BAT_H
#define __BAT_H
#include "Mammal.h"
#include "Canfly.h"

class Bat : public Mammal , public Canfly
{
public:
	
	Bat(int sn, const char* nm, float h, float w) : Mammal(sn, nm, h, w, 2), Canfly(10){}
	Bat(Bat&& other);
	Bat(const Bat& other);
	~Bat();
	friend ostream& operator<< (ostream& o, const Bat& a);
	void fly() const;
	const Bat& operator++();
	void eat();
	void makeSound() const;

};

#endif 