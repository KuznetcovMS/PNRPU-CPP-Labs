#include <iostream>
#include "Money.h"
#include <algorithm>
#include <functional>
using namespace std;

VectorOfMoney::VectorOfMoney(int s)
{
	size = s;
	data = new double[size];
	cout << "¬води суммы" << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> data[i];
	}
}

void VectorOfMoney::Print()
{
	for (int i = 0; i < size; i++)
		cout << data[i] << " ";
	cout << endl;
}

double VectorOfMoney::FindMin()
{
	double min = 32000;
	for (int i = 0; i < size; i++)
	{
		if (data[i] < min)
			min = data[i];
	}
	return min;
}

double VectorOfMoney::FindMax()
{
	double max = -32000;
	for (int i = 0; i < size; i++)
	{
		if (data[i] > max)
			max = data[i];
	}
	return max;
}

void VectorOfMoney::pushback(double el)
{
	double* data1;
	data1 = new double[size+1];
	for (int i = 0; i < size; i++)
	{
		data1[i] = data[i];
	}
	data1[size] = el;
	delete[] data;
	data = data1;
	size++;
}

void VectorOfMoney::del(double el)
{
	int k = 0;
	for (int i = 0; i < size; i++)
	{
		if (data[i] == el)
			k++;
	}
	double* data1;
	data1 = new double[size - k];
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		if (data[i] != el)
			data1[j] = data[i];
		else
			j--;
		j++;
	}
	delete[] data;
	data = data1;
	size = size - k;
}

void VectorOfMoney::add2(double el1, double el2)
{
	for (int i = 0; i < size; i++)
	{
		data[i] = data[i] + el1 + el2;
	}
}
