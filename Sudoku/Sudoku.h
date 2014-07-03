#include <iostream>
#include <string>

class Sudoku {

public:
	//Constructor
	Sudoku();

	//Loads sudoku from text file
	void loadFromFile(std::string filename);

	//Solves sudoku with the aid of helper functions
	bool solve();

	//Prints sudoku
	void print() const;

	//Determines if two sudokus are equal
	bool equals(const Sudoku &other) const;

private:
	//Checks the rows if a number has already been used
	bool checkrows(int row, int column, int value,int temp[9][9]);
	//Checks the coumns if a number has already been used
	bool checkcols(int row, int column, int value, int temp[9][9]);
	//Checks the boxes if a number has already been used
	bool checkboxes(int row, int column, int value,int temp[9][9]);

	//Uses recursive backtracking to solve the puzzle.
	bool recursive_solve(int temp[9][9]);

	//Puzzle in multidimensional array format
	int puzzle[9][9];

};