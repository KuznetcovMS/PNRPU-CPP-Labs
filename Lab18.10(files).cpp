#include <iostream>
#include "FileWork.h"
using namespace std;

int main()
{
    int command, res, key;
    string f_name;

    do
    {
        cout << "1: Make file\n";
        cout << "2: Print file\n";
        cout << "3: Delete element from file\n";
        cout << "4: Add element in file\n";
        cout << "5: Change element in file\n";
        cout << "0: Exit\n" << ">";
        cin >> command;
        cout << "\n";
        switch (command)
        {
        case 0: break;

        case 1:
            cout << "Enter file name: ";
            cin >> f_name;

            if (make_file(f_name) < 0) cout << "\nCan`t create file\n";
            break;

        case 2:
            cout << "Enter file name: ";
            cin >> f_name;

            res = print_file(f_name);
            if (res < 0) cout << "\nFile not found\n";
            else if (res == 0) cout << "\nFile is empty\n";
            break;
        case 3:
            cout << "Enter file name: ";
            cin >> f_name;
            cout << "Enter position: ";
            cin >> key;

            if (del_file(f_name, key) < 0) cout << "\nFile not found\n";
            break;
        case 4:
            cout << "Enter file name: ";
            cin >> f_name;
            cout << "Enter position: ";
            cin >> key;
            if (add_file(f_name, key) < 0) cout << "\nCan`t read file\n";
            break;
        case 5:
            cout << "Enter file name: ";
            cin >> f_name;
            cout << "Enter position: ";
            cin >> key;
            res = change_file(f_name, key);
            if (res < 0) cout << "\nFile not found\n";
            if (res == 0) cout << "\nNot such record\n";
            break;
        default: cout << "\nIncorrect command\n";
        }
    } while (command != 0);
    
}

