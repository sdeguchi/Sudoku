/**----------------------------------------------------------------------------
FileName: SudokuFactory.h
Author: Stephen Deguchi
Student ID#: 1672539
2/24/17
Sub class of PuzzleFactory that creates instances of Sudoku puzzles
*/
#ifndef OOTECHNIQUES_SUDOKUFACTORY_H
#define OOTECHNIQUES_SUDOKUFACTORY_H

#include "Sudoku.h"
#include "SudokuOffspring.h"
#include "PuzzleFactory.h"

class SudokuFactory : public PuzzleFactory {
public:
//-----------------------------------------------------------------------------
// createPuzzle
/**
 * creates a new puzzle to add to a population
 * @param rep : Reproduction : reproduction object to create puzzle
 * @param puz : Puzzle : puzzle to reproduce new puzzle from
 * @return Puzzle* : pointer to newly created puzzle
 */
	Puzzle *createPuzzle(Reproduction &, Puzzle &);
//-----------------------------------------------------------------------------
// createPuzzle
/**
 * creates a starting generation puzzle
 * @return Puzzle* : starting puzzle to add to population
 */
	Puzzle *createPuzzle();

//-----------------------------------------------------------------------------
// destructor
/**
 * destructor for SudokuFactory class
 */
	~SudokuFactory();
//-----------------------------------------------------------------------------
// setStartPuzzle
/**
 * sets the starting puzzle to create a first generation of puzzles from
 */
	void setStartPuzzle();

private:
	//initial puzzle to create a first generation from
	Sudoku *startSudoku = nullptr;

};

#endif //OOTECHNIQUES_SUDOKUFACTORY_H
