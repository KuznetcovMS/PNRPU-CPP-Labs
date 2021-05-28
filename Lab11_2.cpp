#include <iostream>
#include <list>
#include <iterator>
using namespace std;

struct List
{
    int data;
    List* next;
    List* prev;
};

template <typename T>
void get_value(T& value, int i)
{
    bool is_correct = false;
    do
    {
        cout << "Enter " << i << " element\n";
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

List* make(int size)
{
    List* first, * p;
    first = 0;
    p = new List;
    get_value(p->data, 1);
    first = p;
    first->next = NULL;
    first->prev = NULL;
    for (int i = 2; i <= size; i++)
    {
        List* h = new List;
        List* q = p;
        p->next = h;
        p = p->next;
        get_value(p->data, i);
        p->next = NULL;
        p->prev = q;
    }
    return first;
}

void print_list(List* first)
{
    if (first != NULL)
    {
        List* p = first;
        cout << "List elements: ";
        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
}

void list_processing(List* &first)
{
    if (first != NULL)
    {
        List* p = first;
        List* q;
        bool f = false;
        while (p != NULL && !f)
        {
            if (p->data % 2 == 0 && p->prev)
            {
                q = p->prev;
                q->next = p->next;
                delete p;
                p = q;
                f = true;
            }
            else if (p->data % 2 == 0 && !p->prev)
            {
                q = p->next;
                q->prev = NULL;
                delete p;
                p = q;
                first = q;
                f = true;
            }
            p = p->next;
        }
    }
}

int main()
{
    int size;
    do
    {
        cout << "Enter size of list\n";
        cin >> size;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
            size = -1;
        }
        cin.ignore(32767, '\n');
    } while (size <= 0);
    cout << "\nManual list implementation:\n\n";
    List* l = make(size);
    print_list(l);
    list_processing(l);
    print_list(l);

    cout << "\nSTL list implementation:\n\n";
    list<int> mylist;
    

    for (int i = 0; i < size; i++)
    {
        int val;
        get_value(val, i + 1);
        mylist.push_back(val);
    }
    auto it = mylist.begin();

    cout << "List elements:";
    for (auto i = mylist.begin(); i != mylist.end(); i++)
    {
        cout << *i << " ";
    }

    while (it != mylist.end())
    {
        if (*it % 2 == 0)
        {
            mylist.erase(it);
            it = mylist.end();
        }
        else
            advance(it, 1);
    }

    cout << "\nList elements:";
    for (auto i = mylist.begin(); i != mylist.end(); i++)
    {
        cout << *i << " ";
    }
}

