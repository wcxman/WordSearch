#include <vector>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "dictionary.h"

using namespace std;

//Reads words from an input file and stores them in a vector
void dictionary::readWords(string fileName)
{
	ifstream inputFile(fileName);
	if (!inputFile.is_open()) {
		throw invalid_argument("ERROR: File not opened successfully.");
	}
	string currentline;
	while (getline(inputFile, currentline)) {
		words.push_back(currentline);
	}
	inputFile.close();
}

//Sorts words by alphabetical order
void dictionary::sortWords()
{
	sort(words.begin(), words.end());
	/*int lowestIndex = 0;
	for (int i = 0; i < words.size() - 1; i++) {
		lowestIndex = i;
		for (int j = i + 1; j < words.size(); j++){ 
			if (words[j] < words[lowestIndex]) {
				lowestIndex = j;
			}
		}
		string temp = words[i];
		words[i] = words[lowestIndex];
		words[lowestIndex] = temp;
	}*/
}

//Searches the sorted words vector for a target and returns the index where it is found
int dictionary::binarySearch(string target)
{
	int lower = 0;
	int upper = words.size() - 1;
	int searchIndex;
	string thisWord;
	while (lower <= upper) {
		searchIndex = (lower + upper) / 2; //Checks middle index of bounds
		thisWord = words[searchIndex];
		if (target < thisWord) { //If middle value is larger than target, then target must be below it
			upper = searchIndex - 1;
		}
		else if (target > thisWord) { //If middle value is smaller than target, then target must be above it
			lower = searchIndex + 1;
		}
		else if (target == thisWord) {
			return searchIndex;
		}
	}
	return -1; //Returns -1 if no such word exists
}

//Returns the word at the inputted index
string dictionary::returnIndex(int index)
{
	return words[index];
}

//Overloaded output operator to print all words in dictionary
ostream& operator<<(ostream& os, const dictionary& dict)
{
	for (int i = 0; i < dict.words.size(); i++) {
		os << dict.words[i] << endl;
	}
	return os;
}