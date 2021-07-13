#ifndef __PARROT_H
#define __PARROT_H
#include "Bird.h"
#include "Canfly.h"
#include <string>
#define PARROT_TYPE 5

class Parrot : public Bird , public Canfly
{

public:
	Parrot(int sn, const string& nme, float h, float w, const string& coth, float sob, int spOf);
	/*Parrot(const Parrot& other);
	Parrot(Parrot&& other);
	~Parrot();*/
    void eat() override;
	void makeSound() const override ;
	void fly() const override;
	const Parrot& operator++();
};

#endif
