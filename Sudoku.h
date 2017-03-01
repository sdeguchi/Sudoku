/**----------------------------------------------------------------------------
FileName: Sudoku.h
Author: Stephen Deguchi
Student ID#: 1672539
2/24/17
Sub class of Puzzle that conatains the values that are located in the Sudoku
puzzle. Keeps track of the fixed values and values that will need to be changed
to find new solutions for the puzzle
*/
#ifndef OOTECHNIQUES_SUDOKU_H
#define OOTECHNIQUES_SUDOKU_H

#include "Puzzle.h"
#include <iostream>

using namespace std;

class Sudoku : public Puzzle {
public:
//-----------------------------------------------------------------------------
// Constructor
/**
 * creates first puzzle to solve
 */
	Sudoku();
//-----------------------------------------------------------------------------
// Copy Constructor
/**
 * copies a puzzle value for value
 * @param Puzzle : puzzle to copy
 */
	Sudoku(Puzzle &);
//-----------------------------------------------------------------------------
// First Generation Puzzle Constructor
/**
 * creates a first generation puzzle with blank values
 * filled in with random numbers 1-9
 * @param Puzzle* : pointer to first puzzle
 */
	Sudoku(Puzzle *);

//-----------------------------------------------------------------------------
// setFitness
/**
 * sets the fitness for a puzzle
 * @param fitness : int : fitness for the puzzle
 */
	void setFitness(int);
//-----------------------------------------------------------------------------
// getFitness
/**
 * gets the fitness of the puzzle
 * @return int : fitness number of the puzzle
 */
	int getFitness() const;

//-----------------------------------------------------------------------------
// setValue
/**
 * sets a value in the puzzle at a given position
 * @param value : int : value to set position to
 * @param idx : int : position to set value of
 */
	void setValue(int, int);
//-----------------------------------------------------------------------------
// setFix
/**
 * sets a fixed values for a puzzle
 * @param idx : int : index to set fixed value for
 */
	void setFix(int);
//-----------------------------------------------------------------------------
// getVal
/**
 * gets the values for a puzzle
 * @return int* : pointer to array of values
 */
	int *getVal();
//-----------------------------------------------------------------------------
// getFix
/**
 * gets the fixed values for a puzzle
 * @return bool* : pointer to array of fixed positions
 */
	bool *getFix();

//struct with method to compare instances of Sudoku
	struct CmpSudokuPtrs {
//-----------------------------------------------------------------------------
// Ooperator
/**
 * overloaded comparison operator, compares the fitnesses of two puzzle objects
 * @param lhs : Puzzle* : puzzle to compare fitness of
 * @param lhs : Puzzle* : puzzle to compare fitness of
 * @return bool : puzzle fitness less than or equal to puzzle being compared
 */
		bool operator()(const Puzzle *lhs, const Puzzle *rhs) const {
			return ((Sudoku *) lhs)->fitness <= ((Sudoku *) rhs)->fitness;
		}
	};

protected:
//-----------------------------------------------------------------------------
// OStreamHelper
/**
 * helper function for ostream function, prints out the puzzle
 * @param output : ostream
 * @param puz : Puzzle : the puzzle to print out
 * @return ostream output
 */
	void OStreamHelper(ostream &, const Puzzle &) const;
//-----------------------------------------------------------------------------
// IStreamHelper
/**
 * helper function for istream function, sets values for a puzzle
 * @param string : val : values for puzzle
 * @param puz : Puzzle : the puzzle to set the values for
 * @return istream input
 */
	void IStreamHelper(string, Puzzle &);

	//values for the Sudoku
	int values[81] = {-1};

	//fixed values for the Sudoku
	bool fixed[81] = {false};

	//fitness number for the puzzle
	int fitness = -1;
};


#endif //OOTECHNIQUES_SUDOKU_H
