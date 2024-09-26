#pragma once
#ifndef LIST_H
#define LIST_H


#include <iostream>
#include <algorithm>
using namespace std;

template <class T>
struct elem
{
	T value;
	elem<T>* next = nullptr;
	elem<T>* prev = nullptr;
};

template <class T>
class List;

template <class T>
class Iterator
{
	friend class List<T>;
public:
	Iterator();
	Iterator(const Iterator<T>& iter);
	~Iterator();
	bool operator==(const Iterator<T>& iter);
	bool operator!=(const Iterator<T>& iter);
	void operator++();
	void operator--();
	T& operator*();
private:
	elem<T>* it;
};

template <class T>
class List
{
public:
	List();
	List(const List<T>& l);
	List(int s, T k = 0);
	void destroy();
	~List();

	List<T>& operator=(const List<T>& l);
	T& operator[](int ind);
	List<T>& operator+(const T v);
	List<T>& operator+(List<T>& l);

	int get_size();
	void push_back(T val);
	void insert(int pos, T val);

	Iterator<T> begin();
	Iterator<T> ending();

	friend ostream& operator<< <>(ostream& out, const List<T>& l);
	friend istream& operator>> <>(istream& in, List<T>& l);
private:
	elem<T>* first;
	elem<T>* last;
	elem<T>* cur;
	elem<T>* cur_elem;
	int cur_pos;
	int size;
	Iterator<T> beg;
	Iterator<T> end;
};

template<class T>
List<T>::List()
{
	first = nullptr;
	last = nullptr;
	cur = nullptr;
	cur_elem = nullptr;
	cur_pos = 0;
	size = 0;
	beg.it = first;
	end.it = last;
}

template<class T>
List<T>::List(const List<T>& l)
{
	elem<T>* buf;
	buf = l.first;
	first = new elem<T>;
	first->value = l.first->value;
	cur = first;
	last = first;
	size = 1;
	for (int i = 1; i < l.size; i++)
	{
		buf = buf->next;
		last = new elem<T>;
		cur->next = last;
		last->prev = cur;
		last->value = buf->value;
		cur = last;
		size++;
	}
	cur = first;
	cur_elem = 0;
	cur_pos = 0;
	beg.it = first;
	end.it = last;
}

template<class T>
List<T>::List(int s, T k)
{
	if (s > 0)
	{
		first = new elem<T>;
		first->value = k;
		first->prev = nullptr;
		first->next = nullptr;
		cur_elem = first;
		cur = first;
		last = first;
		size = 1;
		for (int i = 1; i < s; i++)
		{
			cur->next = new elem<T>;
			cur->next->prev = cur;
			cur = cur->next;
			cur->value = k;
			cur->next = nullptr;
			last = cur;
			size++;
		}
		cur = first;
		cur_pos = 0;
	}
	else
	{
		first = nullptr;
		last = nullptr;
		cur = nullptr;
		cur_elem = nullptr;
		cur_pos = 0;
		size = 0;
	}
	beg.it = first;
	end.it = last;
}

template<typename T>
void List<T>::destroy()
{
	cur = first;
	if (cur != nullptr)
	{
		int count = 0;
		while (cur->next != nullptr)
		{
			size--;
			cur = cur->next;
			delete first;
			first = cur;
		}
		size--;
		delete cur;
	}
}

template<typename T>
List<T>::~List()
{
	destroy();
}

template<typename T>
List<T>& List<T>::operator=(const List<T>& l)
{
	if (&l == this) return *this;
	size = l.size;
	if (first != nullptr) destroy();
	if (l.size != 0)
	{
		elem<T>* buf;
		buf = l.first;
		first = new elem<T>;
		first->value = l.first->value;
		cur = first;
		last = first;
		size = 1;
		for (int i = 1; i < l.size; i++)
		{
			buf = buf->next;
			last = new elem<T>;
			cur->next = last;
			last->prev = cur;
			last->value = buf->value;
			cur = last;
			size++;
		}
		cur = first;

	}
	beg.it = first;
	end.it = last;
	return *this;
}

template<typename T>
T& List<T>::operator[](int ind)
{
	if (ind < 0 || ind >= size)
	{
		cout << "Incorrect index\n";
		return last->next->value;
	}

	cur = first;
	for (int i = 1; i <= ind; i++)
	{
		cur = cur->next;
	}
	return cur->value;
}

template<typename T>
List<T>& List<T>::operator+(const T v)
{
	for (int i = 0; i < size; i++)
	{
		this->operator[](i) += v;
	}
	return *this;
}

template<typename T>
List<T>& List<T>::operator+(List<T>& l)
{
	if (size == 0)
	{
		*this = l;
		return *this;
	}
	else if (l.size == 0)
	{
		cout << "This class instance is empty\n";
		return *this;
	}
	for (int i = 0; i < min(size, l.size); i++)
	{
		this->operator[](i) += l[i];
	}
	return *this;
}

template<typename T>
int List<T>::get_size()
{
	return size;
}

template<typename T>
void List<T>::push_back(T val)
{
	cur = last;
	if (cur != nullptr)
	{
		cur->next = new elem<T>;
		cur = cur->next;
		cur->value = val;
		cur->prev = last;
		last = cur;
		size++;
	}
	else
	{
		first = new elem<T>;
		first->value = val;
		last = first;
		size = 1;
	}
	beg.it = first;
	end.it = last;
}

template<typename T>
void List<T>::insert(int ind, T val)
{
	cur = first;
	if (cur != nullptr)
	{
		if (ind == 0)
		{
			cur = new elem<T>;
			cur->value = val;
			cur->next = first;
			first->prev = cur;
			first = cur;
			size++;
		}
		else if (ind >= size)
		{
			this->push_back(val);
		}
		else if (ind > 0 && ind < size)
		{
			for (int i = 1; i < ind; i++)
			{
				cur = cur->next;
			}
			elem<T>* buf = new elem<T>;
			buf->value = val;
			buf->next = cur->next;
			buf->prev = cur;
			cur->next = buf;
			size++;
		}
	}
	else
	{
		first = new elem<T>;
		first->value = val;
		size++;
	}
	beg.it = first;
	end.it = last;

}

template<typename T>
Iterator<T> List<T>::begin()
{
	return beg;
}

template<typename T>
Iterator<T> List<T>::ending()
{
	return end;
}

template<typename T>
Iterator<T>::Iterator()
{
	it = nullptr;
}

template<typename T>
Iterator<T>::Iterator(const Iterator<T>& iter)
{
	it = iter.it;
}

template<typename T>
Iterator<T>::~Iterator()
{
}

template<typename T>
bool Iterator<T>::operator==(const Iterator<T>& iter)
{
	return (it == iter.it);
}

template<typename T>
bool Iterator<T>::operator!=(const Iterator<T>& iter)
{
	return (it != iter.it);
}

template<typename T>
void Iterator<T>::operator++()
{
	it = it->next;
}

template<typename T>
void Iterator<T>::operator--()
{
	it = it->prev;
}

template<typename T>
T& Iterator<T>::operator*()
{
	return it->value;
}

template<typename T>
ostream& operator<< <>(ostream& out, const List<T>& l)
{
	elem<T>* buf = l.first;
	out << buf->value << " ";
	for (int i = 1; i < l.size; i++)
	{
		buf = buf->next;
		out << buf->value << " ";
	}
	return out;
}

template<typename T>
istream& operator>> <>(istream& in, List<T>& l)
{
	cout << "Enter " << l.get_size() << " elements:";
	for (int i = 0; i < l.get_size(); i++)
	{
		in >> l[i];
	}
	return in;
}
#endif // !LIST_H