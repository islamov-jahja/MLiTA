// AISDPraktika2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
const int MAX = 100;
int main()
{
	ifstream InFile("input.txt");
	ofstream OutFile("output.txt");
	int pole[MAX][MAX];
	int m, n;
	InFile >> m;
	InFile >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			InFile >> pole[i][j];
	for (int i = m; i >= 0; i--)
		for (int j = n; j >= 0; j--)
			if (i == m-1 && j == n-1)
				continue;
			else
			if (i == m-1)
				pole[i][j] += pole[i][j + 1];
			else
				if (j == n-1)
					pole[i][j] += pole[i + 1][j];
				else
				{
					if (pole[i][j + 1] < pole[i + 1][j])
						pole[i][j] = pole[i][j] + pole[i][j + 1];
					else
						pole[i][j] = pole[i][j] + pole[i + 1][j];
				}
	int i = 0, j = 0;
	OutFile << pole[0][0] << endl;
	while (i < m && j < n)
	{
	    OutFile << i+1 << ' ' << j+1 << endl;
		if (i == m)
		{
			j = j + 1;
		}
		else
			if (i == n - 1)
				i = i + 1;
			else
		      if (pole[i][j + 1] < pole[i + 1][j])
		      {
			    j = j + 1;
		      }
			  else
			  {
				  i = i + 1;
			  }
	}
    return 0;
}

