#pragma once
#include <iostream>
#include <string>
#include "Object.h"
using namespace std;

class Vector
{
public:
	Vector();
	Vector(int);
	~Vector();
	void Add();
	void Del();
	void Show();
	void Avg();
	int operator() ();
	friend ostream& operator<<(ostream& out, const Vector&);
protected:
	Object** beg;
	int size;
	int cur;

};


