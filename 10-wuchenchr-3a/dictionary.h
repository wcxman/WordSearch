#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <vector>
#include <fstream>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class dictionary
{
private:
	vector<string> words;
public:
	//Reads words from an input file and stores them in a vector
	void readWords(string fileName);

	//Sorts words by alphabetical order
	void sortWords();

	//Searches the sorted words vector for a target and returns the index where it is found
	int binarySearch(string target);

	//Returns the word at the inputted index
	string returnIndex(int index);

	//Overloaded output operator to print all words in dictionary
	friend ostream& operator<<(ostream& os, const dictionary& dict);
};
#endif
