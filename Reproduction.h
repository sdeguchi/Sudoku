/**----------------------------------------------------------------------------
FileName: Reproduction.h
Author: Stephen Deguchi
Student ID#: 1672539
2/24/17
Abstract class for an algorithm that changes the data inside a puzzle to
 create a new instance of that puzzle
*/
#include "Puzzle.h"
#ifndef OOTECHNIQUES_REPRODUCTION_H
#define OOTECHNIQUES_REPRODUCTION_H

class Reproduction{
public:
//-----------------------------------------------------------------------------
// makeOffspring
/**
 * Create a new offspring by making mutations to a parent puzzle
 * @param puz : Puzzle : puzzle to make new offsrping from
 * @return Puzzle& : newly created offspring
 */
	virtual Puzzle* makeOffspring(Puzzle&)=0;

};

#endif //OOTECHNIQUES_REPRODUCTION_H
