// MLiTAPraktika10.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
using namespace std;

void SearchRoad(int count, int& resultCount, int i, int j, vector<vector<char>>& field, int m, int n);
int main()
{
	int m, n;
	int resultCount = 0;
	ifstream inFile("input.txt");
	ofstream outFile("output.txt");
	inFile >> m >> n;
	vector<vector<char>> field((m), vector<char>(n));
	vector<vector<char>> reserveField((m), vector<char>(n));

	for (size_t i = 0; i < m; i++)
		for (size_t j = 0; j < n; j++)
			inFile >> field[i][j];

	reserveField = field;
    
	for (size_t i = 0; i < m; i++)
		for (size_t j = 0; j < n; j++)
			if (field[i][j] == '#')
			{
				SearchRoad(1, resultCount, i, j, field, m, n);
				field = reserveField;
			}

	cout << resultCount - 1;
	system("pause");
    return 0;
}

void SearchRoad(int count, int& resultCount, int i, int j, vector<vector<char>>& field, int m, int n)
{
	if (count > resultCount)
		resultCount = count;

	if (j + 1 < n)
		if (field[i][j + 1] == '#')
		{
			count++;
			field[i][j + 1] = '.';
			SearchRoad(count, resultCount, i, j + 1, field, m, n);
		}

	if (j - 1 >= 0)
		if (field[i][j - 1] == '#')
		{
			count++;
			field[i][j - 1] = '.';
			SearchRoad(count, resultCount, i, j - 1, field, m, n);
		}

	if (i - 1 >= 0)
		if (field[i - 1][j] == '#')
		{
			field[i - 1][j] = '.';
			count++;
			SearchRoad(count, resultCount, i - 1, j, field, m, n);
		}

	if (i + 1 < m)
		if (field[i+1][j] == '#')
		{
			field[i + 1][j] = '.';
			count++;
			SearchRoad(count, resultCount, i + 1, j, field, m, n);
		}
}

