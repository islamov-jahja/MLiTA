//Исламов Яхья ПС-21
// MLiTA4.cpp: определяет точку входа для консольного приложения.
/*Найти суммарное число цифр во всех целых числах от M до N включительно.
Ввод из файла INPUT.TXT. В единственной строке находятся целые числа M и N (1 ≤ M ≤
N ≤ 10 15 ).*/

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

const int MaxOfMax = 9;
const int SIZE = 100;

struct num
{
	int byteNum[SIZE];
};

int CountOfNumber(long long int);
num GetSumOfLongNumber(num, num);
num GetCount(long long int);
num setN(num, long long int);
int len(num);
num subLongNumber(num, num);

int main()
{
	ifstream inFile("input.txt");
	ofstream outFile("output.txt");
    long long int m = 0;
	long long int n = 0;
	num resultM;
	num resultN;

	for (int i = 0; i < SIZE; i++)
		resultM.byteNum[i] = 0;

	for (int i = 0; i < SIZE; i++)
		resultN.byteNum[i] = 0;

	inFile >> m;
	inFile >> n;
	m -= 1;



	resultM = GetCount(m);
	resultN = GetCount(n);

	resultN = subLongNumber(resultN, resultM);
	int Len = len(resultN);

		for (int i = Len; i >= 0; i--)
			outFile << resultN.byteNum[i];

	return 0;
}

int CountOfNumber(long long int number)
{
	int count = 0;
	if (number >= 0 && number < 10)
		return 1;
	while (number) {
		number /= 10;
		count++;
	}
	return count;
}



num GetCount(long long int number) {
    num result;
	for (int i = 0; i < SIZE; i++)
		result.byteNum[i] = 0;

	int numberCount = 0;
	int highUrder = 0;
	bool first = true;
	bool notEnd = true;

	num f;
	for (int i = 0; i < SIZE; i++)
		f.byteNum[i] = 0;

    long long int z = 0;

	numberCount = CountOfNumber(number);

	if (numberCount < 2)
	{
		result = GetSumOfLongNumber(result, setN(f, number + 1));
		return (result);
	}

	highUrder = number / pow(10, numberCount - 1);
	highUrder =(highUrder % 10) -1;

	while(numberCount){
		if (first) {
			z = highUrder * numberCount * pow(10, numberCount - 1);
			result = GetSumOfLongNumber(result, setN(f, z));
			first = false;
		}
		else
		{
			if (numberCount != 1) 
			{
				z = numberCount * MaxOfMax * pow(10, numberCount - 1);
				result = GetSumOfLongNumber(result, setN(f, z));
			}
		}
		numberCount--;
	}

	numberCount = CountOfNumber(number);
	result = GetSumOfLongNumber(result, setN(f, 10 + numberCount));
	number -= (highUrder + 1)*pow(10, numberCount - 1);
	result = GetSumOfLongNumber(result, setN(f, numberCount*number));

	return (result);
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


num setN(num longNumber,long long int shortNumber) {
	int i = 0;
	for (int i = 0; i < SIZE; i++)
		longNumber.byteNum[i] = 0;

	while (shortNumber) {
		longNumber.byteNum[i] = shortNumber % 10;
		shortNumber /= 10;
		i++;
	}
	return(longNumber);
}

int len(num number)
{
	for (int i = SIZE - 1; i >= 0; i--)
		if (number.byteNum[i] != 0)
			return(i);
	return 0;
}

num subLongNumber(num number1, num number2) {
	int num2Length = len(number2);
	int num1Length = len(number1);


	if (num2Length == -1) {
		return number1;
	}
	else
	{
		for (int i = 0; i <= num2Length; i++)
		{
			if (number1.byteNum[i] >= number2.byteNum[i]) 
				number1.byteNum[i] -= number2.byteNum[i];
			else
			{
				for (int j = i+1; j <= num1Length; j++)
					if (number1.byteNum[j] > 0)
					{
						number1.byteNum[j] -= 1;
						number1.byteNum[i] = number1.byteNum[i] - number2.byteNum[i] + 10;
						break;
					}
					else
						number1.byteNum[j] = 9;
			}
		}
	}
	return (number1);
}