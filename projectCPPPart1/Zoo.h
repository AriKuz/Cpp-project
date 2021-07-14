#pragma warning(disable: 4996)
#ifndef __ZOO_H
#define __ZOO_H
#include <vector>
#include "Animal.h"
#include "Employee.h"
#include "Cage.h"
#include "Address.h"
#include <string>
const int LION = 0;
const int CROCODILE = 1;
const int BAT= 2;
const int OSTRICH = 3;
const int PARROT = 4;

class Zoo
{
private:
	string name;
	vector<Cage*> cages;
	vector<Employee*> employees;
	Address address;
public:

	Zoo(const string& name, Address& add);
	Zoo(Zoo& other);
	Zoo(Zoo&& other);
	~Zoo();
	void addAnimal(Animal* animal);
	void removeAnimal(int serialNumber);
	void addEmployee(Employee* employee);
	void removeEmployee(int employeeNumber);
	void show();
	void addCage(int type);
	void showAllAnimals()const;
	void showAllEmployees()const;
	void feedAllAnimals();
	Cage& operator[](int index) { return *cages.at(index); }
	Address& getAddress(){return address; }
};

#endif 