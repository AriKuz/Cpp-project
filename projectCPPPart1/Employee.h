#pragma warning(disable: 4996)
#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;


class Employee
{
private:
	int employeeNumber;
	char* name;
	char* role;

public:
	Employee(int en, char* nme, char* rol) {
		cout << "test1";
		employeeNumber = en;
		name = new char[strlen(nme) + 1];
		strcpy(name, nme);
		cout << "test2";
		role = new char[strlen(rol) + 1];
		strcpy(role, rol);
		cout << "test3";
	}

	~Employee();

	friend ostream& operator<< (ostream& o, const Employee& a)
	{
		cout << "Employee num#" << a.employeeNumber << ", name: " << a.name << ", role:" << a.role << endl;
		return o; 
	}
	int getEmployeeNumber() { return this->employeeNumber;}
    char* getEmployeeName() { return this->name;}
    char* getEmployeeRole() { return this->role;}
};



#endif 
