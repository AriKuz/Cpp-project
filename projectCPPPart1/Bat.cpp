#include "Bat.h"

// TODO: do we need the c'tors?
Bat::Bat(const Bat& other) : Mammal(other.serialNumber, other.name, other.height, other.weight, 2, other.type), Canfly(10){}
Bat::Bat(Bat&& other) : Mammal(other.serialNumber, other.name, other.height, other.weight, other.numberOfLegs, other.type), Canfly(other.speedOfFlight){}

ostream& operator<< (ostream& o, const Bat& a)
{
    cout << "Bat's serial num is #" << a.serialNumber << ", Bat's name is " << a.name << ", Bat's height is " << a.height << ",  Bat's weight is " << a.weight << "Bat's number of legs is " << a.numberOfLegs << ", Bat's speed of flight is " << a.speedOfFlight << endl;
    return o;
}
void Bat::fly() const
{
    cout << "Bat is flying with a speed of " << speedOfFlight << endl;
}
const Bat& Bat::operator++()
{
    speedOfFlight++;
    return *this;
}
void Bat::eat()
{
    cout << "Bat is eating" << endl;
}
void Bat::makeSound() const
{
    cout << "Yeee I am bat" << endl;
}