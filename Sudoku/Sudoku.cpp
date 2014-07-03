#include "Sudoku.h"
#include <iostream>
#include <fstream>

	//Constructor
	Sudoku::Sudoku() {
		for(int row =0; row<9;++row) {
			for(int column = 0; column<9; ++column) {
				puzzle[row][column]=0;	
			}
		}
	}

	//Loads sudoku from file
	void Sudoku::loadFromFile(std::string filename) {
		std::ifstream puzzle_file2(filename, std::ifstream::in);
		int value2;
		int count =0;
		int	row2,col2;
		int max = 9;
		while(puzzle_file2>>value2) {
			col2 = count%9;
			row2= count/9;
			puzzle[row2][col2]=(int)value2;
			++count;
		}
	}

	//Solve the Sudoku
	bool Sudoku::solve() {	
		//Initialize temporary solution
		int temp[9][9];
		for(int row =0; row<9;++row) {
			for(int column = 0; column<9; ++column) {
				temp[row][column] =puzzle[row][column];	
			}
		}
		//Recursively solve temporary solution
		return recursive_solve(temp);
	}

	bool Sudoku::recursive_solve(int temp[9][9]) {
		//Check if all rows are filled
		int row_unfilled, col_unfilled;
		bool filled=true;
		for(int r =0; r<9;++r) {
			for(int c = 0; c<9; ++c) {
				//Check if grid is empty
				if(temp[r][c]==0) {
					filled = false;
					row_unfilled=r;
					col_unfilled=c;
					r=9;c=9;
				}
			}
		}

		//if filled return true (meaning the sudoku is solved)	
		if(filled) {
			return true;
		}

		//otherwise insert a value and check if valid
		for(int val =1; val<= 9; ++val) {
			//std::cout<<"val1: "<<val<<std::endl;
			if(checkboxes(row_unfilled,col_unfilled,val,temp)
				&& checkcols(row_unfilled,col_unfilled,val,temp)
				&& checkrows(row_unfilled,col_unfilled,val,temp)) {
				//std::cout<<"val2: "<<val<<" row_unfilled: "<<row_unfilled<<" col_unfilled:"<<col_unfilled<<std::endl;
				temp[row_unfilled][col_unfilled] = val;
				puzzle[row_unfilled][col_unfilled] = val;
				if(recursive_solve(temp)) {
					return true;
				}
				puzzle[row_unfilled][col_unfilled] = 0;
				temp[row_unfilled][col_unfilled]= 0;
			}
		}
		return false;
	}

	void Sudoku::print() const {
		//Iterates through entire puzzle and prints in expected format
		for(int row=0; row<9;++row) {
			for(int column = 0; column<9;++column) {
				std::cout<<puzzle[row][column];
				if(column!=8) {
					std::cout<<" ";
				}
				if(column%3==2&&column!=8) {
					std::cout<<"| ";
				}
			}
			std::cout<<std::endl;
			if(row==2||row==5) {
				std::cout<<"------+-------+------"<<std::endl;
			}
		}
	}

	//Checks if both sudokus are equivalent
	bool Sudoku::equals(const Sudoku &other) const {
		bool equal=true;
		for(int row=0; row<9;++row) {
			for(int column = 0; column<9;++column) {
				if(other.puzzle[row][column]!=puzzle[row][column]) {
					equal =false;
				}
			}
		}	
		return false;
	}

	//Checks if number exists in rows
	bool Sudoku::checkrows(int row, int column, int value, int temp[9][9]) {
		bool possible = true;
		for(int c=0; c<9; ++c) {
			if(temp[row][c]==value) {
				possible = false;
			}		
		}
		return possible;
	}
	
	//Checks if number exists in columns
	bool Sudoku::checkcols(int row, int column, int value, int temp[9][9]) {
		bool possible = true;
		for(int r=0; r<9; ++r) {
			if(temp[r][column]==value) {
				possible = false;
			}
		}
		return possible;
	}

	//Checks if number exists in boxes
	bool Sudoku::checkboxes(int row, int column, int value,int temp[9][9]) {
		bool possible =true;
		int rowb = row/3*3;
		int colb = column/3*3;
		int rowe = row/3*3+2;
		int cole= column/3*3+2;
		for(int br = rowb; br<=rowe; ++br) {
			for(int bc = colb; bc<=cole; ++bc) {
				if(temp[br][bc]==value) {
					possible =false;
				}
			}
		}
		return possible;
	}