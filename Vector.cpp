#include "Vector.h"
#include "Abiturient.h"
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

void Vector::Add()
{
	cout << "1 - Add Person\n";
	cout << "2 - Add Abiturient\n";
	int type;
	cin >> type;
	Object* p = nullptr;
	switch (type)
	{
	case 1:
		p = new Person;
		p->input();
		break;
	case 2:
		p = new Abiturient;
		p->input();
		break;
	default:
		cout << "Incorrect value";
		break;
	}
	if (type == 1 || type == 2)
	{
		if (cur < size)
		{
			beg[cur] = p;
			cur++;
		}
		else
		{
			Object** buf = new Object * [size + 1];
			for (int i = 0; i < size; i++)
			{
				buf[i] = beg[i];
			}
			buf[size] = p;
			delete[]beg;
			beg = buf;
			size++;
			cur++;

		}
	}
	
}

void Vector::Del()
{
	if (cur != 0) cur--;
}

void Vector::Show()
{
	for (int i = 0; i < cur; i++)
	{
		beg[i]->show();
	}
}

void Vector::Avg()
{
	float avg = 0;
	int sum = 0;
	for (int i = 0; i < cur; i++)
	{
		sum += beg[i]->value();
	}
	if (cur > 0)
	{
		avg = float(sum) / cur;
		cout << "Average age: " << avg << endl << endl;
	}
	else cout << "Group is empty" << endl << endl;
	
}

int Vector::operator()()
{
	return cur;
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
