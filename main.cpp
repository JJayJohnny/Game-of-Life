#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#define Y 25
#define X 72

using namespace std;

//int wake[] = { 3 };
//int live[] = { 2, 3 };

void fill(char tab[Y][X], char znak)
{
	for (int i = 0; i < Y; i++)
		for (int j = 0; j < X; j++)
			tab[i][j] = znak;
}

void display(char tab[Y][X])
{
	for (int i = 1; i < Y-1; i++)
	{
		for (int j = 1; j < X-1; j++)
		{
			cout << tab[i][j];
		}
		cout << endl;
	}
}

void rewrite(char from[Y][X], char to[Y][X])
{
	for (int i = 0; i < Y; i++)
	{
		for (int j = 0; j < X; j++)
		{
			to[i][j] = from[i][j];
		}
	}
}

void step(char tab[Y][X])
{
	char next[Y][X];
	fill(next, ' ');
	for (int i = 1; i < Y-1; i++)
	{
		for (int j = 1; j < X - 1; j++)
		{
			int neighbours = 0;
			if (tab[i - 1][j - 1] == '*') neighbours++;
			if (tab[i][j - 1] == '*') neighbours++;
			if (tab[i + 1][j - 1] == '*') neighbours++;
			if (tab[i - 1][j] == '*') neighbours++;
			if (tab[i + 1][j] == '*') neighbours++;
			if (tab[i - 1][j+1] == '*') neighbours++;
			if (tab[i][j+1] == '*') neighbours++;
			if (tab[i+1][j+1] == '*') neighbours++;

			if (tab[i][j] == ' ' && neighbours == 3 )
				next[i][j] = '*';
			
			if (tab[i][j] == '*' && (neighbours==2 || neighbours == 3))
				next[i][j] = '*';
		}
	}

	rewrite(next, tab);
	system("CLS");
	display(tab);
	//Sleep(100);
	//step(tab);
}

void setup(char tab[Y][X])
{
	srand(time(NULL));
	for (int i = 0; i < 300; i++)
	{
		int x = rand()%(X-2);
		int y = rand()%(Y-2);
		tab[1 + y][1 + x] = '*';
	}
}

int main()
{
	char tab[Y][X];
	fill(tab, ' ');

	setup(tab);
	display(tab);
	Sleep(3000);

	for (; ;)
	{
		step(tab);
		Sleep(50);
	}
	return 0;
}