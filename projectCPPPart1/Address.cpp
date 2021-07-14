#include <string.h>
#include "Address.h"

Address::Address(const string& street, int number, const string& city){
    setStreet(street);
    setCity(city);
    this->number = number;

}


ostream& operator<<(ostream& os, const Address& add)
{
    cout << "Street: " << add.street << " Number: " << add.number<< "City: " << add.city << endl;
    return os;
}

void Address::setStreet(const string& street)
{
    this->street = street;
}
string& Address::getStreet()
{
    return street;
}
void Address::setCity(const string& city)
{
    this->city = city;
}
string& Address::getCity()
{
    return city;
}