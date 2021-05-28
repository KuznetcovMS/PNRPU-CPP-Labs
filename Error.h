#pragma once
#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 30;

class Error
{
public:
	Error();
	Error(string m);
	~Error();
	string what();
private:
	string messaage;
};

