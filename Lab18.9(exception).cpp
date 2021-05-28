#include <iostream>
#include "List.h"
using namespace std;


int main()
{
    cout << "Method 1\n";
	//Test size
	try
	{
		cout << "List size: 10\n";
		List<int> a(10);
		cout << a << endl;
		cout << "List size: 35\n";
		List<int> b(35);
		cout << b;
	}
	catch (const char *ex)
	{
		cout << ex;
	}

	//Test incorrect index
	try
	{
		cout << "\n\nIndex test\n";
		List<int> c(10, 15);
		cout << c << endl;

		cout << c[5] << endl;
		cout << c[10];
	}
	catch (const char* ex)
	{
		cout << ex << endl;
	}

	cout << "Method 2\n";
}

