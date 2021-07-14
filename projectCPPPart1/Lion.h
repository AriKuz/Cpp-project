
#ifndef __LION_H
#define __LION_H

#include "Mammal.h"
#include <stdio.h>

#define LION_TYPE 3

class Lion :public Mammal
{
	public:
        Lion(int s, const char* name, float h, float w) : Mammal(s, name, h, w, 4, LION_TYPE){
            cout << "in Lion:Lion" << endl;
        }
        Lion(const Lion &other);
        Lion(Lion&& other);
        ~Lion();
        void makeSound() const ;
        void eat();
        const Lion& operator++();
        friend ostream& operator<< (ostream& o, const Lion& a);
};

#endif 