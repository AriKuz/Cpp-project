#ifndef __ADDRESS_H
#define __ADDRESS_H
#include <iostream>
using namespace std;
class Address
{
protected:
	char* street;
	int number;
	char* city;
public:
	Address(const char* street, int number, const char* city);
	Address(Address& otheradress);
	Address(Address&& other);
	~Address();
	void setStreet(const char* street);
	char* getStreet();
	void setCity(const char* city);
	char* getCity();
	void setNumber(const int num){ number = num;};
	int getNumber(){ return this->number; }
	friend ostream& operator<<(ostream& os, const Address& add);	
};
#endif
