#include "Employee.h"

int main()
{
	Person a;
	cin >> a;
	cout << a;
	Person b = a;
	cout << b;
	Person c("Vasya", 35);
	cout << c;

	Employee e;
	cout << e;
	cin >> e;
	cout << e;
	Employee f = e;
	Employee k("Sergey", 32, "software engineer", 100000.99);
	cout << k;
	cout << "Final salary: " << k.get_final_salary(50.25);

}

