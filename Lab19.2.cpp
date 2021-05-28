#include <iostream>
#include "List.h"
using namespace std;


int main()
{
	cout << "Method 2\n";
	try
	{
		cout << "Size test\n";
		List<int> a(10);
		cout << a << endl;

		List<int> b(35);
		cout << b;
	}
	catch (Error &er)
	{
		cout << er.what() << endl;
	}

	try
	{
		cout << "\nIndex test\n";
		List<int> a(10);
		cout << a[5] << endl;

		List<int> b(25);
		cout << b[-5];
	}
	catch (Error& er)
	{
		cout << er.what() << endl;
	}
}
