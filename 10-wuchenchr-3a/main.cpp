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
    const matrix<char>& letterGrid = g.getGrid();
    
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
	
}


int main() {
	try {
		dictionary newdic;
		newdic.readWords("C:\\Dictionary5.txt");
		cout << newdic.returnIndex(0) << endl;
		newdic.sortWords();
		cout << newdic.returnIndex(0) << endl;
		cout << newdic.binarySearch("Birthdate") << " " << newdic.binarySearch("apple") << " " << newdic.binarySearch("kjadflkajdsflkajsdflkasdjflkasdjf");
		cout << newdic;
		return 0;
	}
	catch (invalid_argument e) {
		cout << e.what();
	}

}
