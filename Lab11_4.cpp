#include <iostream>
#include <queue>
using namespace std;

struct Queue
{
    int data;
    Queue* next;
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

void make_qu(Queue*& front, int size)
{
    Queue* p = new Queue;
    get_value(p->data, 1);
    p->next = NULL;
    front = p; 
    for (int i = 2; i <= size; i++)
    {
        Queue* h = new Queue;
        get_value(h->data, i);
        p->next = h;
        h->next = NULL;
        p = h;
    }
}

void print_qu(Queue* fr)
{
    Queue* p = fr;
    cout << "\nQueue elements: ";
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

void queue_processing(Queue*& fr)
{
    Queue* p = fr->next;
    Queue* last = fr;
    bool f = false;
    if (last->data % 2 == 0)
    {
        fr = fr->next;
        f = true;
        delete last;
        last = NULL;
    }
    while (p != NULL && !f)
    {
        if (p->data % 2 == 0)
        {
            f = true;
            last->next = p->next;
            delete p;
            p = NULL;
            break;

        }
        last = last->next;
        p = p->next;
    }
}
int main()
{
    int size;
    do
    {
        cout << "Enter size of queue\n";
        cin >> size;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
            size = -1;
        }
        cin.ignore(32767, '\n');
    } while (size <= 0);

    cout << "\nManual queue implementation:\n\n";

    Queue* fr;
    make_qu(fr, size);
    print_qu(fr);
    queue_processing(fr);
    print_qu(fr);

    cout << "\nSTL queue implementation:\n\n";

    queue<int> qu;
    int* arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        int val;
        get_value(val, i + 1);
        qu.push(val);
    }

    cout << "Queue elements: ";
    for (int i = 0; i < size; i++)
    {
        cout << qu.front() << " ";
        arr[i] = qu.front();
        qu.pop();
    }

    for (int i = 0; i < size; i++)
    {
        qu.push(arr[i]);
    }

    queue<int> qu_b;
    bool f = false;
    while (!qu.empty())
    {
        if (qu.front() % 2 != 0)
        {
            qu_b.push(qu.front());
        }
        else if (qu.front() % 2 == 0 && !f)
                f = true;
        else if (qu.front() % 2 == 0 && f)
                qu_b.push(qu.front());
        qu.pop();
    }
    size = qu_b.size();

    cout << "\nModified queue elements: ";
    for (int i = 0; i < size; i++)
    {
        cout << qu_b.front() << " ";
        qu_b.pop();
    }
}

