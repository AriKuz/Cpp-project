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
	Employee(int en, char* nme, char* rol);
	~Employee();
	friend ostream& operator<< (ostream& o, const Employee& a);
	int getEmployeeNumber() { return this->employeeNumber;}
};

#endif 
