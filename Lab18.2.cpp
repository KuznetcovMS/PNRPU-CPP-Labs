#include <iostream>
#include <string>
#include "Abiturient.h"
using namespace std;

Abiturient make_abiturient()
{
    string fio, spec;
    int ege;
    cout << "\nEnter FIO: ";
    getline(cin, fio);
    cout << "\nEnter speciality: ";
    getline(cin, spec);
    cout << "\nEnter ege result: ";
    cin >> ege;
    Abiturient a(fio, spec, ege);
    return a;
}

void print_abiturient(Abiturient a)
{
    a.show();
}

int main()
{
    //Constructor without parametrs
    Abiturient a;
    a.show();

    //Constructor with parametrs
    Abiturient b("Vasya Pupkin", "Software Engineer", 246);
    b.show();

    //Copy constructor
    Abiturient c = b;
    c.show();
    c.set_fio("Bill Gates");
    c.set_speciality("Programmer");
    c.set_ege(301);
    print_abiturient(c);

    //Copy constructor
    Abiturient d = make_abiturient();
    d.show();





    
}


