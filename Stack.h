#pragma once
#include <iostream>
using namespace std;
struct Node{
	double data;
	Node* prev;
};
class Stack {
private:
	Node* top;
	int size;
public:
	Stack();
	~Stack();
	double Top();
	void Push(double);
	void Pop();
	int Size();
	void Show();
};