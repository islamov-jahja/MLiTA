// Mlitapraktika6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
const int SIZE = 10;

int main()
{
	vector<int> myArr(10);
	int countSSS = 0;
	int minElIndex = -1;
	int saveNumber = 0;
	int minEl = 99999999;
	int count = 0;
	int countOfPer = 0;
	vector<int> numbers(SIZE);
	bool good = false;
	while (cin)
	{
		cin >> numbers[count];
		count++;
	}
	count -= 2;
	while (countOfPer < 5)
	{
		for (size_t i = count - 1; i >= 0; i--)
			if (numbers[i] < numbers[i + 1])
			{
				good = true;
				for (size_t j = i; j <= count; j++)
				{
					if (numbers[j] > numbers[i] && numbers[j] < minEl)
					{
						minEl = numbers[j];
						minElIndex = j;
					}
					if (j == count)
					{
						saveNumber = numbers[i];
						numbers[i] = numbers[minElIndex];
						numbers[minElIndex] = saveNumber;
						if (i + 1 != count)
						{
							for (size_t k = i + 1; k <= count; k++)
							{
								myArr[countSSS] = numbers[k];
								countSSS++;
							}
							countSSS--;
							for (size_t k = i + 1; k <= count; k++)
							{
								numbers[k] = myArr[countSSS];
								countSSS--;
							}
							countSSS = 0;
						}
					}
				}
				minEl = 99999999;
				break;
			}
		if (good)
		{
			for (size_t i = 0; i <= count; i++)
				cout << numbers[i] << ' ';
			cout << endl;
			good = false;
		}
		if (!good)
			break;
		countOfPer++;
	}
	system("pause");
    return 0;
}

void OutLeksPor(vector<char> numbers, int allCount, int& countInProcess)
{
	int count = numbers.size() - 1;
	vector<int> myArr(100);
	bool good = false;
	int minElIndex = -1;
	int saveNumber = 0;
	long long int minEl = 9999999;
	int countSSS = 0;
	while (countInProcess < allCount)
	{
		for (size_t i = 0; i <= count - 1; i++)
			if (numbers[i] < numbers[i + 1])
				good = true;

		if (!good)
			break;
		for (size_t i = count - 1; i >= 0; i--)
			if (numbers[i] < numbers[i + 1])
			{
				for (size_t j = i; j <= count; j++)
				{
					if (numbers[j] > numbers[i] && numbers[j] < minEl)
					{
						minEl = numbers[j];
						minElIndex = j;
					}
					if (j == count)
					{
						saveNumber = numbers[i];
						numbers[i] = numbers[minElIndex];
						numbers[minElIndex] = saveNumber;
						if (i + 1 != count)
						{
							for (size_t k = i + 1; k <= count; k++)
							{
								myArr[countSSS] = numbers[k];
								countSSS++;
							}
							countSSS--;
							for (size_t k = i + 1; k <= count; k++)
							{
								numbers[k] = myArr[countSSS];
								countSSS--;
							}
							countSSS = 0;
						}
					}
				}
				minEl = 99999999;
				break;
			}
		if (good)
		{
			for (size_t i = 0; i <= count; i++)
				cout << numbers[i] << ' ';
			cout << endl;
		}
		good = false;
		countInProcess++;
	}
}

