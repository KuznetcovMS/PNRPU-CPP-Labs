#include "Vector.h"
Vector::Vector()
{
	beg = 0;
	cur = 0;
	size = 0;
}

Vector::Vector(int n)
{
	beg = new Object * [n];
	cur = 0;
	size = n;
}

Vector::~Vector()
{
	if (beg != 0) delete[] beg;
	beg = 0;
}

void Vector::Add(Object* p)
{
	if (cur < size)
	{
		beg[cur] = p;
		cur++;
	}
	else
	{
		Object** buf = new Object* [size + 1];
		for (int i = 0; i < size; i++)
		{
			buf[i] = beg[i];
		}
		buf[size] = p;
		delete []beg;
		beg = buf;
		size++;
		cur++;

	}
}

ostream& operator<<(ostream& out, const Vector& v)
{
	if (v.size == 0) out << "Empty\n";
	Object** p = v.beg;
	for (int i = 0; i < v.cur; i++)
	{
		(*p)->show();
		p++;
	}
	return out;
}
