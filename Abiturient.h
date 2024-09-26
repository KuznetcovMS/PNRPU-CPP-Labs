#pragma once
#include <iostream>
#include <string>
using namespace std;

class Abiturient
{
	string m_fio;
	string m_specialty;
	int m_ege;

public:
	Abiturient();
	Abiturient(string, string, int);
	Abiturient(const Abiturient&);
	~Abiturient();
	string get_fio();
	void set_fio(string);
	string get_speciality();
	void set_speciality(string);
	int get_ege();
	void set_ege(int);
	void show();
};

