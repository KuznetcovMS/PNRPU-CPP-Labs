#include <iostream>
#include <string>
#include <fstream>
using namespace std;


struct string_ex
{
    string line;
    int num_word = 0;
    int pos_max_cons = 0;
};


void read_file(ifstream &file, string_ex arr[])
{
    int ind = 0;

    while (!file.eof())
    {
        getline(file, arr[ind].line);
        ind++;
    }
}


int get_file_rows(ifstream& file)
{
    string  currentLine;
    int count = 0;

    while (!file.eof())
    {
        getline(file, currentLine);
        count++;
    }
    file.seekg(0);
    return count;
}


void print_arr(string_ex arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Row №" << i + 1 << endl;
        cout << "Row: " << arr[i].line << endl;
        cout << "Numbers of word: " << arr[i].num_word << endl;
        cout << "The word with the maximum number of consonants under the number: " << arr[i].pos_max_cons << endl << endl;
    }
    
}


bool is_char_in_string(char a, string s)
{
    int ind = 0;
    bool find = false;

    while (ind < s.length() && !find)
    {
        if (s[ind] == a)
        {
            find = true;
        }
        ind++;
    }
    return find;
}


void string_processing(string_ex s[], int size)
{
    int num_word = 0;
    int max_cons = 0;
    int cons_in_word = 0;
    int pos_max_cons = 0;

    bool word_started = false;
    string cons = "БбВвГгДдЖжЗзЙйКкЛлМмНнПпРрСсТтФфХхЦцЧчШшЩщ";

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < s[i].line.length(); j++)
        {
            if (s[i].line[j] != ' ')
            {
                if (!word_started)
                {
                    word_started = true;
                    num_word++;
                    cons_in_word = 0;
                }
                if (is_char_in_string(s[i].line[j], cons))
                {
                    cons_in_word++;
                }
               
            }
            if (s[i].line[j] == ' ' || j + 1 == s[i].line.length())
            {
                word_started = false;
                if (cons_in_word > max_cons)
                {
                    max_cons = cons_in_word;
                    pos_max_cons = num_word;
                }
            }
        }
        s[i].num_word = num_word;
        s[i].pos_max_cons = pos_max_cons;
        num_word = 0;
        max_cons = 0;
        cons_in_word = 0;
        pos_max_cons = 0;
        word_started = false;
    }
}


void write_in_file(string_ex arr[], ofstream& file, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i].num_word == 1)
        {
            file << arr[i].line << endl;
        }
    }
}
int main()
{
    system("chcp 1251>null");

    ifstream ifile("inLab9.txt");
    remove("OutLab9.txt");
    ofstream outfile("OutLab9.txt");

    
    if (ifile.is_open())
    {
        int arr_size = get_file_rows(ifile);
        string_ex* data = new string_ex[arr_size];
        read_file(ifile, data);
        string_processing(data, arr_size);
        print_arr(data, arr_size);
        write_in_file(data, outfile, arr_size);
    }
    else
    {
        cout << "File inLab9.txt not found";
    }
    ifile.close();
    outfile.close();
}