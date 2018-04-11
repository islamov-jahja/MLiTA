// MLiTA7.cpp: определяет точку входа для консольного приложения.
//Исламов Яхья ПС-21
/*12.1. Дороги Прима (5)
В государстве Прим имеется ряд населенных пунктов, связанных грунтовыми дорогами.
Между любыми двумя пунктами может быть не более одной дороги. Решено заасфальтировать
некоторые дороги. Стоимость асфальтирования каждой дороги известна. Требуется выбрать
дороги для асфальтирования так, чтобы можно было проехать из каждого населенного пункта в
любой другой по асфальту, а общая стоимость работы была минимальной. Использовать алгоритм
Прима.*/

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
const int NO_WAY = 1000000;

struct Rib{
	int from;
	int sum;
};

struct SortCoord{
	int x;
	int y;
};

bool comp2(SortCoord a, SortCoord b) { return a.x < b.x; }
int main()
{
	ifstream inFile("input.txt");
	ofstream outFile("output.txt");
	int sizeOfMatrix;
	int countOfRibs;
	inFile >> sizeOfMatrix;
	inFile >> countOfRibs;
	vector<vector<int>> Matrix((sizeOfMatrix + 1, NO_WAY), vector<int>(sizeOfMatrix + 1, NO_WAY));
	vector<Rib> ribs(sizeOfMatrix + 1, {0, NO_WAY});
	bool endCycle = false;
	int lastRib = 0;

	for (size_t i = 0; i < countOfRibs; i++)
	{
		int k, l, cost;
		inFile >> k >> l >> cost;
		Matrix[k][l] = cost;
		Matrix[l][k] = cost;
	}

	set<int> traversedEdges;
	traversedEdges.insert(1);
	lastRib = 1;

	while (!endCycle)
	{
		if (traversedEdges.size() == sizeOfMatrix)
			endCycle = true;

		for (size_t j = 1; j <= sizeOfMatrix; j++)
			if (Matrix[lastRib][j] < ribs[j].sum && lastRib != j && traversedEdges.find(j) == traversedEdges.end())
			{
				ribs[j].from = lastRib;
				ribs[j].sum = Matrix[lastRib][j];
			}

		int min = NO_WAY;
		for (size_t j = 1; j <= sizeOfMatrix; j++)
			if (ribs[j].sum < min && traversedEdges.find(j) == traversedEdges.end())
			{
				min = ribs[j].sum;
				lastRib = j;
			}

		traversedEdges.insert(lastRib);
	}

	int allSum = 0;
	for (size_t i = 2; i <= sizeOfMatrix; i++)
		allSum += ribs[i].sum;

	outFile << allSum << endl;

	
	vector<SortCoord> resultArr(sizeOfMatrix - 1);
	lastRib = 0;
	for (size_t i = 2; i <= sizeOfMatrix; i++)
		if (ribs[i].from < i)
		{
			resultArr[lastRib].x = ribs[i].from;
			resultArr[lastRib].y = i;
			lastRib++;
		}
		else
		{
			resultArr[lastRib].x = i;
			resultArr[lastRib].y = ribs[i].from;
			lastRib++;
		}

	sort(resultArr.begin(), resultArr.end(), comp2);
	for (auto x : resultArr)
		if (x.x != 0 && x.y != 0)
		    outFile << x.x << ' ' << x.y << endl;
    return 0;
}

