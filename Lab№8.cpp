#include <iostream>
#include <string>
#include <fstream>
using namespace std;


struct stadion
{
    string name;
    int year = 0;
    int amountGrounds = 0;
    string typeSports;
};


void read_file(stadion stadions[], fstream &file)
{
    string  currentLine;
    int stadionInd = 0;

    while (!file.eof())
    {
        getline(file, currentLine);
        stadions[stadionInd].name = currentLine;

        getline(file, currentLine);
        stadions[stadionInd].year = stoi(currentLine);

        getline(file, currentLine);
        stadions[stadionInd].amountGrounds = stoi(currentLine);

        getline(file, currentLine);
        stadions[stadionInd].typeSports = currentLine;

        getline(file, currentLine);
        stadionInd++;
    }
}


void print_struct(stadion stadions[], int num_elem)
{
    for (int i = 0; i < num_elem; i++)
    {
        cout << "Element №" << i + 1 << endl;
        cout << "Stadion name: " << stadions[i].name << endl;
        cout << "Year: " << stadions[i].year << endl;
        cout << "Amount Grounds: " << stadions[i].amountGrounds << endl;
        cout << "Type Sports: " << stadions[i].typeSports << endl << endl;
    }
}


void insert_elements(stadion arr[], int num, stadion arrOut[])
{
    for (int i = 0; i < num - 1; i++)
    {
        arrOut[i] = arr[i];
    }

    arrOut[num - 1].name = "Молния";
    arrOut[num - 1].year = 2000;
    arrOut[num - 1].amountGrounds = 3;
    arrOut[num - 1].typeSports = "Бег Гимнастика Лыжи";

    arrOut[num].name = "Локомотив";
    arrOut[num].year = 2002;
    arrOut[num].amountGrounds = 6;
    arrOut[num].typeSports = "Футбол Воллейбол Баскетбол Хоккей";

    for (int i = num + 1; i < 7; i++)
    {
        arrOut[i] = arr[i - 2];
    }
}


void write_in_file(stadion arr[], ofstream &file, int year)
{
    for (int i = 0; i < 7; i++)
    {
        if (arr[i].year >= year) 
        {
            file << "Stadion name: " << arr[i].name << endl;
            file << "Year: " << arr[i].year << endl;
            file << "Amount Grounds: " << arr[i].amountGrounds << endl;
            file << "Type Sports: " << arr[i].typeSports << endl << endl;
        }
    }
}

int main()
{   
    //system("chcp 65001>null");
    system("chcp 1251>null");

    fstream file ("lab8.txt");
    stadion stadions[5];
    stadion stadionsOut[7];
    int key_year = 0;
    int numDel = 0;


    if (file.is_open())
    {
        read_file(stadions, file);
        print_struct(stadions, 5);
        
        do
        {
            cout << "Введите номер элемента, перед которым необходимо вставить два элемента:" << endl;
            cin >> numDel;
            cout << endl << numDel;
        } while (numDel < 1 || numDel > 5);

        insert_elements(stadions, numDel, stadionsOut);
        print_struct(stadionsOut, 7);

        do
        {
            cout << "Введите год, ниже которого все элементы будут удалены" << endl;
            cin >> key_year;
            cout << endl;
        } while (key_year < 1);
        
        file.close();
        remove("lab8.txt");
        ofstream fileOut("lab8.txt");
        write_in_file(stadionsOut, fileOut, key_year);
    }
    else
    {
        cout << "Файл не найден";
    }
    
}
