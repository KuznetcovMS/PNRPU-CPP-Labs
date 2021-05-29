#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;
#include "Money.h"

Money::Money(int r, long int c)
{
	rub = r;
	cop = c;
	double co = c;
	sum = r + co / 100;
}

double Money::Get()
{
	return sum;
}

void Money::Print()
{
	cout << "\nРубли - " << rub << ", копейки - " << cop;
}



Vector::Vector(int s)
{
	size = s;
	data = new int[size];
	cout << "Введи числа" << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> data[i];
	}
}

int Vector::give(int index)
{
	return data[index];
}

int Vector::givesize()
{
	return size;
}


void Vector::end()
{
	delete[] data;
	data = 0;
}

void Vector::pushback(int el)
{
	int* data1;
	data1 = new int[size + 1];
	for (int i = 0; i < size; i++)
		data1[i] = data[i];
	data1[size] = el;
	delete[] data;
	data = data1;
	size++;
}

void Vector::del(int index)
{
	int* data1;
	data1 = new int[size - 1];
	for (int i = 0; i < index; i++)
		data1[i] = data[i];
	for (int i = index+1; i < size; i++)
		data1[i-1] = data[i];
	delete[] data;
	data = data1;
	size--;
}

int Vector::min()
{
	int min = 32000;
	for (int i = 0; i < size; i++)
	{
		if (data[i] < min)
			min = data[i];
	}
	return min;
}

int Vector::max()
{
	int max = -32000;
	for (int i = 0; i < size; i++)
	{
		if (data[i] > max)
			max = data[i];
	}
	return max;
}

void Vector::bred(int max, int min, int index)
{
	data[index] = data[index] + min + max;
}