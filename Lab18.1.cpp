#include <iostream>
#include "Fraction.h"
using namespace std;

fraction make_frac(int f, double s)
{
    fraction t;
    t.Init(f, s);
    return t;
}
int main()
{
    fraction A, B;
    A.Init(5, 0.25);
    B.Read();
    A.Show();
    B.Show();

    cout << "\nA multiply result: "<< A.multiply(4.25) << endl;
    double m;
    cout << "\nEnter number: ";
    cin >> m;
    cout << "\nMultiply result: " << B.multiply(m) << endl;

    fraction C = make_frac(253, 0.128);
    cout << "\nMultiply C result: " << C.multiply(128.165) << endl;
}

