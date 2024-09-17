#pragma once
#include "Person.h"
#include <string>
using namespace std;

class Abiturient :
    public Person
{
protected:
    int m_ball;
    string m_spec;
public:
    Abiturient();
    Abiturient(const Abiturient& a);
    Abiturient(string name, int age, int ball, string spec);
    ~Abiturient();

    void set_ball(int ball);
    void set_spec(string spec);

    int get_ball();
    string get_spec();

    int value();
    void show();
    void input();

    Abiturient& operator=(const Abiturient& a);
};

