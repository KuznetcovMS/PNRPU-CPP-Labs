#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int FillArray(int a[], ifstream& file) {
	int index = 0;
	string CurrentLine;
	while (!file.eof()) {
		getline(file, CurrentLine);
		a[index] = stoi(CurrentLine);
		index++;
	}
	return index;
};
void PrintArray(int a[], int N, int j = 0) {
	for (int i = j; i < N; i++) {
		cout << a[i] << " ";
	}
};
//Функции метода естественного слияния 
void MergeOfTwo(int array[], int size) {
	int quantity1 = 1, quantity2 = 1;
	bool flag = false;
	int i = 0, j = 0;
	while ((array[i] <= array[i + 1]) && (i < size - 1)) {
		quantity1++;
		i++;
	}
	cout << "\nКол-во элементов 1-ой серии = " << quantity1 << endl;
	if ((array[i] > array[i + 1]) && (i < size - 1)) {
		flag = true;
		i++;
		while ((array[i] <= array[i + 1]) && (i < size - 1)) {
			quantity2++;
			i++;
		}
	}
	int number = i + 1;
	int* a = new int[quantity1];
	int* b = new int[quantity2];
	cout << "Кол-во элементов 2-ой серии = " << quantity2 << endl;
	cout << "\n( ";
	for (i = 0; i < quantity1; i++) {
		a[i] = array[i];
		cout << a[i] << " ";
	}
	cout << ") + ( ";
	for (i = quantity1; i < number; i++) {
		b[j] = array[i];
		cout << b[j] << " ";
		j++;
	}
	cout << ") = ( ";
	int l = 0;
	j = 0;
	if (flag) {
		for (i = 0; i < number; i++) {
			if (((a[l] < b[j]) || (j >= quantity2)) && (l < quantity1)) {
				array[i] = a[l];
				l++;
			}
			else if (((a[l] > b[j]) || (i >= quantity1)) && (j < quantity2)) {
				array[i] = b[j];
				j++;
			}
			else if ((a[l] == b[j])) {
				array[i] = a[l];
				array[i + 1] = b[j];
				i++;
				l++;
				j++;
			}
		}
	}
	PrintArray(array, number);
	cout << ")\n";
	delete[] a;
	delete[] b;
};
void NaturalMergeSort(int array[], int size, int first) {
	bool flag = false;
	int count = 0;
	for (int i = 0; i < size - 1; i++) {
		if (array[i] <= array[i + 1]) {
			count++;
		}
		if (count == size - 1) {
			flag = true;
		}
	}
	if (!flag) {
		int number = first + 1;
		cout << endl << number << " слияние:\n";
		MergeOfTwo(array, size);
		cout << "\nМножество после слияния:\n";
		PrintArray(array, size);
		cout << "\n";
		NaturalMergeSort(array, size, first + 1);
	}
	else {
		cout << "\nОтсортированное множество:\n";
		PrintArray(array, size);
		cout << "\n";
	}
};
//Сбалансированное слияние
void Merge(int array[], int first, int last) {
	int middle, start, final;
	int* A = new int[100];
	middle = (first + last) / 2;
	start = first;
	final = middle + 1;
	for (int i = first; i <= last; i++) {
		if ((start <= middle) && ((final > last) || (array[start] < array[final]))) {
			A[i] = array[start];
			start++;
		}
		else {
			A[i] = array[final];
			final++;
		}
	}
	for (int i = first; i <= last; i++) {
		array[i] = A[i];
	}
	cout << "\n\nСлияние:\n( ";
	PrintArray(array, last + 1, first);
	cout << ")";
	delete[] A;
};
void BalanceMergeSort(int array[], int first, int last) {
	if (first < last) {
		cout << "\n\nМножество:\n";
		PrintArray(array, last + 1, first);
		cout << " = ( ";
		PrintArray(array, ((first + last) / 2) + 1, first);
		cout << ") + ( ";
		PrintArray(array, last + 1, ((first + last) / 2) + 1);
		cout << ")";
		BalanceMergeSort(array, first, (first + last) / 2);
		BalanceMergeSort(array, (first + last) / 2 + 1, last);
		Merge(array, first, last);
	}
}
int main() {
	system("chcp 1251");
	ifstream inputfile("F1.txt");
	if (inputfile.is_open()) {
		int* array = new int[100];
		int quantity = FillArray(array, inputfile);
		inputfile.close();
		PrintArray(array, quantity);
		cout << endl;
		int otvet;
		cout << "\nВведите номер метода внешней сортировки:\n0 - сортировка естественного слияния\n1 - сортировка сбалансированного слияния\n2 - сортировка многофазного слияния\nВаш выбор: ";
		cin >> otvet;
		switch (otvet) {
		case(0):
			cout << "\nВы выбрали сортировку естественного слияния\n";
			NaturalMergeSort(array, quantity, 0);
			break;
		case(1):
			cout << "\nВы выбрали сортировку сбалансированного слияния";
			BalanceMergeSort(array, 0, quantity - 1);
			cout << "\n\nОтсортированное множество:\n";
			PrintArray(array, quantity);
			cout << "\n";
			break;
		case(2):
			break;
		default:
			cout << "\nКак ты это ввёл?\n\n";
		}
		delete[] array;
	}
	else {
		cout << "\nОшибка! Не удалось открыть файл F1.txt\n";
	}
	system("pause");
	return 0;
}