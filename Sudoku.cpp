/**----------------------------------------------------------------------------
FileName: Sudoku.cpp
Author: Stephen Deguchi
Student ID#: 1672539
2/24/17
Sub class of Puzzle that conatains the values that are located in the Sudoku
puzzle. Keeps track of the fixed values and values that will need to be changed
to find new solutions for the puzzle
*/
#include "Sudoku.h"

//-----------------------------------------------------------------------------
// Constructor
/**
 * creates first puzzle to solve
 */
Sudoku::Sudoku() {

	//get input to set the values for the Sudoku
	cin >> *this;



}
//-----------------------------------------------------------------------------
// Copy Constructor
/**
 * copies a puzzle value for value
 * @param Puzzle : puzzle to copy
 */
Sudoku::Sudoku(Puzzle &puz) {

	//copy all 81 values for a Sudoku puzzle
	for (int i = 0; i < 81; i++) {

		//copy values of puzzle
		values[i] = puz.getVal()[i];

		//copy fixed positions of puzzle
		fixed[i] = puz.getFix()[i];
	}

}
//-----------------------------------------------------------------------------
// First Generation Puzzle Constructor
/**
 * creates a first generation puzzle with blank values
 * filled in with random numbers 1-9
 * @param Puzzle* : pointer to first puzzle
 */
Sudoku::Sudoku(Puzzle *start) {

	//copy all 81 values of puzzle
	for (int i = 0; i < 81; i++) {

		//copy values of puzzle
		values[i] = start->getVal()[i];

		//copy fixed positions of puzzle
		fixed[i] = start->getFix()[i];
	}

	//set blank values in puzzle to random values
	for (int i = 0; i < 81; i++) {

		//if a position has a blank value, set it to random number
		if (values[i] == 0) {

			//set a random value at a blank position to 1-9
			values[i] = rand() % 9 + 1;
		}

	}

}
//-----------------------------------------------------------------------------
// setFitness
/**
 * sets the fitness for a puzzle
 * @param fitness : int : fitness for the puzzle
 */
void Sudoku::setFitness(int fit) {
	fitness = fit;
}
//-----------------------------------------------------------------------------
// getFitness
/**
 * gets the fitness of the puzzle
 * @return int : fitness number of the puzzle
 */
int Sudoku::getFitness() const {
	return fitness;
}
//-----------------------------------------------------------------------------
// setValue
/**
 * sets a value in the puzzle at a given position
 * @param value : int : value to set position to
 * @param idx : int : position to set value of
 */
void Sudoku::setValue(int value, int idx) {
	values[idx] = value;
}
//-----------------------------------------------------------------------------
// setFix
/**
 * sets a fixed values for a puzzle
 * @param idx : int : index to set fixed value for
 */
void Sudoku::setFix(int idx) {

	//set a position to fixed
	fixed[idx] = true;
}
//-----------------------------------------------------------------------------
// getVal
/**
 * gets the values for a puzzle
 * @return int* : pointer to array of values
 */
int *Sudoku::getVal() {
	return values;
}
//-----------------------------------------------------------------------------
// getFix
/**
 * gets the fixed values for a puzzle
 * @return bool* : pointer to array of fixed positions
 */
bool *Sudoku::getFix() {
	return fixed;
}
//-----------------------------------------------------------------------------
// OStreamHelper
/**
 * helper function for ostream function, prints out the puzzle
 * @param out : ostream
 * @param puz : Puzzle : the puzzle to print out
 * @return ostream output
 */
void Sudoku::OStreamHelper(ostream &out, const Puzzle &puz) const {

	//border for sudoku output
	string border = "+-------+-------+-------+\n";

	//output a border
	out << border;

	//index of value to output
	int idx = -1;

	//output three rows of squares
	for (int i = 0; i < 3; i++) {

		//output one row of squares
		for (int j = 0; j < 3; j++) {

			//output left border
			out << "| ";

			//output one row of values
			for (int k = 0; k < 3; k++) {
				idx++;
				out << values[idx];
				idx++;
				out << " " << values[idx];
				idx++;
				out << " " << values[idx] << " | ";

			}
			//skip line
			out << endl;
		}

		//output border
		out << border;


	}

}
//-----------------------------------------------------------------------------
// IStreamHelper
/**
 * helper function for istream function, sets values for a puzzle
 * @param string : val : values for puzzle
 * @param puz : Puzzle : the puzzle to set the values for
 * @return istream input
 */
void Sudoku::IStreamHelper(string input, Puzzle &puz) {

	//set all 81 values for sudoku
	for (int i = 0; i < 81; i++) {

		//value of the position
		int val = input[i] - 48;

		//set the position of the puzzle to value
		puz.setValue(val, i);

		//if a value is not blank, set the position to fixed
		if (input.at(i) != '0') {
			puz.setFix(i);
		}

	}

}