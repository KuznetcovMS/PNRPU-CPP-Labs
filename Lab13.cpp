#include <iostream>
using namespace std;
int board[8][8];

void print_res()
{
	for (int i = 0; i < 8; i++)
	{ 
		for (int j = 0; j < 8; j++)
		{
			if (board[i][j] == -1) cout << "Q  ";  
			else if (board[i][j] != 0)cout << "B  ";  
			else cout << "*  ";
		}
		cout << endl << endl;
	}
	cout << endl << endl;
}
void set_queen(int i, int j) {

	for (int x = 0; x < 8; ++x)
	{
		board[x][j]++; 
		board[i][x]++;  
		int foo;
		foo = j - i + x; 
		if (foo >= 0 && foo < 8)
			board[x][foo]++;
		foo = j + i - x;

		if (foo >= 0 && foo < 8)
			board[x][foo]++;

		board[i][j] = -1; 
	}
	print_res();
}


void reset_queen(int i, int j) {

	for (int x = 0; x < 8; x++)
	{
		board[x][j]--;  
		board[i][x]--; 
		int foo; 
		foo = j - i + x;
		if (foo >= 0 && foo < 8)
			board[x][foo]--;
		foo = j + i - x;

		if (foo >= 0 && foo < 8)
			board[x][foo]--;

		board[i][j] = 0; 
	}
}

bool try_queen(int i) { 

	bool result = false; 

	for (int j = 0; j < 8; ++j) 
	{

		if (board[i][j] == 0) 
		{
			set_queen(i, j); 

			if (i == 7) 
				result = true; 

			else if (!(result = try_queen(i + 1))) reset_queen(i, j); 
		}

		if (result) j = 8;


	}

	return result;
}

int main()
{
	for (int i = 0; i < 8; ++i) 
		for (int j = 0; j < 8; ++j)
			board[i][j] = 0;
	try_queen(0);
}
