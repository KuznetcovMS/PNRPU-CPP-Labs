#include <iostream>
#include "Pair.h"
using namespace std;

int main()
{
    Pair a;
    cin >> a;
    cout << a << endl;;
    Pair b(15, 128.64);
    b--;
    cout << b << endl;
    Pair c = b;
    --c;
    cout << c << endl;
    cout << (a < b) << endl;
    cout << (c > b) << endl;

}
