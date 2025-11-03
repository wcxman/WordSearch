#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "grid.h"

using namespace std;

// Read grid from file and populate matrix
grid::grid(string fileName)
{
    ifstream inputFile(fileName); // Open file, if  file cannot open give error message
    if (!inputFile.is_open()) {
        throw invalid_argument("ERROR: Grid file open failed.");
    }

    // Read the grid size
    inputFile >> size;

    // Initialize the matrix with the given size
    letterGrid = matrix<char>(size, size, ' ');

    // Read the grid data
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            inputFile >> letterGrid[i][j];
        }
    }

    inputFile.close();
}

int grid::getSize() const
{
    return size;
}

// Get letter at specific position with bounds checking
char grid::getLetter(int row, int col) const
{
    if (row < 0 || row >= size || col < 0 || col >= size) {
        throw out_of_range("ERROR: Grid index out of range.");
    }
    return letterGrid[row][col];
}

// Return reference to entire grid matrix
const matrix<char>& grid::getGrid() const
{
    return letterGrid;
}

// Output grid
ostream& operator<<(ostream& os, const grid& g)
{
    os << "Grid size: " << g.size << " x " << g.size << endl;
    for (int i = 0; i < g.size; i++) {

        for (int j = 0; j < g.size; j++) {

            os << g.letterGrid[i][j] << " ";
        }
        os << endl;
    }
    return os;
}