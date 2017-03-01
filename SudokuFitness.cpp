/**----------------------------------------------------------------------------
FileName: SudokuFitness.cpp
Author: Stephen Deguchi
Student ID#: 1672539
2/24/17
Sub class of Fitness that uses an algorithm to check the values in a Sudoku
 puzzle to see how the solution matches the rules of the game. The better the
 compliance to the rules, the lower the level of fitness.
*/
#include "SudokuFitness.h"
//-----------------------------------------------------------------------------
// howFit
/**
 * determines the fitness for a puzzle by checking how good of a solution it is
 * @param puz : Puzzle& : puzzle to find fitness of
 * @return int : fitness of puzzle
 */
int SudokuFitness::howFit(Puzzle &puz) {

	//fintess of puzzle
	int fitness = 0;

	//top left position of square to check fitness of
	int topL = 0;

	//check all rows, columns and squares
	for (int i = 0; i < 9; i++) {

		//fitness of current row, column and square
		int row, col, squ;

		//check each row, column, and square given a starting position to
		//check from, start of column, start of row, top left of square
		row = checkRow(i * 9, puz);
		col = checkCol(i, puz);
		squ = checkSqu(topL, puz);

		//increment the row of squares
		if (topL == 6 || topL == 33) {
			topL += 21;
		}

			//increment the column of squares
		else {
			topL += 3;
		}
		//increment the fitness by the row, column, and square of puzzle
		fitness += row + col + squ;
	}
	return fitness;
}
//-----------------------------------------------------------------------------
// checkRow
/**
 * determines the fitness for a row in a Sudoku
 * @param start : int: start index of row to check
 * @param puz : Puzzle& : puzzle to find fitness of
 * @return int : fitness of puzzle row
 */
int SudokuFitness::checkRow(int start, Puzzle &puz) {

	//track values that have been used
	int val[9] = {0};

	//get the values of each position in a row
	for (int i = start; i < start + 9; i++) {
		val[puz.getVal()[i] - 1]++;
	}

	//fitness of row
	int fitness = 0;

	//add up the fitness for a row
	for (int i = 0; i < 9; i++) {

		//if value seen more than once, increment fitness
		if (val[i] > 1) {
			fitness += val[i] - 1;
		}

	}

	return fitness;
}
//-----------------------------------------------------------------------------
// checkCol
/**
 * determines the fitness for a column in a Sudoku
 * @param start : int: start index of column to check
 * @param puz : Puzzle& : puzzle to find fitness of
 * @return int : fitness of puzzle column
 */
int SudokuFitness::checkCol(int start, Puzzle &puz) {

	//track values that have been used
	int val[9] = {0};

	//get the values of each position in a column
	for (int i = start; i < start + 73; i += 9) {
		val[puz.getVal()[i] - 1]++;
	}
	//fitness of column
	int fitness = 0;

	//add up the fitness for a column
	for (int i = 0; i < 9; i++) {

		//if the value seen more than once, increment fitness
		if (val[i] > 1) {
			fitness += val[i] - 1;
		}
	}
	return fitness;
}
//-----------------------------------------------------------------------------
// checkSqu
/**
 * determines the fitness for a square in a Sudoku
 * @param start : int: start index of top left value to check
 * @param puz : Puzzle& : puzzle to find fitness of
 * @return int : fitness of puzzle squ
 */
int SudokuFitness::checkSqu(int start, Puzzle &puz) {

	//track values that have been used
	int val[9] = {0};

	//get the values of each column in a square
	for (int i = 0; i < 3; i++) {
		val[puz.getVal()[start + i] - 1]++;
		val[puz.getVal()[start + i + 9] - 1]++;
		val[puz.getVal()[start + i + 18] - 1]++;
	}

	//fitnesss of a square
	int fitness = 0;

	//add up the values for a square
	for (int i = 0; i < 9; i++) {

		//if the value seen more than once, increment fitness
		if (val[i] > 1) {
			fitness += val[i] - 1;
		}
	}
	return fitness;
}