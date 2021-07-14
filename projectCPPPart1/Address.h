#ifndef __ADDRESS_H
#define __ADDRESS_H
#include <iostream>
#include <string>
using namespace std;
class Address
{
protected:
	string street;
	int number;
	string city;
public:
	Address(const string& street, int number, const string& city);
	void setStreet(const string& street);
	string& getStreet();
	void setCity(const string& city);
	string& getCity();
	void setNumber(const int num){ number = num;};
	int getNumber(){ return this->number; }
	friend ostream& operator<<(ostream& os, const Address& add);	
};
#endif
