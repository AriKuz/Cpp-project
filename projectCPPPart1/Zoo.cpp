#include "Zoo.h"

Zoo::Zoo(const char* nme, Address& add) : address(add)
{
	name = new char[strlen(nme) + 1];
	strcpy(name, nme);
}

Zoo::Zoo(Zoo& other) : address(other.getAddress())
{
	name = new char[strlen(other.name) + 1];
	name = other.name;
	cages = other.cages;
	employees = other.employees;
}

Zoo::Zoo(Zoo&& other) : address(other.address)
{
	name = other.name;
	other.name = nullptr;
	cages = other.cages;
	delete &other.cages;
	employees = other.employees;
	delete &other.employees;
}

Zoo::~Zoo()
{
	delete[] name;
}

void Zoo::addAnimal(Animal* animal) 
{
	// TODO: handle cages addition (if no appropriate cage, add it)
	addCage(animal->getType());
	cout << "cage was added";

	for (auto it = cages.begin(); it != cages.end(); ++it)
	{
    	if ((*it)->getType() == animal->getType())
		{
			(*it)->addAnimal(animal);
			cout << "Animal was added successfully!!" << endl;
			return;
		}
	}
	throw "There is no cage for that type.";
}

void Zoo::removeAnimal(int serialNumber)
{
	auto itr_cages = cages.begin();
	auto itr_end = cages.end();
	for (; itr_cages != itr_end; ++itr_cages)
		(*itr_cages)->removeAnimal(serialNumber);
}

void Zoo::addEmployee(Employee* employee) 
{
	employees.push_back(new Employee(*employee));
}

void Zoo::removeEmployee(int employeeNumber) 
{
	for (auto it = employees.begin(); it != employees.end(); ++it)
		if ((*it)->getEmployeeNumber() == employeeNumber)
		{
			employees.erase(it);
			return;
		}
}

void Zoo::show()  
{
	cout << "Zoo " << name << " in " << address << endl;
	showAllAnimals();
	showAllEmployees();
}

void Zoo::addCage(int type) 
{
	cages.push_back(new Cage(type));
	// if (cagesCount < maxCagesCount)
	// 	cages[cagesCount++] = new Cage(type);
	// else
	// 	throw "There is maximum cages in the zoo.";
}

void Zoo::showAllAnimals() const 
{
	cout << "Animals :\n";
	int counter = 0;
	for (auto it = cages.begin(); it != cages.end(); ++it, counter++)
		cout << "Cage number " << counter << ", animals:\n" << **it;
}

void Zoo::showAllEmployees() const 
{
	cout << "\nEmployees :\n";
	int counter = 0;
	for (auto it = employees.begin(); it != employees.end(); ++it, counter++)
		cout << **it << endl;
}

void Zoo::feedAllAnimals()
{
	for (auto it = cages.begin(); it != cages.end(); ++it)
		(*it)->feedAllAnimalsInCage();
}