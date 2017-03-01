/**----------------------------------------------------------------------------
FileName: SudokuFitness.h
Author: Stephen Deguchi
Student ID#: 1672539
2/24/17
Sub class of Fitness that uses an algorithm to check the values in a Sudoku
 puzzle to see how the solution matches the rules of the game. The better the
 compliance to the rules, the lower the level of fitness.
*/
#ifndef OOTECHNIQUES_SUDOKUFITNESS_H
#define OOTECHNIQUES_SUDOKUFITNESS_H

#include "Sudoku.h"
#include "Fitness.h"
class SudokuFitness:public Fitness{
public:
//-----------------------------------------------------------------------------
// howFit
/**
 * determines the fitness for a puzzle by checking how good of a solution it is
 * @param puz : Puzzle& : puzzle to find fitness of
 * @return int : fitness of puzzle
 */
	int howFit(Puzzle&);

private:
//-----------------------------------------------------------------------------
// checkRow
/**
 * determines the fitness for a row in a Sudoku
 * @param start : int: start index of row to check
 * @param puz : Puzzle& : puzzle to find fitness of
 * @return int : fitness of puzzle row
 */
	int checkRow(int, Puzzle&);
//-----------------------------------------------------------------------------
// checkCol
/**
 * determines the fitness for a column in a Sudoku
 * @param start : int: start index of column to check
 * @param puz : Puzzle& : puzzle to find fitness of
 * @return int : fitness of puzzle column
 */
	int checkCol(int, Puzzle&);
//-----------------------------------------------------------------------------
// checkSqu
/**
 * determines the fitness for a square in a Sudoku
 * @param start : int: start index of top left value to check
 * @param puz : Puzzle& : puzzle to find fitness of
 * @return int : fitness of puzzle squ
 */
	int checkSqu(int, Puzzle&);

};


#endif //OOTECHNIQUES_SUDOKUFITNESS_H
