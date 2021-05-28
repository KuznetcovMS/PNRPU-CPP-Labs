#include <iostream>
#include <string>
using namespace std;

struct Data
{
    string name;
    int num = 0;
};

void print_struct(Data arr[])
{
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i].name << ": " << arr[i].num << endl;
    }
    cout << endl << endl;
}

int get_ind(string st, string st2)
{
    if (st == st2)
    {
        return 0;
    }
    else
    {
        int i = 0;
        while (st[i] != '/0' || st2[i] != '/0')
        {
            if (st[i] != st2[i])
            {
                return i;
            }
            i++;
        }
    }
}
void sh_sort(Data arr[], int size)
{
    int d = size / 2;
    while (d > 0)
    {
        for (int i = d; i < size; i++)
        {
            Data cur_val = arr[i];
            int pos = i;
            while (pos >= d && (unsigned int)arr[pos - d].name[get_ind(arr[pos - d].name, cur_val.name)] > (unsigned int)cur_val.name[get_ind(arr[pos - d].name, cur_val.name)])
            {
                arr[pos] = arr[pos - d];
                pos -= d;
                arr[pos] = cur_val;
            }
        }
        d = d / 2;
    }
}

void hoarasort(Data arr[], int first, int last)
{

    int i = first, j = last;
    unsigned int  x = (unsigned int)arr[(first + last) / 2].name[0];
    Data tmp;

    do {
        while ((unsigned int)arr[i].name[0] < x)
            i++;
        while ((unsigned int)arr[j].name[0] > x)
            j--;

        if (i <= j)
        {
            if (i < j)
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
            i++;
            j--;
        }
    } while (i <= j);

    if (i < last)
        hoarasort(arr, i, last);
    if (first < j)
        hoarasort(arr, first, j);
}

int main()
{
    const int size = 6;
    system("chcp 1251>null");

    Data arr_sh[size] = { {"Александр Пушкин", 826}, {"Фёдр Достоевский", 18}, {"Михаил Лермонтов", 449}, {"Николай Гоголь", 30}, {"Лев Толстой", 174},  {"Михаил Булгаков", 30} };
    Data arr_hoar[size] = { {"Александр Пушкин", 826}, {"Фёдр Достоевский", 18}, {"Михаил Лермонтов", 449}, {"Николай Гоголь", 30}, {"Лев Толстой", 174},  {"Михаил Булгаков", 30} };

    cout << "Изначальный массив:\n\n";
    print_struct(arr_sh);

    cout << "Сортировка Шелла:\n\n";
    sh_sort(arr_sh, size);
    print_struct(arr_sh);

    cout << "Быстрая сортировка Хоара:\n\n";
    hoarasort(arr_hoar, 0, 5);
    print_struct(arr_hoar);

}

