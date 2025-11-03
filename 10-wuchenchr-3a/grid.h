#ifndef GRID_H
#define GRID_H
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>
#include "d_matrix.h"

using namespace std;

class grid
{
private:
    matrix<char> letterGrid;
    int size;

public:
    // Constructor that reads grid from file
    grid(string fileName);

    // Accessor methods
    int getSize() const;
    char getLetter(int row, int col) const;
    const matrix<char>& getGrid() const;

    // Display method
    friend ostream& operator<<(ostream& os, const grid& g);
};

#endif