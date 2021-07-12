#include <string.h>
#include "Address.h"

Address::Address(const char* street, int number, const char* city) : street(nullptr), number(number), city(nullptr)
{
    setStreet(street);    
    setCity(city);    
}

Address::Address(Address& otheradress): street(nullptr), city(nullptr)
{
    if (this != &otheradress)
    {
        setStreet(otheradress.street);
        setCity(otheradress.city);
        this->number = otheradress.number;
    }
}

Address::Address(Address&& other)
{
    std::swap(street, other.street);
    std::swap(city, other.city);
}

Address::~Address()
{
    delete[]this->street;
    delete[]this->city;
}

ostream& operator<<(ostream& os, const Address& add)
{
    cout << "Street: " << add.street << " Number: " << add.number<< "City: " << add.city << endl;
    return os;
}

void Address::setStreet(const char* street)
{
    delete[]this->street;
    this->street = new char[strlen(street)+1];
    strcpy(this->street, street);
}
char* Address::getStreet()
{
    return street;
}
void Address::setCity(const char* city)
{
    delete[]this->city;
    this->city = new char[strlen(city)+1];
    strcpy(this->city, city);
}
char* Address::getCity()
{
    return city;
}