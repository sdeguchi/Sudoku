/**----------------------------------------------------------------------------
FileName: PuzzleFactory.h
Author: Stephen Deguchi
Student ID#: 1672539
2/24/17
Abstract class for a factory that creates instances of puzzles
*/
#ifndef OOTECHNIQUES_PUZZLEFACTORY_H
#define OOTECHNIQUES_PUZZLEFACTORY_H

#include "Reproduction.h"

class PuzzleFactory {
public:
//-----------------------------------------------------------------------------
// createPuzzle
/**
 * creates a new puzzle to add to a population
 * @param rep : Reproduction : reproduction object to create puzzle
 * @param puz : Puzzle : puzzle to reproduce new puzzle from
 * @return Puzzle* : pointer to newly created puzzle
 */
	virtual Puzzle *createPuzzle(Reproduction &, Puzzle &)=0;
//-----------------------------------------------------------------------------
// createPuzzle
/**
 * creates a starting generation puzzle
 * @return Puzzle* : starting puzzle to add to population
 */
	virtual Puzzle *createPuzzle()=0;
//-----------------------------------------------------------------------------
// destructor
/**
 * destructor for PuzzleFactory class
 */
	virtual ~PuzzleFactory() {};
//-----------------------------------------------------------------------------
// setStartPuzzle
/**
 * sets the starting puzzle to create a first generation of puzzles from
 */
	virtual void setStartPuzzle()=0;


};


#endif //OOTECHNIQUES_PUZZLEFACTORY_H
