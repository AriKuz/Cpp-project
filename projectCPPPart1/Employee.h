#pragma warning(disable: 4996)
#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;


class Employee
{
private:
	int employeeNumber;
	string name;
	string role;

public:
	Employee(int en, string& nme, string& rol) 
	{
		this->employeeNumber = en;
		this->name = nme;
		this->role = rol;
	}

	friend ostream& operator<< (ostream& o, const Employee& a)
	{
		cout << "Employee num#" << a.employeeNumber << ", name: " << a.name << ", role:" << a.role << endl;
		return o; 
	}
	int getEmployeeNumber() { return this->employeeNumber;}
};

#endif 
