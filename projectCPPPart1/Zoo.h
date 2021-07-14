#pragma warning(disable: 4996)
#ifndef __ZOO_H
#define __ZOO_H
#include <vector>
#include "Animal.h"
#include "Employee.h"
#include "Cage.h"
#include "Address.h"
#include "MyTemplate.h"
#include <string>
const int LION = 0;
const int CROCODILE = 1;
const int BAT= 2;
const int OSTRICH = 3;
const int PARROT = 4;

class Zoo
{
private:
	//TODO : add a limit for cages and for employees and for animals vector in Cage.h
	string name;
	vector<Cage*> cages;
	vector<Employee*> employees;
    CustomLinkedList<Employee*> employees2;
	Address address;
	static Zoo* theZoo;
	Zoo(const string& name, Address& add);
	
public:
	static Zoo* getInstance(const string& name, Address& add); 
	Zoo(Zoo& other): address(other.address) {};
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