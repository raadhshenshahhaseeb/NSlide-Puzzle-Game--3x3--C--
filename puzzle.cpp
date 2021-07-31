#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <chrono>
#include <array>
using namespace std;

const short unsigned int Keyleft = 37;
const short unsigned int Keytop = 38;
const short unsigned int Keyright = 39;
const short unsigned int Keydown = 40;
const short unsigned int Keyexit = 81;

// NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE

// IN DEV C++ GO TO TOOLS->COMPILER OPTIONS->GENERAL-> AND ADD THE FOLLOWING STATEMENT WOTHOUT BRACKETS INTO
// ADD THE FOLLOWING COMMANDS WHEN CALLING COMPILER BOX => [-std=c++11 -std=gnu++11 ] OR THE PROGRAM WILL NOT RUN
// Anyone using a different IDE from Dev C++ please check that through google.

class Game
{
public:
	int *shuffle_arr();
	int startGame(int board[3][3]);
	int getKey();
	int showBoard(int board[3][3]);
	int board();
	int checkWin(int board[3][3]);
	int checkWinDummy();
};

int Game::checkWinDummy()
{
	int arr[3][3];
	int k = 0, check = 0;
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			arr[i][j] = k;
			++k;
		}
	}

	check = this->checkWin(arr);
	if (check == 0)
	{
		this->showBoard(arr);
	}
	else
	{
		system("cls");
		cout << "0    1    2\n3    4    5\n6    7    8\n\nSolution to Win";
		cout << "\n\n\nPerfectly Running- Conditions Checked";
		system("pause");
		system("exit");
	}
}

int Game::checkWin(int board[3][3])
{
	int arr[3][3], k = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			arr[i][j] = k;
			++k;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (k == 6)
		{
			return 1;
		}
		for (int j = 0; j < 3; j++)
		{
			if (arr[i][j] != board[i][j])
			{
				return 0;
			}
			else
			{
				++k;
			}
		}
	}
}

int *Game::shuffle_arr()
{
	int num = 0;
	std::array<int,9> shuff {1, 2, 3, 4, 5, 6, 7, 8, 0};
	static int _shuff[9];
	 // obtain a time-based seed:
  	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

  	shuffle (shuff.begin(), shuff.end(), std::default_random_engine(seed));

  	std::cout << "shuffled elements:";
  	for (int& x: shuff) {
		std::cout << ' ' << x;
  		std::cout << '\n';
		_shuff[num] = x;
		}
	return _shuff;
}

int Game::board()
{
	int board[3][3], numG = 0, temp = 0, i = 0, check = 0;
	int *p = shuffle_arr();

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = *(p + (numG++));
		}
	}
	check = this->checkWin(board);
	if (check == 0)
	{
		this->showBoard(board);
	}
	else
	{
		system("cls");
		cout << "\n\n\nYOU WIN";
		system("pause");
		system("exit");
	}
}
int Game::showBoard(int board[3][3])
{
	int numG = 0, temp = 0, i = 0;
	system("cls");

	cout << "\n\n\n\n";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << board[i][j] << "		";
		}
		cout << "\n\n\n\n\n\n\n\n";
	}
	this->startGame(board);
}

int Game::startGame(int board1[3][3])
{
	int a;
	int i = 0, j = 0, p, q, temp, x;
	for (p = 0; p < 3; p++)
	{
		for (int q = 0; q < 3; q++)
		{
			if (board1[p][q] == 0)
			{
				i = p;
				j = q;
			}
		}
	}

	while (a != 113 || a != 81)
	{
		a = getchar();
		x = getKey();
		if (a == 0 || a == 0xE0)
		{
			a = getchar();
		}

		else
		{

			//For Moving to Right
			if (a == 68 || a == 100 || x == 39)
			{
				if (j == 0)
				{
					cout << "\nNo more possible moves towards Right\n"
						 << endl;
				}
				else
				{
					j--; //moves the zero around
					swap(board1[i][j], board1[i][j + 1]);
					this->showBoard(board1);
				}
			}
			//For Moving to Left
			if (a == 97 || a == 65 || x == 37)
			{
				if (j == 2)
				{
					cout << "\nNo more possible moves towards Left\n"
						 << endl;
				}
				else
				{
					j - 2; //moves the zero around
					swap(board1[i][j], board1[i][j + 1]);
					this->showBoard(board1);
				}
			}
			//For moving Up
			if (a == 83 || a == 115 || x == 40)
			{
				if (i == 0)
				{
					cout << "\nNo more possible moves towards Down\n"
						 << endl;
				}
				else
				{
					i--;
					//moves the zero around
					swap(board1[i + 1][j], board1[i][j]);
					this->showBoard(board1);
				}
			}
			if (a == 87 || a == 119 || x == 38)
			{
				if (i == 2)
				{
					cout << "\nNo more possible moves towards Up\n"
						 << endl;
				}
				else
				{
					i - 2;
					//moves the zero around
					swap(board1[i + 1][j], board1[i][j]);
					this->showBoard(board1);
				}
			}
		}
	}
}

int Game::getKey()
{
	while (true)
	{
		for (int i = 8; i <= 256; i++)
		{
			if (GetAsyncKeyState(i) & 0x7FFF)
			{
				// WWW.RAADH.COM	WWW.RAADH.COM	WWW.RAADH.COM	WWW.RAADH.COM	WWW.RAADH.COM	WWW.RAADH.COM
				// This if filters the keys, i want to allow direction arrows
				// and q for quit. If you want to add more just add the code for the key,
				// to know the key code just coment the if line and print the keycode.
				if ((i >= 37 && i <= 40) || i == 81)
					return i;
			}
		}
	}
}

int main()
{
	Game g;
	int choice = 1;
	cout << "Welcome to N Slide Puzzle Game\n\n\n";
	cout << "Press 1 to Play\nPress 2 to Check Dummy Win and its Solution\nPress any other key to quit to Quit\n";
	cin >> choice;
	cout << endl;
	switch (choice)
	{
	case 1:
		g.board();
		break;
	case 2:
		g.checkWinDummy();
		break;
	default:
		exit(1);
	}

	return 1;
}
