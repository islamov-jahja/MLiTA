// MLITAPraktika11.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
using namespace std;


bool myFunction(string a, string b)
{
	if (a.length() == b.length())
	{
		return (a < b);
	}
	else
	{
		return (a.length() > b.length());
	}
}

int main()
{
	ifstream inFile("input.txt");
	ofstream outFile("output.txt");
	string word;
	inFile >> word;
	string wordForInsert;
	vector<string> wordsForCompare;
	while (!inFile.eof())
	{
		inFile >> wordForInsert;
		wordsForCompare.push_back(wordForInsert);
	}
	string wordReserve;
	vector<string> resultWords;
	bool end1 = false;
	bool end2 = true;
	multimap<char, int> chars;
	wordReserve = word;
	int countChars = 0;



	for (size_t i = 0; i < wordsForCompare.size(); i++)
	{
		wordForInsert = wordsForCompare[i];
		for (size_t k = 0; k < word.size(); k++)
			chars.emplace(word[k], 2);
		for (size_t j = 0; j < wordForInsert.size(); j++)
		{
			if (chars.find(wordForInsert[j]) == chars.end())
			{
				end2 = false;
			}
			else
			{
				auto itMap = chars.find(wordForInsert[j]);
				chars.erase(itMap);
			}
		}

		if (end2 == true)
		{
			resultWords.push_back(wordsForCompare[i]);
		}
		else
			end2 = true;

		chars.clear();
	}

	sort(resultWords.begin(), resultWords.end(), myFunction);
	countChars = 0;
	for (size_t i = 0; i < resultWords.size(); i++)
		countChars += resultWords[i].length();

	outFile << countChars << endl;
	for (size_t i = 0; i < resultWords.size(); i++)
		outFile << resultWords[i] << endl;


	system("pause");
    return 0;
}

