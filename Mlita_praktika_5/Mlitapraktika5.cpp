// Mlitapraktika5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <algorithm>
using namespace std;

const int SIZE = 100050;

int main()
{
	ifstream inFile("input.txt");
	ofstream outFile("output.txt");
	int countSaler = 0;
	int countBuyer = 0;
    int minPriceSalerArr[SIZE];
	int maxPriceBuyerArr[SIZE];
	int  Bestreceipts = 0;
    int receipts = 0;
    int bestPrice = 0;
    int count = 0;
    int buyer = 0;

	inFile >> countSaler;
	inFile >> countBuyer;

	for (int i = 0; i < countSaler; i++)
		inFile >> minPriceSalerArr[i];

	for (int i = 0; i < countBuyer; i++)
		inFile >> maxPriceBuyerArr[i];
	sort(minPriceSalerArr, minPriceSalerArr + countSaler);
	sort(maxPriceBuyerArr, maxPriceBuyerArr + countBuyer);


    
	for (int i = 0; i < countBuyer; i++) {
		for (int j = 0; j < countSaler; j++)
		{
			if (maxPriceBuyerArr[i] >= minPriceSalerArr[j])
			{
				count++;
			}
			else
			{
				receipts = min(count, countBuyer - i) * maxPriceBuyerArr[i];
				if (Bestreceipts < receipts) 
				{
					Bestreceipts = receipts;
					bestPrice = maxPriceBuyerArr[i];
					count = 0;
					break;
				}
			}
		}
	}

	outFile << bestPrice << ' '<< Bestreceipts << endl;
	system("pause");
    return 0;
}

