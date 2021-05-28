#include "Abiturient.h"

Abiturient::Abiturient():Person()
{
	m_ball = 0;
	m_spec = "";
}

Abiturient::Abiturient(const Abiturient& a)
{
	m_name = a.m_name;
	m_age = a.m_age;
	m_ball = a.m_ball;
	m_spec = a.m_spec;
}

Abiturient::Abiturient(string name, int age, int ball, string spec):Person(name, age)
{
	m_ball = ball;
	m_spec = spec;
}

Abiturient::~Abiturient()
{
}

void Abiturient::set_ball(int ball)
{
	m_ball = ball;
}

void Abiturient::set_spec(string spec)
{
	m_spec = spec;
}

int Abiturient::get_ball()
{
	return m_ball;
}

string Abiturient::get_spec()
{
	return m_spec;
}

int Abiturient::value()
{
	return m_age;
}

void Abiturient::show()
{
	cout << "\nName: " << m_name;
	cout << "\nAge: " << m_age;
	cout << "\nBall: " << m_ball;
	cout << "\nSpecialization: " << m_spec << endl;
}

void Abiturient::input()
{
	cout << "Enter name: ";
	cin >> m_name;
	cout << "\nEnter age: ";
	cin >> m_age;
	cout << "Enter ball: ";
	cin >> m_ball;
	cout << "\nEnter spec: ";
	cin >> m_spec;
	cout << endl;
}

Abiturient& Abiturient::operator=(const Abiturient& a)
{
	if (&a == this) return *this;
	m_name = a.m_name;
	m_age = a.m_age;
	m_ball = a.m_ball;
	m_spec = a.m_spec;
	return *this;
}
