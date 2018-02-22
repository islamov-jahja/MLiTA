// MLiTA2.cpp: определяет точку входа для консольного приложения.
/*visual studio 2017   Исламов Яхья ПС-21
Дана шахматная доска, состоящая из N  N  клеток (2 ≤ N ≤ 300), несколько из них вырезано.
Провести ходом коня через невырезанные клетки путь минимальной длины из одной заданной
клетки в другую.(6)
*/

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;
const int SIZE = 304;

struct cell
{
	int x, y;
};
struct back 
{
	cell father;
};

struct block
{
	cell father;
	cell itself;
};

void AddToQueue(block[SIZE], int*, bool*, char[SIZE][SIZE], int, int, int, int, back[SIZE][SIZE]);

int main()
{
	int numberOfLines;
	ifstream inFile("input.txt");
	ofstream outFile("output.txt");
	inFile >> numberOfLines;
	char arr[SIZE][SIZE];
	char resultArr[SIZE][SIZE];
	block queue[SIZE*18];
	back vozvrat[SIZE][SIZE];
	int Top = 0;
	bool good = true;
	for (int i = 0; i < (numberOfLines + 4); i++)            //инициализация
		for (int j = 0; j < (numberOfLines + 4); j++)
		{
			if (i == 0 || i == 1 || i == (numberOfLines + 3) || i == (numberOfLines + 2) || j == 0 || j == 1 || j == (numberOfLines + 3) || j == (numberOfLines + 2))
			{
				arr[i][j] = '#';
			}
			else
			{
				inFile >> arr[i][j];
				if ((arr[i][j] == '@') && (good))
				{
					queue[Top].father.x = -1;
					queue[Top].father.y = -1;
					vozvrat[i][j].father.x = i;
					vozvrat[i][j].father.y = j;
					queue[Top].itself.x = i;
					queue[Top].itself.y = j;
					good = false;
				}
				else if (arr[i][j] == '#')
					resultArr[i - 2][j - 2] = '#';
			}
			resultArr[i][j] = '.';

		}
	arr[queue[Top].itself.x][queue[Top].itself.y] = '#';
	bool impossible = true;
	bool notFound = true;
	int index = 0, x, y;
	while (notFound)
	{
		impossible = true;
		x = queue[index].itself.x;
		y = queue[index].itself.y;
		index += 1;
		if (arr[x - 1][y + 2] != '#')
		{
			AddToQueue(queue, &Top, &notFound, arr, x, y, -1, 2, vozvrat);
			if (!notFound)
				break;
			impossible = false;
		}
		if (arr[x - 1][y - 2] != '#')
		{
			AddToQueue(queue, &Top, &notFound, arr, x, y, -1, -2, vozvrat);
			if (!notFound)
				break;
			impossible = false;
		}
		if (arr[x + 1][y + 2] != '#')
		{
			AddToQueue(queue, &Top, &notFound, arr, x, y, 1, 2, vozvrat);
			if (!notFound)
				break;
			impossible = false;
		}
		if (arr[x + 1][y - 2] != '#')
		{
			AddToQueue(queue, &Top, &notFound, arr, x, y, 1, -2, vozvrat);
			if (!notFound)
				break;
			impossible = false;
		}
		if (arr[x - 2][y + 1] != '#')
		{
			AddToQueue(queue, &Top, &notFound, arr, x, y, -2, 1, vozvrat);
			if (!notFound)
				break;
			impossible = false;
		}
		if (arr[x - 2][y - 1] != '#')
		{
			AddToQueue(queue, &Top, &notFound, arr, x, y, -2, -1, vozvrat);
			if (!notFound)
				break;
			impossible = false;
		}
		if (arr[x + 2][y + 1] != '#')
		{
			AddToQueue(queue, &Top, &notFound, arr, x, y, 2, 1, vozvrat);
			if (!notFound)
				break;
			impossible = false;
		}
		if (arr[x + 2][y - 1] != '#')
		{
			AddToQueue(queue, &Top, &notFound, arr, x, y, 2, -1, vozvrat);
			if (!notFound)
				break;
			impossible = false;
		}
		if (impossible && index == Top)
		{
			outFile << "Impossible";
			return 1;
		}
	}

	int m, n, f, s;
	m = queue[Top].itself.x;
	n = queue[Top].itself.y;
	f = -3;
	s = -3;
	bool notEnd = true;
	while (notEnd)
	{
		resultArr[m - 2][n - 2] = '@';
		if ((vozvrat[m][n].father.x == m) && (vozvrat[m][n].father.y == n))
		{
			break;
		}
		f = vozvrat[m][n].father.x;
		s = vozvrat[m][n].father.y;
		m = f;
		n = s;
	}

	for (int i = 0; i < numberOfLines; i++)
	{
		for (int j = 0; j < numberOfLines; j++)
			outFile << resultArr[i][j];
		outFile << endl;
	}

    return 0;
}

void AddToQueue(block queue[SIZE], int* Top, bool* notFound, char arr[SIZE][SIZE], int x, int y, int m, int n, back vozvrat[SIZE][SIZE])
{
	*Top += 1;
	if (x < 0 || y < 0)
		*notFound = false;
	if (arr[x + m][y + n] == '@')
		*notFound = false;
	arr[x + m][y + n] = '#';
	vozvrat[x + m][y + n].father.x = x;
	vozvrat[x + m][y + n].father.y = y;
	queue[*Top].itself.x = x + m;
	queue[*Top].itself.y = y + n;
	queue[*Top].father.x = x;
	queue[*Top].father.y = y;
}
