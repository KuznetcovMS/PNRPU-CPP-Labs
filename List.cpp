#include "List.h"

List::List()
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

List::List(const List& l)
{
	elem* buf;
	buf = l.first;
	first = new elem;
	first->value = l.first->value;
	cur = first;
	last = first;
	size = 1;
	for (int i = 1; i < l.size; i++)
	{
		buf = buf->next;
		last = new elem;
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

List::List(int s, int k)
{
	if (s > 0)
	{
		first = new elem;
		first->value = k;
		first->prev = nullptr;
		first->next = nullptr;
		cur_elem = first;
		cur = first;
		last = first;
		size = 1;
		for (int i = 1; i < s; i++)
		{
			cur->next = new elem;
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


void List::destroy()
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

List::~List()
{
	destroy();
}

List& List::operator=(const List& l)
{
	if (&l == this) return *this;
	size = l.size;
	if (first != nullptr) destroy();
	if (l.size != 0)
	{
		elem* buf; 
		buf = l.first;
		first = new elem;
		first->value = l.first->value;
		cur = first;
		last = first;
		size = 1;
		for (int i = 1; i < l.size; i++)
		{
			buf = buf->next;
			last = new elem;
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

int& List::operator[](int ind)
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

List& List::operator+(const int v)
{
	for (int i = 0; i < size; i++)
	{
		this->operator[](i) += v;
	}
	return *this;
}

List& List::operator+(List& l)
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

int List::get_size()
{
	return size;
}

void List::push_back(int val)
{
	cur = last;
	if (cur != nullptr)
	{
		cur->next = new elem;
		cur = cur->next;
		cur->value = val;
		cur->prev = last;
		last = cur;
		size++;
	}
	else
	{
		first = new elem;
		first->value = val;
		last = first;
		size = 1;
	}
	beg.it = first;
	end.it = last;
}

void List::insert(int ind, int val)
{
	cur = first;
	if (cur != nullptr)
	{
		if (ind == 0)
		{
			cur = new elem;
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
			elem* buf = new elem;
			buf->value = val;
			buf->next = cur->next;
			buf->prev = cur;
			cur->next = buf;
			size++;
		}
	}
	else
	{
		first = new elem;
		first->value = val; 
		size++;
	}
	beg.it = first;
	end.it = last;
	
}

Iterator List::begin()
{
	return beg;
}

Iterator List::ending()
{
	return end;
}


ostream& operator<<(ostream& out, const List& l)
{
	elem* buf = l.first;
	out << buf->value << " ";
	for (int i = 1; i < l.size; i++)
	{
		buf = buf->next;
		out <<  buf->value << " ";
	}
	return out;
}

istream& operator>>(istream& in, List& l)
{
	cout << "Enter " << l.get_size() << " elements:";
	for (int i = 0; i < l.get_size(); i++)
	{
		in >> l[i];
	}
	return in;
}

Iterator::Iterator()
{
	it = nullptr;
}

Iterator::Iterator(const Iterator& iter)
{
	it = iter.it;
}

Iterator::~Iterator()
{
}

bool Iterator::operator==(const Iterator& iter)
{
	return (it==iter.it);
}

bool Iterator::operator!=(const Iterator& iter)
{
	return (it != iter.it);
}

void Iterator::operator++()
{
	it = it->next;
}

void Iterator::operator--()
{
	it = it->prev;
}

int& Iterator::operator*()
{
	return it->value;
}
