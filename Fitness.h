/**----------------------------------------------------------------------------
FileName: Fitness.h
Author: Stephen Deguchi
Student ID#: 1672539
2/24/17
Abstract class for an algorithm that determines the fitness of a puzzle,
 that is how good a current solution is. The better a solution, the lower the
 fitness.
*/
#ifndef OOTECHNIQUES_FITNESS_H
#define OOTECHNIQUES_FITNESS_H

#include "Puzzle.h"
class Fitness{
public:
//-----------------------------------------------------------------------------
// howFit
/**
 * determines the fitness for a puzzle by checking how good of a solution it is
 * @param puz : Puzzle& : puzzle to find fitness of
 * @return int : fitness of puzzle
 */
	virtual int howFit(Puzzle&)=0;

};


#endif //OOTECHNIQUES_FITNESS_H
