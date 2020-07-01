#include <iostream>
#include <string>
#include <cstdlib>

#include "grid.h"

using namespace std;

int main(int argc, char* argv[]) 
{

	if (argc != 4) 
    {
        cerr << "Usage: " << argv[0] << " grid_file col_no row_no" << endl << endl;
        return EXIT_FAILURE;
    }

    grid* g;

    g = new grid(argv[1]);  // sample.grid

    int row = atoi(argv[2]);  // 4
	int col = atoi(argv[3]);  // 2

    cout << "The colony including the cell at "
        << "(" << row << "," << col << ")"
        << " has an area of " << g->count(row, col) << " units." << endl;

    cout << *g << endl;

    delete g;

    return EXIT_SUCCESS;
}

