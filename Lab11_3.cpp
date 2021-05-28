#include <iostream>
#include <stack>
using namespace std;

struct Stack
{
    double data;
    Stack* prev;
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

Stack* make_stack(int size)
{
    Stack* top, * p;
    top = 0;
    p = new Stack;
    get_value(p->data, 1);
    p->prev = NULL;
    top = p;
    for (int i = 2; i <= size; i++)
    {
        Stack* h = new Stack;
        get_value(h->data, i);
        h->prev = top;
        top = h;
    }
    return top;
}

void print_st(Stack* top)
{
    if (top != NULL)
    {
        Stack* p = top;
        cout << "Stack elements: ";
        while (p != NULL)
        {
            cout << p->data << "; ";
            p = p->prev;
        }
        cout << endl;
    }
}

double pop(Stack*& top)
{
    Stack* p = top;
    int num = 0;
    while (p != NULL)
    {
        num++;
        p = p->prev;
    }
    p = top;
    if (num == 1)
    {
        double d = top->data;
        delete p;
        top = NULL;
        return d;
    }
    else
    {
        Stack* t = p->prev;
        double d = p->data;
        top = t;
        delete p;
        return d;
    }
}

void push(Stack*& top, double val)
{
    if (top != NULL)
    {
        Stack* p = new Stack;
        p->data = val;
        p->prev = top;
        top = p;
    }
    else
    {
        Stack* p = new Stack;
        p->data = val;
        p->prev = NULL;
        top = p;
    }
    
}

void stack_processing(Stack* &top)
{
    Stack* st2 = NULL;
    Stack* p = top;
    while (p != NULL)
    {
        if (p->data < 0)
        {
            push(st2, pop(p));
            push(st2, 0);
        }
        else
        {
            push(st2, pop(p));
        }
    }
    top = NULL; 
    p = st2;
    while (p != NULL)
    {
        push(top, pop(p));
    }

}

int main()
{
    int size;
    do
    {
        cout << "Enter size of stack\n";
        cin >> size;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
            size = -1;
        }
        cin.ignore(32767, '\n');
    } while (size <= 0);
    cout << "\nManual stack implementation:\n\n";

    Stack* st = make_stack(size);
    print_st(st);
    stack_processing(st);
    print_st(st);

    cout << "\nSTL stack implementation:\n\n";

    stack<double> sta;
    for (int i = 0; i < size; i++)
    {
        double val;
        get_value(val, i + 1);
        sta.push(val);
    }

    cout << "Stack elements: ";
    stack<double> st_buf;
    for (unsigned int i = 0; i < size; i++)
    {
        cout << sta.top() << " ";
        if (sta.top() < 0)
        {
            st_buf.push(sta.top());
            st_buf.push(0);
        }
        else
        {
            st_buf.push(sta.top());
        }
        sta.pop();
    }
    size = st_buf.size();
    for (int i = 0; i < size; i++)
    {
        sta.push(st_buf.top());
        st_buf.pop();
    }

    cout << "\nModified stack: ";
    for (int i = 0; i < size; i++)
    {
        cout << sta.top() << " ";
        sta.pop();
    }
}

