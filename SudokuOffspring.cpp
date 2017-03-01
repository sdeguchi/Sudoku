/**----------------------------------------------------------------------------
FileName: SudokuOffspring.cpp
Author: Stephen Deguchi
Student ID#: 1672539
2/24/17
Sub class of Reproduction class that changes the values inside of a puzzle
 and creates a new puzzle to repopulate a genertion of puzzle solutions
*/
#include "SudokuOffspring.h"
//-----------------------------------------------------------------------------
// makeOffspring
/**
 * Create a new offspring by making mutations to a parent puzzle
 * @param puz : Puzzle : puzzle to make new offsrping from
 * @return Puzzle& : newly created offspring
 */
Puzzle *SudokuOffspring::makeOffspring(Puzzle &puz) {

//number of mutations made to offspring
	int count = 0;

	//new offspring
	Puzzle *temp = new Sudoku(puz);

	//make mutations to offspring
	while (count < 3) {

		//change a random position of offspring
		int pos = rand() % 81;

		//if the position of the offspring is not fixed, mutate it
		if (!puz.getFix()[pos]) {

			//set the value of the offspring to a random value at the unfixed
			//position
			temp->setValue((rand() % 9) + 1, pos);

			//increment the number of mutations made
			count++;
		}
	}
	return temp;

}