#ifndef __BAT_H
#define __BAT_H
#include "Mammal.h"
#include "Canfly.h"

#define BAT_TYPE 0

class Bat : public Mammal , public Canfly
{
public:
	
	Bat(int sn, const char* nm, float h, float w) : Mammal(sn, nm, h, w, 2, BAT_TYPE), Canfly(10){}
	Bat(const Bat& other);
	Bat(Bat&& other);
	~Bat();
	friend ostream& operator<< (ostream& o, const Bat& a);
	void fly() const;
	const Bat& operator++();
	void eat();
	void makeSound() const;
};

#endif 