#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int arr_size, collisions, M;

template <typename T>
void get_value(T& value)
{
    bool is_correct = false;
    do
    {
        cout << "Enter " << "element\n";
        cin >> value;
        if (cin.fail())
        {
            cout << "\nIncorrect value" << endl << endl;
            cin.clear();
            cin.ignore(32767, '\n');
        }
        else
        {
            is_correct = true;
            cin.ignore(32767, '\n');
        }
    } while (!is_correct);
}

struct Data
{
    string fio = "";
    string date = "";
    long long int phn = 0;
    long long int pasp = 0;
};

int Hash(string date)
{
    return (stoi(date.substr(0, 2)) + stoi(date.substr(3, 5)) + stoi(date.substr(6, 10))) % M;
}

void change_size(Data *&arr)
{
    Data* new_arr = new Data[arr_size + (arr_size / 2)];
    for (int i = 0; i < arr_size; i++)
    {
        new_arr[i] = arr[i];
    }
    arr_size += arr_size / 2;
    delete[] arr;
    arr = new_arr;
    
}

void add_elem(Data *&arr, Data elem)
{
    int hash_val = Hash(elem.date);
    if (arr[hash_val].fio.length() == 0)
    {
        arr[hash_val] = elem;
    }
    else
    {
        bool f = false;
        int last = arr_size;
        collisions++;
        for (int i = hash_val + 1; i < arr_size; i++)
        {
            if (arr[i].fio.length() == 0)
            {
                f = true;
                arr[i] = elem;
                i = arr_size;
            }
        }
        if (!f)
        {
            change_size(arr);
            arr[last] = elem;

        }
    }

}

void read_file(Data *&arr)
{
    ifstream file("F1.txt");
    if (file.is_open())
    {
        string currentLine;
        Data new_elem;
        while (!file.eof())
        {
            getline(file, currentLine);
            new_elem.fio = currentLine;

            getline(file, currentLine);
            new_elem.date = currentLine;

            getline(file, currentLine);
            new_elem.phn = stoull(currentLine);

            getline(file, currentLine);
            new_elem.pasp = stoull(currentLine);

            getline(file, currentLine);
            add_elem(arr, new_elem);
        }
        file.close();
    }
    else cout << "File not found\n";

    
}

void print_hash_table(Data arr[])
{
    for (int i = 0; i < arr_size; i++)
    {
        if (arr[i].fio.length() != 0) {
            cout << "\nElement № " << i << endl;
            cout << "FIO: " << arr[i].fio << endl;
            cout << "Date: " << arr[i].date << endl;
            cout << "Phone number: " << arr[i].phn << endl;
            cout << "Passport: " << arr[i].pasp << endl;
            cout << "Hash value: " << Hash(arr[i].date) << endl << endl;
        }
        else
        {
            cout << "Element № " << i << " is empty" << endl;
        }
        
    }
}

bool is_date(string date)
{
    if (date.length() == 10)
    {
        if (date[2] != '.' && date[5] != '.') return false;
        bool f = true;
        for (int i = 0; i < 10; i++)
        {
            if (i == 2 || i == 5) i++;
            if (int(unsigned char(date[i])) < 48 || int(unsigned char(date[0])) > 57) f = false;
        }
        return f;
    }
    else return false;
}

void find(Data arr[], string key) 
{
    if (is_date(key))
    {
        int hash_val = Hash(key);
        if (arr[hash_val].date == key)
        {
            cout << "Item found" << endl;
            cout << "FIO: " << arr[hash_val].fio << endl;
            cout << "Date: " << arr[hash_val].date << endl;
            cout << "Phone number: " << arr[hash_val].phn << endl;
            cout << "Passport: " << arr[hash_val].pasp << endl;
            cout << "Hash value: " << hash_val << endl << endl;
        }
        else
        {
            bool f = false;
            for (int i = hash_val + 1; i < arr_size; i++)
            {
                if (arr[i].date == key)
                {
                    f = true;
                    cout << "Item found" << endl;
                    cout << "FIO: " << arr[i].fio << endl;
                    cout << "Date: " << arr[i].date << endl;
                    cout << "Phone number: " << arr[i].phn << endl;
                    cout << "Passport: " << arr[i].pasp << endl;
                    cout << "Hash value: " << hash_val << endl << endl;
                }
            }
            if (!f)
            {
                cout << "Item not found\n";
            }
        }
    }
    else cout << "Incorrect date format\n";

    
}
int main()
{
    system("chcp 1251>null");
    do
    {
        get_value(arr_size);
    } while (arr_size < 2 || arr_size > 100);

    M = arr_size;
    
    Data* data_base = new Data[arr_size];
    
    read_file(data_base);
    print_hash_table(data_base);
    cout << "Collisions: " << collisions << endl;
    
    string key;
    while (key != "0")
    {
        cout << "\nEnter the date of birth of the person you are looking for: ";
        getline(cin, key);
        if (key != "0") find(data_base, key);
    }
    

}
