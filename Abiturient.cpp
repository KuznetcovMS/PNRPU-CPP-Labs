#include "Abiturient.h"
#include <iostream>
#include <string>
using namespace std;

Abiturient::Abiturient()
{
	m_fio = "";
	m_specialty = "";
	m_ege = 0;
	cout << "Constructor without parametrs for object: " << this << endl;
}

Abiturient::Abiturient(string fio, string spec, int ege)
{
	m_fio = fio;
	m_specialty = spec;
	m_ege = ege;
	cout << "Constructor with parametrs for object: " << this << endl;
}

Abiturient::Abiturient(const Abiturient &a)
{
	m_fio = a.m_fio;
	m_specialty = a.m_specialty;
	m_ege = a.m_ege;
	cout << "Copy Constructor for object: " << this << endl;
}

Abiturient::~Abiturient()
{
	cout << "Distructor for object: " << this << endl;
}

string Abiturient::get_fio()
{
	return m_fio;
}

void Abiturient::set_fio(string fio)
{
	m_fio = fio;
}

string Abiturient::get_speciality()
{
	return m_specialty;
}

void Abiturient::set_speciality(string speciality)
{
	m_specialty = speciality;
}

int Abiturient::get_ege()
{
	return m_ege;
}

void Abiturient::set_ege(int ege)
{
	m_ege = ege;
}

void Abiturient::show()
{
	cout << "\nAbiturients FIO: " << m_fio << endl;
	cout << "Abiturients speciality: " << m_specialty << endl;
	cout << "Abiturients exam score: " << m_ege << endl << endl << endl;
}

