#include <iostream>
#include "List.h"
#include<conio.h>
using namespace std;

void test()
{
	system("pause");
	List *a = new List(200000, 128);
	cout << a->get_size() << " ";
	system("pause");
	delete a;
	system("pause");
}

int main()
{	List a;
	cout << sizeof(int) << endl;
	a.push_back(0);
	a.push_back(1);
	a.push_back(2);
	a.insert(1, 12);
	a.insert(0, 99);
	a.insert(5, 1128);
	a.insert(10, 64);
	cout << a;
	List b;
	b = a;
	cout << endl << b;
	a = a + 10;
	cout << endl << a;
	a = a + b;
	cout << endl << a;
	List c = b;
	cout << endl << c;
	List d = c;
	d = a;
	cout << "\n" << d;
	
	Iterator it = a.begin();
	cout << endl << endl;
	cout << *it << " ";
	++it;
	cout << *it << " ";
	--it;
	cout << *it << " ";

	//test();
}

