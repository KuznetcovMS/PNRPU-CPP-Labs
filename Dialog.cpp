#include "Dialog.h"
#include <string>
using namespace std;

Dialog::Dialog()
{
	EndState = 0;
}

Dialog::~Dialog()
{
}

void Dialog::GetEvent(TEvent& event)
{
	string OpInt = "+-mszq";
	string s;
	string param;
	
	char code;
	cout << "m: Create group\n";
	cout << "+: Add element\n";
	cout << "-: Delete element\n";
	cout << "s: Show group elemnts\n";
	cout << "z: Show average age\n";
	cout << "q: Exit\n";
	cout << '>';
	cin >> s;
	code = s[0];
	if (OpInt.find(code) >= 0)
	{
		event.what = evMessage;
		switch (code)
		{
		case 'm': event.command = cmMake; break;
		case '+': event.command = cmAdd; break;
		case '-': event.command = cmDel; break;
		case 's': event.command = cmShow; break;
		case 'z': event.command = cmAvg; break;
		case 'q': event.command = cmQuit; break;
		}
		if (s.length() > 1)
		{
			param = s.substr(1, s.length() - 1);
			int A = atoi(param.c_str());
			event.a = A;
		}
	}
	else event.what = evNothing;
}

int Dialog::Execute()
{
	TEvent event;
	do {
		EndState = 0;
		GetEvent(event);
		HandleEvent(event);
	} while (!Valid());
	return EndState;
}

void Dialog::HandleEvent(TEvent& event)
{
	if (event.what == evMessage)
	{
		switch (event.command)
		{
		case cmMake:
			size = event.a;
			beg = new Object * [size];
			cur = 0;
			ClearEvent(event);
			break;
		case cmAdd:
			Add();
			ClearEvent(event);
			break;
		case cmDel: 
			Del();
			ClearEvent(event);
			break;
		case cmShow:
			Show();
			ClearEvent(event);
			break;
		case cmAvg:
			Avg();
			ClearEvent(event);
			break;
		case cmQuit: 
			EndExec();
			ClearEvent(event);
			break;
		}
	}
}

void Dialog::ClearEvent(TEvent& event)
{
	event.what = evNothing;
}

int Dialog::Valid()
{
	if (EndState == 0) return 0;
	else return 1;
}

void Dialog::EndExec()
{
	EndState = 1;
}
