#pragma once
#include <iostream>
#include <algorithm>
using namespace std;


struct elem
{
	int value = 0;
	elem* next = nullptr;
	elem* prev = nullptr;
};


class Iterator
{
	friend class List;
public:
	Iterator();
	Iterator(const Iterator& iter);
	~Iterator();
	bool operator==(const Iterator& iter);
	bool operator!=(const Iterator& iter);
	void operator++();
	void operator--();
	int& operator*();
private:
	elem* it;
};


class List
{
public:
	List();
	List(const List& l);
	List(int s, int k = 0);
	void destroy();
	~List();

	List& operator=(const List& l);
	int& operator[](int ind);
	List& operator+(const int v);
	List& operator+(List& l);

	int get_size();
	void push_back(int val);
	void insert(int pos, int val);

	Iterator begin();
	Iterator ending();

	friend ostream& operator<<(ostream& out, const List& l);
	friend istream& operator>>(istream& in, const List& l);
private:
	elem* first;
	elem* last;
	elem* cur;
	elem* cur_elem;
	int cur_pos;
	int size;
	Iterator beg;
	Iterator end;
};


