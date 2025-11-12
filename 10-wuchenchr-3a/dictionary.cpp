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
	int lowestIndex = 0;
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
	}
}

//Searches the sorted words vector for a target and returns the index where it is found
int dictionary::binarySearch(string target) const
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

//Sorts words by alphabetical order using quick sort
void dictionary::quickSort()
{
	int part = partition(0, words.size()-1);
	quickSort(0, part - 1);
	quickSort(part+1, words.size() -1);
}

//Sorts indices startIndex through endIndex
void dictionary::quickSort(int startIndex, int endIndex)
{
	if (startIndex < endIndex) {
		int part = partition(startIndex, endIndex);
		quickSort(startIndex, part - 1);
		quickSort(part + 1, endIndex);
	}
}

//Helper function for quicksort
int dictionary::partition(int startIndex, int endIndex)
{
	string pivotVal = words[endIndex];
	int i = startIndex - 1;
	string temp = "";
	for (int j = startIndex; j < endIndex - 1; j++) {
		if (words[j] <= pivotVal) {
			i++;
			temp = words[i];
			words[i] = words[j];
			words[j] = temp;
		}
	}
	temp = words[i+1];
	words[i+1] = pivotVal;
	words[endIndex] = temp;
	return i + 1;
}

//Returns the word at the inputted index
string dictionary::returnIndex(int index) const
{
	return words[index];
}

// heapsort function
void dictionary::heapSort()
{
    heap<string> wordHeap;
    wordHeap.initializeMaxHeap(words);
    wordHeap.heapsort();
    words = wordHeap.getSortedArray();
}

//Overloaded output operator to print all words in dictionary
ostream& operator<<(ostream& os, const dictionary& dict)
{
	for (int i = 0; i < dict.words.size(); i++) {
		os << dict.words[i] << endl;
	}
	return os;

}
