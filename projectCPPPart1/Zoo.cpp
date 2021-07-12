#include "Zoo.h"

Zoo::Zoo(const char* nme, int numOfCages, Address& add, int maximumEmployees) : address(add)
{
	name = new char[strlen(nme) + 1];
	strcpy(name, nme);
	maxCagesCount = numOfCages;
	cages = new Cage*[maxCagesCount];
	maxEmployees = maximumEmployees;
	employees = new Employee*[maximumEmployees];
}

Zoo::Zoo(Zoo& other) : address(other.getAddress())
{
	name = new char[strlen(other.name) + 1];
	name = other.name;
	cages = new Cage*[sizeof(other.cages)];
	cages = other.cages;
	employees = new Employee*[sizeof(other.employees)];
	employees = other.employees;
	cagesCount = other.cagesCount;
	maxCagesCount = other.maxCagesCount;
	animalsCount = other.animalsCount;
	employeesCount = other.employeesCount;
	maxEmployees = other.maxEmployees;
}

Zoo::Zoo(Zoo&& other) : address(other.address)
{
	name = other.name;
	other.name = nullptr;
	cages = other.cages;
	other.cages = nullptr;
	employees = other.employees;
	other.employees = nullptr;
	// address = other.address;
	// other.address = nullptr;
	cagesCount = other.cagesCount;
	maxCagesCount = other.maxCagesCount;
	animalsCount = other.animalsCount;
	employeesCount = other.employeesCount;
	maxEmployees = other.maxEmployees;
}

Zoo::~Zoo()
{
	delete[] name;
	delete[] cages;
	// delete address;
	delete[] employees;
}

void Zoo::addAnimal(Animal& animal) 
{
	if (cagesCount == 0)
	{
		throw "There is no cages in the zoo, Please add one.";
	}
	bool succes = false;
	for (int i = 0; i < cagesCount; i++)
	{
		if ((*this)[i].getType() == animal.getType())
		{
			(*this)[i].addAnimal(animal);
			return;
		}
	}
	throw "There is no cage for that type.";
}
void Zoo::removeAnimal(int serialNumber) {
	for (int i = 0; i < cagesCount; i++) 
	{
		for (int j = 0;j < (*this)[i].getAnimalsCount();j++) 
		{
			if ((*this)[i].getAnimals()[j]->getSerialNumber() == serialNumber) 
			{
				(*this)[i].removeAnimal(serialNumber);
				return;
			}
		}
	}
    cout << "Serial number was not belong to any animal!!!" << endl;
}
void Zoo::addEmployee(Employee& employee) 
{
	if (employeesCount < maxEmployees)
	{
		employees[employeesCount++] = new Employee(employee);
	}
	else
	{
		throw "There is not enough room for new employee";
	}
}
void Zoo::removeEmployee(int employeeNumber) 
{
	for (int i = 0; i < employeesCount; i++)
	{
		if (employees[i]->getEmployeeNumber() == employeeNumber)
		{
			Employee** newArray = new Employee*[maxEmployees];
			std::copy(employees, employees + i, newArray);
			std::copy(employees + i + 1, employees + employeesCount, newArray + i);
			delete[] employees;
			employees = newArray;
			--employeesCount;
			return;
		}
	}
	throw "There is no employee with this number";
}
void Zoo::show()  
{
	cout << "Zoo " << name << " in " << address << endl;
	(*this).showAllAnimals();
	(*this).showAllEmployees();
}
void Zoo::addCage(int type) 
{
	if (cagesCount < maxCagesCount)
	{
		cages[cagesCount++] = new Cage(type);
	}
	else
	{
		throw "There is maximum cages in the zoo.";
	}
}
void Zoo::showAllAnimals() const{
	for (int i = 0; i < cagesCount; i++)
	{
		cout << "Cage number " << i << " animals :\n" << cages[i];
	}
}
void Zoo::showAllEmployees() const {
	cout << "Employees :\n";
	for (int i = 0; i < employeesCount; i++)
	{
		cout << *employees[i] << endl;
	}
	
}
void Zoo::feedAllAnimals() {
    for (int i = 0; i < cagesCount; i++) 
	{
		for (int j = 0;j < (*this)[i].getAnimalsCount();j++) 
		{
			(*this)[i].getAnimals()[j]->eat();
		}
	}
}