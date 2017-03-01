/**----------------------------------------------------------------------------
FileName: SudokuFactory.cpp
Author: Stephen Deguchi
Student ID#: 1672539
2/24/17
Sub class of PuzzleFactory that creates instances of Sudoku puzzles
*/
#include "SudokuFactory.h"

//-----------------------------------------------------------------------------
// createPuzzle
/**
 * creates a new puzzle to add to a population
 * @param rep : Reproduction : reproduction object to create puzzle
 * @param puz : Puzzle : puzzle to reproduce new puzzle from
 * @return Puzzle* : pointer to newly created puzzle
 */
Puzzle *SudokuFactory::createPuzzle(Reproduction &rep, Puzzle &puz) {

//create a new offspring
	return rep.makeOffspring(puz);
}
//-----------------------------------------------------------------------------
// createPuzzle
/**
 * creates a starting generation puzzle
 * @return Puzzle* : starting puzzle to add to population
 */
Puzzle *SudokuFactory::createPuzzle() {

	//create a first gen puzzle
	return new Sudoku(startSudoku);
}
//-----------------------------------------------------------------------------
// destructor
/**
 * destructor for SudokuFactory class
 */
SudokuFactory::~SudokuFactory() {

	delete startSudoku;
}
//-----------------------------------------------------------------------------
// setStartPuzzle
/**
 * sets the starting puzzle to create a first generation of puzzles from
 */
void SudokuFactory::setStartPuzzle() {
	startSudoku = new Sudoku();
}