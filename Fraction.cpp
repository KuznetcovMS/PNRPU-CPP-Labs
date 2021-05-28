#include "Fraction.h"
#include <iostream>
using namespace std;

void fraction::Init(int f, double s)
{
	first = f; second = s;
}

void fraction::Read()
{
	cout << "Enter first number (int): ";
	cin >> first;
	cout << "\nEnter second number (double): ";
	cin >> second;
}

void fraction::Show()
{
	cout << "\nfirst = " << first;
	cout << "\nsecond = " << second;
	cout << endl;
}

double fraction::multiply(double k)
{
	return first * k + second * k;
}