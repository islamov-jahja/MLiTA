// MLiTAPraktika9.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;


int main()
{
	ifstream inFile("input.txt");
	ofstream outFile("output.txt");
	int countOfRequirement = 0;
	int countOfDoctor = 0;
	inFile >> countOfDoctor;
	int indexX = 0;
	vector<vector<int>> Matrix((countOfDoctor + 1), vector<int>(countOfDoctor+1));
	vector<vector<int>> MatrixReserve((countOfDoctor + 1), vector<int>(countOfDoctor + 1));
	bool checkForEnd = false;
	const int SIZE_ARR_DOCTOR = 100;
	bool checker = true;
	bool checkOfZero = true;

	for (size_t i = 1; i <= countOfDoctor; i++)
	{
		inFile >> countOfRequirement;
		if (countOfRequirement == 0)
			checkForEnd = true;
		for (size_t j = 0; j < countOfRequirement; j++)
		{
			inFile >> indexX;
			Matrix[i][indexX] = 1;
		}
	}

	for (int i = 1; i <= countOfDoctor; i++)
	{
		for (int j = 1; j <= countOfDoctor; j++)
			cout << Matrix[i][j] << ' ';
		cout << endl;
	}

	bool isEquality = false;
	vector<int> arrOfDoctors(countOfDoctor);
	int counter = 0;

	if (checkForEnd == false)
	{
		outFile << "No";
		return 0;
	}
	else
	{
		while (checker)
		{
			for (size_t i = 1; i <= countOfDoctor; i++)
				for (size_t j = 1; j <= countOfDoctor; j++)
					MatrixReserve[i][j] = Matrix[i][j];

			for (size_t i = 1; i <= countOfDoctor; i++)       //нахождение нулевых строк
			{
				for (size_t j = 1; j <= countOfDoctor; j++)
					if (Matrix[i][j] == 1)
						checkOfZero = false;

				if (checkOfZero)
				{

					for (size_t k = 0; k < arrOfDoctors.size(); k++)
					{
						if (arrOfDoctors[k] == i)
							isEquality = true;
					}

					if (!isEquality)
						arrOfDoctors.push_back(i);
					isEquality = false;
				}
				checkOfZero = true;
			}
			//
			for (size_t i = 1; i <= countOfDoctor; i++)
				for (size_t j = 1; j <= countOfDoctor; j++)
					if (Matrix[i][j] == 1)
					{
						for (size_t k = 0; k < arrOfDoctors.size(); k++)
							if (j == arrOfDoctors[k])
								Matrix[i][j] = 0;
					}

			for (size_t i = 1; i <= countOfDoctor; i++)
				for (size_t j = 1; j <= countOfDoctor; j++)
					if (Matrix[i][j] != MatrixReserve[i][j])
						checker = false;

			if (checker == true)
			{
				for (auto x : arrOfDoctors)
					if (x != 0)
						counter++;
				if (countOfDoctor == counter)
				{
					outFile << "Yes" << endl;
					for (auto x : arrOfDoctors)
						if (x != 0)
						    outFile << x << endl;
					return 0;
				}
				else
				{
					outFile << "No";
					return 0;
				}

			}
			
			checker = true;
		}
	}
	system("pause");
    return 0;
}

