#include <iostream>
#include "List.h"
#include "Pair.h"
using namespace std;

int main()
{
    List<float> c(10, 5.0);
    c.push_back(0);
    cout << c << endl;

    //Pair p(1, 2.5);
    List<Pair> lp(10, Pair(1, 2.5));
    cout << lp << endl;

    List<Pair> llp(12, Pair(128, 35.7));

    cout << llp;
    
   
}
