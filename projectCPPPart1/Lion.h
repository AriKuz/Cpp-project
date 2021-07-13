
#ifndef __LION_H
#define __LION_H

#include "Mammal.h"
#include <stdio.h>
#include <string>

#define LION_TYPE 3

class Lion :public Mammal
{
	public:
        Lion(int s, const string& name, float h, float w) : Mammal(s, name, h, w, 4, LION_TYPE){}
        /*
        Lion::Lion(const Lion& other) : Mammal(other.serialNumber, other.name, other.height, other.weight, other.numberOfLegs, other.type) {};
        Lion::Lion(Lion&& other) : Mammal(other.serialNumber, other.name, other.height, other.weight, other.numberOfLegs, other.type){}
        
        ~Lion();
        
        */
        void makeSound() const ;
        void eat();
        const Lion& operator++();
        friend ostream& operator<< (ostream& o, const Lion& a);
};

#endif 