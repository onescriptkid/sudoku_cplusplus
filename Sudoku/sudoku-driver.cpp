// Jerry Roth
// CS 270
// Project 1 - Sudoku Solver
// Oct. 2006

#include <iostream>
#include <string>
#include <time.h>
#include "Sudoku.h"
using namespace std;

int main(int argc, char * argv[])
{
   string ans, filename;
   Sudoku puzzle;

   cout << "\nSudoku Solver" << endl;
   cout << "-------------" << endl << endl;

   do {
      cout << "\nEnter name of file containing the Sudoku problem: ";
      cin >> filename;
      puzzle.loadFromFile(filename);

      cout << "Given Puzzle:" << endl << endl;
      puzzle.print();

      cout << endl << "Solved Puzzle:" << endl << endl;

      clock_t startTime = clock(); 

      if (puzzle.solve())
         puzzle.print(); // print solved puzzle
      else
         cout << endl << "No Solution" << endl; // indicate there is no solution

      clock_t endTime = clock(); 

      cout << "\n\nTime used: " << (endTime - startTime)/(double)CLOCKS_PER_SEC << " seconds.\n" << endl;

      //// Note: if you have the answer to your puzzle in another file, you can use
      //// the following code to compare your solution to the known answer.
      //Sudoku solution;
      //solution.loadFromFile("<type the answer file name here>");
      //if (puzzle.equals(solution)) 
      //   cout << "Correct solution" << endl;
      //else
      //   cout << "Incorrect solution" << endl;



      cout << "\nDo you want to run it again? (Y|N) ";
      cin >> ans;

   } while (ans == "Y" || ans == "y");


   return 0;
}

