#include "Zoo.h"

Zoo::Zoo(const char* nme, int numOfCages, Address& add, int maximumEmployees) : address(&add)
{
	name = new char[strlen(nme) + 1];
	strcpy(name, nme);
	maxCagesCount = numOfCages;
	cages = new Cage*[maxCagesCount];
	maxEmployees = maximumEmployees;
	employees = new Employee*[maximumEmployees];
	employeesCount = 0;
}

Zoo::Zoo(Zoo& other) : address(other.address)
{
	name = strdup(other.name);
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
	delete address;
	delete[] employees;
}

void Zoo::addAnimal(Animal* animal) 
{
	if (cagesCount == 0)
	{
		//added first cage in zoo 
		addCage(animal->getType());
	}
	bool succes = false;
	for (int i = 0; i < cagesCount; i++)
	{
		if (cages[i]->getType() == animal->getType() && cages[i]->getAnimalsCount() < 5)
		{
			//added animal to exsisted cage
			cages[i]->addAnimal(animal);
			cout << "Animal was added successfully!!" << endl;
			return;
		}
	}
	//create cage and added animal to this new cage 
	addCage(animal->getType());
	cages[cagesCount]->addAnimal(animal);
	cout << "Cage for this animal created and Animal was added successfully!!" << endl;
}


void Zoo::removeAnimal(int serialNumber) {
	for (int i = 0; i < cagesCount; i++) 
	{
		for (int j = 0; j < cages[i]->getAnimalsCount();j++) 
		{
			Animal** a = cages[i]->getAnimals();
			cout << "Animals: " << *a << endl;
			cout << a[j] << endl;
			if (cages[i]->getAnimals()[j]->getSerialNumber() == serialNumber) 
			{
				cages[i]->removeAnimal(serialNumber);
				return;
			}
		}
	}
    cout << "Serial number was not belong to any animal!!!" << endl;
}

void Zoo::addEmployee(Employee* employee) 
{
	if (employeesCount < maxEmployees)
		employees[employeesCount++] = new Employee(*employee);
	else
	{
		cout << "Ohh too much employeess, cant added new one:(" << endl;
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
cout << "Cant remove employee, didnt find this employee number: " << employeeNumber << endl;
}    


void Zoo::show()  
{
	cout << "Zoo " << name << endl;
	cout << "located at: " << address << endl;
	showAllAnimals();
	showAllEmployees();
}

void Zoo::addCage(int type) 
{
	if(this->cagesCount < this->maxCagesCount){
		cout<<"No more available cages sorry :(";
		return;
	}
	for(int i =0 ; i < cagesCount ; i++){
		if(cages[i]->getType() == type){
			if(cages[i]->getAnimalsCount()>5){
				cages[cagesCount++] = new Cage(type);
			}
			cout<< "Cage not created. There is a cage with less than 5 animals in with this type.";
			return;
		}
	}
	cages[cagesCount++] = new Cage(type);
}

void Zoo::showAllAnimals() const {
	cout << "Animals :\n";
	for (int i = 0; i < cagesCount; i++)
		cout << *(cages[i])  << endl;
}

void Zoo::showAllEmployees() const {
	cout << "\nEmployees :\n";
	for (int i = 0; i < employeesCount; i++)
		cout << *employees[i] << endl;
}

void Zoo::feedAllAnimals() {
    for (int i = 0; i < cagesCount; i++) 
		for (int j = 0;j < (*this)[i].getAnimalsCount();j++) 
			cages[i]->getAnimals()[j]->eat();
}