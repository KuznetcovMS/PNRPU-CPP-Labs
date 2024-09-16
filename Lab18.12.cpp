#include <iostream>
#include <vector>
#include <queue>
#include "Money.h"
#include <list>
#include <deque>
#include <set>
using namespace std;

void Multi()
{
	float check = 1, menu = 1;
	float min = 32000, max = -32000;
	multiset<float> mSet;
	cout << "Вводи элементы дерева. Окончание ввода - 0" << endl;
	while (check != 0)
	{
		cin >> check;
		if (check != 0)
			mSet.insert(check);
		else break;
	}
	while (menu == 1 || menu == 2 || menu == 3 || menu == 4)
	{

		cout << "Меню: \n1. Вывести структуру\n2. Найти минимум и добавить в конец \n3. Найти элемент и удалить \n4. К каждому элементу добавить сумму максимума и минимума \n\n0. Выход";
		cout << endl << "Выбери пункт меню: "; cin >> menu;

		if (menu == 1)
		{
			for (auto& item : mSet)
			{
				cout << item << " ";
			}
			cout << endl;
		}

		if (menu == 2)
		{
			for (auto& item : mSet)
			{
				if (item < min)
					min = item;
			}
			mSet.insert(min);
			cout << "Элемент добавлен" << endl;
		}

		if (menu == 3)
		{
			cout << "Введи элемент: "; cin >> check;
			if (mSet.find(check) != mSet.end())
			{
				mSet.erase(check);
				cout << "Элемент удален" << endl;
			}
			else
				cout << "Элемент не найден" << endl;
		}

		if (menu == 4)
		{
			int i = 0, s = mSet.size();
			float* mas = new float[mSet.size()];
			min = 32000;
			for (auto& item : mSet)
			{
				if (item > max) max = item;
				if (item < min) min = item;
			}
			for (auto& item : mSet)
			{
				mas[i] = item + min + max;
			}
			mSet.clear();
			for (i = 0; i < s; i++)
			{
				check = mas[i];
				mSet.insert(check);
			}
			delete[] mas;
			cout << "\nИзменения применены" << endl;
		}
	}
}



void Moneyy()
{
	int s = 0, r = 0, menu = 1, index, k = 0;
	double zn, min = 32000, max = -32000;
	long int c = 0;
	while (s <= 0)
	{
		cout << "Введи количество сумм: "; cin >> s;
	}
	Money* data;
	data = new Money[s];
	for (int i = 0; i < s; i++)
	{
		cout << "Введи количество рублей: "; cin >> r;
		cout << "Введи количество копеек: "; cin >> c; cout << endl;
		data[i] = Money(r, c);
	}
	while (menu == 1 || menu == 2 || menu == 3 || menu == 4)
	{

		cout << "Меню: \n1. Вывести все суммы\n2. Найти минимум и добавить в конец \n3. Найти элемент и удалить \n4. К каждому элементу добавить сумму максимума и минимума \n\n0. Выход";
		cout << endl << "Выбери пункт меню: "; cin >> menu;

		if (menu == 1)
		{
			for (int i = 0; i < s; i++)
			{
				cout << data[i].Get() << " ";
			}
			cout << endl;
		}

		if (menu == 2)
		{
			for (int i = 0; i < s; i++)
			{
				if (data[i].sum < min)
					min = data[i].sum;
			}
			Money* data1;
			data1 = new Money[s + 1];
			for (int i = 0; i < s; i++)
			{
				data1[i] = data[i];
			}
			data1[s].sum = min;
			delete[] data;
			data = data1;
			cout << "Элемент добавлен" << endl;
			s++;
		}


		if (menu == 3)
		{
			cout << "Введи значение: "; cin >> zn;
			for (int i = 0; i < s; i++)
			{
				if (data[i].sum == zn)
				{
					data[i].sum = -1;
					k++;
				}

			}
			Money* data1;
			data1 = new Money[s - k];
			int j = 0;
			for (int i = 0; i < s; i++)
			{
				if (data[i].sum != -1)
				{
					data1[j] = data[i];
					j++;
				}
			}
			delete[] data;
			data = data1;
			s = s - k;
			k = 0;
			cout << "Элементы удалены" << endl;
		}

		if (menu == 4)
		{

			for (int i = 0; i < s; i++)
			{
				if (data[i].sum > max) max = data[i].sum;
				if (data[i].sum < min) min = data[i].sum;
			}
			for (int i = 0; i < s; i++)
				data[i].sum = data[i].sum + max + min;
			cout << "\nИзменения применены" << endl;

		}
	}
}



void Vectorrr()
{
	int s, in, menu = 4;
	cout << "Введи количество сумм "; cin >> s;
	Vector a(s);
	while (menu == 1 || menu == 2 || menu == 3 || menu == 4)
	{

		cout << "Меню: \n1. Вывести вектор\n2. Найти минимум и добавить в конец \n3. Найти элемент и удалить \n4. К каждому элементу добавить сумму максимума и минимума \n\n0. Выход";
		cout << endl << "Выбери пункт меню: "; cin >> menu;
		if (menu == 1)
		{
			for (int i = 0; i < a.givesize(); i++)
				cout << a.give(i) << " ";
			cout << endl;
		}

		if (menu == 2)
		{
			a.pushback(a.min());
			cout << "Элемент добавлен" << endl;
		}

		if (menu == 3)
		{
			int el;
			cout << "Введи элемент: "; cin >> el;
			for (int i = 0; i < a.givesize(); i++)
			{
				if (a.give(i) == el)
					a.del(i);
			}
			cout << "Элемент удален" << endl;
		}

		if (menu == 4)
		{
			for (int i = 0; i < a.givesize(); i++)
			{
				a.bred(a.max(), a.min(), i);
			}
			cout << "Изменения внесены" << endl;
		}

		if (menu == 0)
		{
			a.end();
			break;
		}
	}
}


int main()
{
	setlocale(LC_ALL, "Russian");
	int menu = 1;

	while (menu == 1 || menu == 2 || menu == 3 || menu == 4 || menu == 5)
	{

		cout << "Меню: \n1. multiset\n2. Money \n3. Параметризированный вектор \n\n0. Выход";
		cout << endl << "Выбери пункт меню: "; cin >> menu;

		if (menu == 1)
			Multi();

		if (menu == 2)
			Moneyy();

		if (menu == 3)
			Vectorrr();
	}


}