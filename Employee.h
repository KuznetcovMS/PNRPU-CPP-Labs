#pragma once
#include "Person.h"

class Employee : public Person
{
protected:
	string m_post;
	double m_salary;
public:
	Employee();
	Employee(string name, int age, string post, double salary);
	Employee(const Employee& e);
	~Employee();

	void show();
	string get_post();
	double get_salary();
	double get_final_salary(double percent);

	void set_post(string post);
	void set_salary(double salary);

	friend istream& operator>>(istream& in, Employee& e);
	friend ostream& operator<<(ostream& out, Employee& e);
};

