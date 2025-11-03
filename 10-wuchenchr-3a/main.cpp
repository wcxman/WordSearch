#include <vector>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "dictionary.h"
#include "grid.h"

using namespace std;


// Global function to find matches between grid and dictionary
void findMatches(const dictionary& dict, const grid& g)
{
    int size = g.getSize();
	int row = 0, col = 0;
    const matrix<char>& letterGrid = g.getGrid();
	vector<string> candidates;
	string currentCandidate = "";

    
    // Define the 8 possible directions (dx, dy)
	int directions[8][2] = {
		{0, 1},   // right
		{1, 0},   // down
		{0, -1},  // left
		{-1, 0},  // up
		{1, 1},   // down-right
		{1, -1},  // down-left
		{-1, 1},  // up-right
		{-1, -1}  // up-left
	};
	
	for (int i = 0; i < g.getSize(); i++) { //Starting Row
		for (int j = 0; j < g.getSize(); j++) { //Starting Column
			for (int k = 0; k < 8; k++) { //Direction
				row = i;
				col = j;
				std::cout << i << " " << j << endl;
				while (currentCandidate.length() < 46) { //Longest word is 45 letters
					currentCandidate += g.getLetter(row, col);
					if (currentCandidate.length() >= 5) { //Shortest words are 5 letters
						candidates.push_back(currentCandidate);
					}
					row = (row + directions[k][0])%size; //Increments row in direction, wraps around w/ positive out of bounds
					col = (col + directions[k][1])%size; //Increments row in direction, wraps around w/ positive out of bounds
					if (row < 0) {
						row += size; //Wraps around w/ negative out of bounds
					}
					if (col < 0) {
						col += size;
					}
					if (row == i && col == j) { //If we have returned to initial location
						currentCandidate = ""; //Clears value of current candidate
						break;
					}
				}
			}
		}
	}
	for (string candidate : candidates) { //For each candidate in the vector of candidates
		if (dict.binarySearch(candidate) != -1) {
			std::cout << "Found: " << candidate << endl;
		}
	}
}


// Search function
void search()
{
    string gridFileName;
    string dictFileName;
    
    // Read the name of the grid file
    cout << "Enter the grid file name: ";
    cin >> gridFileName;
    
    cout << "Enter the dictionary file name: ";
    cin >> dictFileName;
    
    // Read the data from input files for grid and dictionary
    cout << "Loading dictionary from: " << dictFileName << endl;
    
    dictionary wordDic;
    wordDic.readWords(dictFileName);
    
    wordDic.sortWords();
    cout << "Dictionary sorted successfully." << endl;
    
    cout << "Loading grid from: " << gridFileName << endl;
    grid wordGrid(gridFileName);
    
    // Display grid info
    cout << "Size: " << wordGrid.getSize() << "x" << wordGrid.getSize() << endl;
    cout << "Grid contents:" << endl;
    cout << wordGrid << endl;
    
    // Print out the words found in the dictionary
    cout << "Word Search Result: " << endl;
    findMatches(wordDic, wordGrid);
}

int main() {
	// Call search function
	search();
	
	/* try {
		dictionary newdic;
		newdic.readWords("c:\\Dictionary.txt");
		newdic.sortWords();
		grid newgrid("C:\\input15.txt");
		cout << newgrid << endl;
		findMatches(newdic, newgrid);
		return 0;
	}
*/
	catch (invalid_argument e) {
		cout << e.what();
	}
	catch (out_of_range e) {
		cout << e.what();
	}

}

