#include "Bird.h"

ostream& operator<<(ostream& o, const Bird& a)
{
    o << (Animal&)a << "\nserial number: " << a.serialNumber
      << "\nname: " << a.name
      << "\nheight: " << a.height
      << "\nweight: " << a.weight
      << "\ncolor of feathers: " << a.getColorOfFeathers()
      << "\nsize of beak: " << a.getSizeOfBeak();
    return o;
}