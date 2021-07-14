#pragma warning(disable: 4996)
#ifndef __ZOO_H
#define __ZOO_H
#include "Animal.h"
#include "Employee.h"
#include "Cage.h"
#include "Address.h"

const int LION = 0;
const int CROCODILE = 1;
const int BAT= 2;
const int OSTRICH = 3;
const int PARROT = 4;

class Zoo
{
private:
	char* name;
	Cage** cages;
	Employee** employees;
	Address* address;
	int cagesCount ;
	int maxCagesCount;
	int animalsCount;
	int employeesCount;
	int maxEmployees;
public:

	Zoo(const char* name, int numOfCages, Address& add, int maxEmployees);
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
	Cage& operator[](int index) { return *cages[index]; }
	Address& getAddress(){return *address; }
};

#endif 