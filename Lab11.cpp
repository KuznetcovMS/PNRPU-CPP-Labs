#include <iostream>
using namespace std;


struct List
{
    double data;
    List* next;
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

List* make_list(int size)
{
    if (size <= 0)
    {
        cout << "Incorrect list size\n";
        return 0;
    }

    List* first, *p;
    first = NULL;
    p = new List;
    get_value(p->data, 1);
    first = p;
    first->next = NULL;
    for (int i = 2; i <= size; i++)
    {
        List* h = new List;
        p->next = h;
        p = p->next;
        get_value(p->data, i);
        p->next = NULL;
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
            cout << p->data << "; ";
            p = p->next;
        }
        cout << endl;
    }
}

void list_processing(List* first)
{
    if (first != NULL)
    {
        List* p = first;
        while (p != NULL)
        {
            if (p->data < 0.0)
            {
                List* z = new List;
                z->data = 0.0;
                z->next = p->next;
                p->next = z;
                p = p->next;
            }
            p = p->next;
        }
    }
}

void delete_list(List* first)
{
    if (first != NULL)
    {
        List* p = first;
        while (p != NULL)
        {
            List* q = p;
            p = p->next;
            delete q;
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
    } while (size < 0);

   List* l = make_list(size);
   print_list(l);
   list_processing(l);
   print_list(l);
   delete_list(l);
   return 0;
}

