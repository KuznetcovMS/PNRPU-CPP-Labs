#include <iostream>
#include "Employee.h"
#include "Vector.h"
using namespace std;

int main()
{
    Vector v(1);

    Person a;
    cin >> a;
    Object* p = &a;
    v.Add(p);

    Employee c;
    cin >> c;
    Object* pt = &c;
    pt->show();
    v.Add(pt);
    cout << v;
    

}

