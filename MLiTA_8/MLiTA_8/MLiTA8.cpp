
#include "stdafx.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <set>
using namespace std;

void PrintGrayWord(vector<char> grayArr, int count);
bool isSet(vector<char> mySet, int counInSet);
void OutSet();
void OutGray(vector<char> grayArr, int count, int depth);
int main()
{
	vector<char> grayArr(2, 0);
	char action = '0';
	int count;

	while (action != '3')
	{
		grayArr[0] = '0';
		grayArr[1] = '1';
		cout << "Please, choose the action what you want" << endl;
		cout << "1. give out the words of the gray code" << endl;
		cout << "2. give out subsets of a set" << endl;
		cout << "3. exit" << endl;
	    cin >> action;
		if (action == '1')
		{
			cout << "enter the desired word order" << endl;
			cin >> count;
			cin.clear();
			OutGray(grayArr, count, 1);
		}
		else if (action == '2')
			OutSet();
	}
	
}

void OutSet()
{
	int countInSet;
	int order = 0;
	int indexSet = 0;
	cout << "Enter count of elements in Set" << endl;
	cin >> countInSet;
	vector<char> mySet(countInSet+1);
	if (countInSet != 0)
	{
		cout << "enter the set" << endl;

		while (cin && indexSet < countInSet)
		{
			cin >> mySet[indexSet];
			indexSet++;
		}
        
		if (!isSet(mySet, countInSet))
		{
			cout << "you entered incorrect data. set can not contain the same elements" << endl;
			return;
		}

		cin.clear();
		cout << "enter the order" << endl;
		cin >> order;
		sort(mySet.begin(), mySet.begin() + countInSet);
	}
	string lineOnSet;
	string reservLine;
	set<string> chekSet;
	if (order > 1 && countInSet != 0)
		for (size_t i = 0; i < (countInSet - order + 1); i++)
		{
			for (size_t j = i + 1; j < countInSet; j++)
			{
				lineOnSet.clear();
				lineOnSet += mySet[i];
				if (order != 2)
					lineOnSet += mySet[j];
				for (size_t f = j + 1; f < (j + (order - 2)); f++)
				{
					lineOnSet += mySet[f];
				}
				for (size_t k = (j + (order - 2)); k < countInSet; k++)
				{
					reservLine = lineOnSet;
					reservLine += mySet[k];
					if (chekSet.find(reservLine) == chekSet.end())
						cout << reservLine << endl;
					chekSet.insert(reservLine);
				}
			}
		}
	else if (order == 1 && countInSet != 0)
		for (size_t i = 0; i < countInSet; i++)
			cout << mySet[i] << endl;
}

void OutGray(vector<char> grayArr, int count, int depth)
{
	if (depth < count)
	{
		int indexGrayArrFunc = 0;
		int indexGrayArr = 0;
		cout << depth << " Gray Word" << endl;
		PrintGrayWord(grayArr, depth);
		int koef1 = pow(2, depth)*depth;
		int koef = pow(2, depth + 1)*(depth+1);
		vector<char> grayArrFunc(koef + 1, 0);

		while(indexGrayArr < koef1)
		{
			grayArrFunc[indexGrayArrFunc] = '0';
			indexGrayArrFunc++;

			for (size_t j = 0; j < depth; j++)
			{
				grayArrFunc[indexGrayArrFunc] = grayArr[indexGrayArr];
				indexGrayArr++;
				indexGrayArrFunc++;
			}
		}

		indexGrayArr = koef1 - 1;

		while (indexGrayArr >= 0)
		{
			grayArrFunc[indexGrayArrFunc] = '1';
			indexGrayArrFunc++;
			indexGrayArr -= depth;
			for (size_t j = 0; j < depth; j++)
			{
				grayArrFunc[indexGrayArrFunc] = grayArr[indexGrayArr+(j+1)];
				indexGrayArrFunc++;
			}
		}
        
		OutGray(grayArrFunc, count, depth + 1);
	}
	else
	{
		cout << count << " Gray Word" << endl;
		PrintGrayWord(grayArr, count);
		return;
	}
}

bool isSet(vector<char> mySet, int counInSet)
{
	for (size_t i = 0; i < counInSet; i++)
		for (size_t j = i+1; j < counInSet; j++)
			if (mySet[i] == mySet[j])
				return (false);
	return (true);
}

void PrintGrayWord(vector<char> grayArr, int count)
{
	for (size_t i = 0; i < pow(2, count)*count; i++)
	{
		cout << grayArr[i] << ' ';
		if ((i + 1) % count == 0)
			cout << endl;
	}
}