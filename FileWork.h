#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include "Pair.h"

int make_file(string& f_name)
{
	fstream file(f_name, ios::out | ios::trunc);
	if (!file) return -1;

	int n;
	Pair p;

	cout << "Enter number of elements: ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> p;
		file << p << '\n';
	}

	file.close();
	return n;
}

int print_file(string& file_name)
{
	fstream file(file_name, ios::in);
	if (!file) return -1;
	int i = 0;
	Pair p;
	while (file >> p)
	{
		cout << p << endl;
		i++;
	}
	file.close();
	return i;
}

int del_file(string& file_name, int k)
{
	ofstream buf("temp.txt", ios::out|ios::trunc);
	Pair p;
	fstream file(file_name);
	int i = 0;
	if (!file) return -1;
	while (file >> p)
	{
		i++;
		if (i != k) buf << p << '\n';
	}
	file.close(); buf.close();
	remove(file_name.c_str());
	rename("temp.txt", file_name.c_str());
	return i;
}

int add_file(string& f_name, int k)
{
	fstream temp("temp.txt", ios::out | ios::trunc);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Pair p; int i = 0, l = 0;
	Pair pp;
	cin >> pp;
	while (stream >> p)
	{
		i++;
		if (i == k)
		{
			temp << pp << '\n';
			l++;
		}
		temp << p << '\n';
	}
	if (l == 0) temp << pp << '\n';
	stream.close(); temp.close();
	remove(f_name.c_str());
	rename("temp.txt", f_name.c_str());
	return l;
}

int change_file(string& f_name, int k)
{
	fstream temp("temp.txt", ios::out | ios::trunc);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Pair p; int i = 0, l = 0;
	Pair pp;
	
	char x;
	while (stream >> p)
	{
		i++;
		if (i == k)
		{
			cout << p << " - is changing... Continue[y/n]?\n";
			cin >> x;
			if (x == 'n' || x == 'N') break;
			cin >> pp;
			temp << pp << '\n';
			l++;
		}
		else temp << p << '\n';
	}
	stream.close(); temp.close();
	remove(f_name.c_str());
	rename("temp.txt", f_name.c_str());
	return l;
}
