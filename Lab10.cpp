#include <iostream>
#include <string>
using namespace std;


int get_num_equal(string arr[], int size)
{
    int count = 0;
    int j, num_eq;
    for (int i = 0; i < size; i++)
    {
        j = i - 1;
        num_eq = 1;
        while (j >= 0)
        {
            if (arr[i] == arr[j])
            {
                num_eq++;
            }
            j--;
        }
        if (num_eq > 1)
        {
            if (num_eq == 2)
            {
                count += num_eq;
            }
            else
            {
                count++;
            }
        }
    }
    return count;
}
int main()
{
    system("chcp 1251>null");
    int size;

    do
    {
        cout << "Введите количество строк\n";
        cin >> size;
        if (cin.fail())
        {
            cout << "*";
            cin.clear();
            cin.ignore(32767, '\n');
            size = -1;
        }
        cin.ignore(32767, '\n');
    } while (size < 0);

    string* main_arr = new string[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Введите строку: ";
        getline(cin, main_arr[i]);
    }
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Строка № " << i + 1 << ": ";
        cout << main_arr[i] << endl;
    }

    int num_eq = get_num_equal(main_arr, size);
    if (num_eq > 0)
    {
        cout << "\nКоличесвто одинаковых строк в массиве: " << num_eq << endl;
        if (num_eq == size)
        {
            cout << "Массив полностью состоит из повторяющихся строк, поэтому все строки были удалены" << endl;
            delete[] main_arr;
        }
        else
        {
            string* final_arr = new string[size - num_eq];
            int ind = 0;
            for (int i = 0; i < size; i++)
            {
                bool f = false;
                int j = 0;
                while (j < size && !f)
                {
                    if (i != j)
                    {
                        if (main_arr[i] == main_arr[j])
                            f = true;
                    }
                    j++;
                }
                if (!f)
                {
                    final_arr[ind] = main_arr[i];
                    ind++;
                }
            }
            delete[] main_arr;
            cout << "Массив без повторяющихся строк\n\n";
            for (int i = 0; i < size - num_eq; i++)
            {
                cout << "Строка № " << i + 1 << ": ";
                cout << final_arr[i] << endl;
            }
            delete[] final_arr;
        }
    }
    else
    {
        delete[] main_arr;
        cout << "В массиве нет повторяющихся строк\n";
    }
}

