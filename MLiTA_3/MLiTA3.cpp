// MLiTA.cpp: определяет точку входа для консольного приложения.
//Исламов Яхья ПС-21 VS 2017
/*3.1. Заяц (5)
Имеется лестница, состоящая из N ступенек. При подъеме по лестнице заяц может прыгать на
любое количество ступенек от 1 до K. Сколько у зайца способов подъема по лестнице?
Ввод из файла INPUT.TXT. Единственная строка содержит целые положительные числа N и K.
Вывод в файл OUTPUT.TXT. Выводится единственное число - количество способов подъема
по лестнице.*/

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

const int SIZE = 100;

struct num
{
	int byteNum[SIZE];
};


num GetSumOfLongNumber(num, num);
int Len(num);
int main()
{
	ifstream inFile("input.txt");
	ofstream outFile("output.txt");
	int countOfStep = 0;
	int oneTimeJump = 0;
	inFile >> countOfStep;
	inFile >> oneTimeJump;
	num arrOfStep[SIZE];
	num number;
	int indexOfEndNumber = 0;

	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			arrOfStep[i].byteNum[j] = 0;
	
	arrOfStep[1].byteNum[0] = 1;

	for (int i = 2; i <= countOfStep; i++)
	{
		if (i - oneTimeJump > 0)
		{
			for (int j = oneTimeJump; j > 0; j--)
			{
				arrOfStep[i] = GetSumOfLongNumber(arrOfStep[i], arrOfStep[i - j]);
			}
		}
		else
		{
			arrOfStep[i].byteNum[0] = 1;
			for (int k = 1; k < i; k++)
				arrOfStep[i] = GetSumOfLongNumber(arrOfStep[i], arrOfStep[k]);
		}
	}

	indexOfEndNumber = Len(arrOfStep[countOfStep]);

	if (indexOfEndNumber != 0)
		for (int i = indexOfEndNumber; i >= 0; i--)
			outFile << arrOfStep[countOfStep].byteNum[i];
	else
		outFile << 0;

    return 0;
}


num GetSumOfLongNumber(num number1, num number2)
{
	int carry = 0;
	for (int i = 0; i < SIZE; i++)
	{
		carry += number1.byteNum[i] + number2.byteNum[i];
		number1.byteNum[i] = carry % 10;
		carry /= 10;
	}
	return(number1);
}

int Len(num number)
{
	for (int i = SIZE - 1; i >= 0; i--)
		if (number.byteNum[i] != 0)
			return(i);
}