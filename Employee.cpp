#include "Employee.h"

Employee::Employee() :Person()
{
	m_post = "";
	m_salary = 0.0;
}

Employee::Employee(string name, int age, string post, double salary) :Person(name, age)
{
	m_post = post;
	m_salary = salary;
}

Employee::Employee(const Employee& e)
{
	m_name = e.m_name;
	m_age = e.m_age;
	m_post = e.m_post;
	m_salary = e.m_salary;
}

Employee::~Employee()
{
}

void Employee::show()
{
	cout << "\nName: " << m_name;
	cout << "\nAge: " << m_age;
	cout << "\nPost: " << m_post;
	cout << "\nSalary: " << m_salary << endl;
}

string Employee::get_post()
{
	return m_post;
}

double Employee::get_salary()
{
	return m_salary;
}

double Employee::get_final_salary(double percent)
{
	return m_salary + (m_salary * percent / 100);
}

void Employee::set_post(string post)
{
	m_post = post;
}

void Employee::set_salary(double salary)
{
	m_salary = salary;
}

istream& operator>>(istream& in, Employee& e)
{
	cout << "Enter name: ";
	in >> e.m_name;
	cout << "\nEnter age: ";
	in >> e.m_age;
	cout << "\nEnter post: ";
	in >> e.m_post;
	cout << "\nEnter salary: ";
	in >> e.m_salary;
	cout << endl;
	return in;
}

ostream& operator<<(ostream& out, Employee& e)
{
	out << "\nName: " << e.m_name;
	out << "\nAge: " << e.m_age;
	out << "\nPost: " << e.m_post;
	out << "\nSalary: " << e.m_salary << endl;
	return out;
}
