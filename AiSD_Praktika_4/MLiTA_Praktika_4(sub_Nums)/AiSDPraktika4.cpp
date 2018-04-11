// AiSDPraktika4.cpp: определяет точку входа для консольного приложения.
//Исламов Яхья ПС-21

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>;
#include <algorithm>
using namespace std;

int main()
{
	const int LEN = 400;

	ifstream inFile("input.txt");
	ofstream outFile("output.txt");
	uint8_t number1[LEN];
	uint8_t number2[LEN];
	string number3;
	int arr[LEN];
	int index3 = 0;
	string symb;

	getline(inFile, number3);
	int index1 = number3.length() - 1;

	for (int i = 0; i < number3.length(); i++) {
		symb[0] = number3[i];
		cout << number3[i];
		number1[i] = atoi(symb.c_str());
	}

	getline(inFile, number3);
	int index2 = number3.length() - 1;

	for (int i = 0; i < number3.length(); i++) {
		symb[0] = number3[i];
		number2[i] = atoi(symb.c_str());
	}


	int component1 = 0;
	int component2 = 0;
	int component3 = 0;
	int component = 0;
	bool notSub = true;
	int subs = 0;

	while (notSub)
	{
		component1 = number1[index1];
     	component2 = number2[index2];
		cout << component1 << ' ' << component2;
		if (component2 <= component1)
		{
			component3 = component1 - component2;
			arr[index3] = component3;
			index3++;
			index1--;
			index2--;
			component = component3;
		}
		else
		{
			for (int j = index1-1; j >= 0; j--)
			{
				if (number1[j] > 0)
				{
					number1[j]--;
					break;
				}
				else if(number1[j] == 0)
				{
					component = number1[j];
					number1[j] = 9;
				}
			}
			component3 = (component1 + 10) - component2;
			arr[index3] = component3;
			index3++;
			index1--;
			index2--;
		}
		if (index2 < 0)
		{
			break;
		}
	}

	while (index1 >= 0)
	{
		arr[index3] = number1[index1];
		index1--;
		index3++;
	}

	bool good = false;

	for (int k = index3-1; k >= 0; k--) {
		if (arr[k] != 0)
			good = true;
		if (good)
		    outFile << arr[k];
	}
	if (!good)
		outFile << 0;
    return 0;
}

