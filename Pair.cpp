#include "Pair.h"
#include <iostream>
using namespace std;

Pair& Pair::operator=(const Pair& p)
{
	if (&p == this) return *this;
	first = p.first;
	second = p.second;
	return *this;
}

Pair& Pair::operator--()
{
	first--;
	return *this;
}

Pair& Pair::operator--(int)
{
	second--;
	return *this;
}

bool Pair::operator<(const Pair& p)
{
	return (first + second < p.first + p.second);
}

bool Pair::operator>(const Pair& p)
{
	return (first + second > p.first + p.second);
}

istream& operator>>(istream& in, Pair& p)
{
	cout << "Enter first: ";
	in >> p.first;
	cout << endl;
	cout << "Enter second: ";
	in >> p.second;
	cout << endl;
	return in;
}

ostream& operator<<(ostream& out, const Pair& p)
{
	return (out << p.first << " : " << p.second);
}
