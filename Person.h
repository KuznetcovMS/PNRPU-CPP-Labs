#pragma once
#include <iostream>
#include <string>
#include "Object.h"
using namespace std;

class Person : public Object
{
protected:
	string m_name;
	int m_age;
public:
	Person();
	Person(string name, int age);
	Person(const Person& p);
	virtual ~Person();

	void show();
	string get_name();
	int get_age();

	void set_name(string name);
	void set_age(int age);

	Person& operator=(const Person& p);

	friend istream& operator>>(istream& in, Person& p);
	friend ostream& operator<<(ostream& out, Person& p);
};
