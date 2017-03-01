/**----------------------------------------------------------------------------
FileName: SudokuOffspring.h
Author: Stephen Deguchi
Student ID#: 1672539
2/24/17
Sub class of Reproduction class that changes the values inside of a puzzle
 and creates a new puzzle to repopulate a genertion of puzzle solutions
*/

#ifndef OOTECHNIQUES_SUDOKUOFFSPRING_H
#define OOTECHNIQUES_SUDOKUOFFSPRING_H

#include "Sudoku.h"
#include "Reproduction.h"

class SudokuOffspring : public Reproduction {
public:
//-----------------------------------------------------------------------------
// makeOffspring
/**
 * Create a new offspring by making mutations to a parent puzzle
 * @param puz : Puzzle : puzzle to make new offsrping from
 * @return Puzzle& : newly created offspring
 */
	Puzzle *makeOffspring(Puzzle &);
};

#endif //OOTECHNIQUES_SUDOKUOFFSPRING_H
