#include "Person.h"

Person::Person()
{
	m_name = "";
	m_age = 0;
}

Person::Person(string name, int age)
{
	m_name = name;
	m_age = age;
}

Person::Person(const Person& p)
{
	m_name = p.m_name;
	m_age = p.m_age;
}

Person::~Person()
{
}

int Person::value()
{
	return m_age;
}

void Person::show()
{
	cout << "\nName: " << m_name;
	cout << "\nAge: " << m_age << endl;

}

void Person::input()
{
	cout << "Enter name: ";
	cin >> m_name;
	cout << "\nEnter age: ";
	cin >> m_age;
	cout << endl;
}

string Person::get_name()
{
	return m_name;
}

int Person::get_age()
{
	return m_age;
}

void Person::set_name(string name)
{
	m_name = name;
}

void Person::set_age(int age)
{
	m_age = age;
}

Person& Person::operator=(const Person& p)
{
	if (&p == this) return *this;
	m_name = p.m_name;
	m_age = p.m_age;
	return *this;
}

istream& operator>>(istream& in, Person& p)
{
	cout << "Enter name: ";
	in >> p.m_name;
	cout << "\nEnter age: ";
	in >> p.m_age;
	cout << endl;
	return in;
}

ostream& operator<<(ostream& out, Person& p)
{
	out << "\nName: " << p.m_name;
	out << "\nAge: " << p.m_age << endl;
	return out;
}
