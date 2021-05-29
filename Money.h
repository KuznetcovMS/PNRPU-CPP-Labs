#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

class Money
{
public:
	long int rub;
	int cop;
	double sum;
	Money()
	{
		rub = cop = sum = 0;
	}

	Money(int r, long int c);
	double Get();
	void Print();
};


class Vector
{
public:
	Vector(int s);
	int give(int index);
	int givesize();
	void end();
	void pushback(int el);
	void del(int index);
	int min();
	int max();
	void bred(int max, int min, int index);
private:
	int size;
	int* data;
};
