/**----------------------------------------------------------------------------
FileName: Population.h
Author: Stephen Deguchi
Student ID#: 1672539
2/24/17
Abstract class for a population of puzzles, holds all of the puzzles for
 each generation of new solutions
*/
#ifndef OOTECHNIQUES_POPULATION_H
#define OOTECHNIQUES_POPULATION_H

#include "PuzzleFactory.h"
#include "Fitness.h"

using namespace std;

class Population {
public:
//-----------------------------------------------------------------------------
// Constructor
/**
 * Constructs a population of puzzles
 * @param pop: int :size of population
 */
	Population(int pop) : popSize(pop) {}
//-----------------------------------------------------------------------------
// Destructor
/**
 * Virtual destructor for abstract population class
 */
	virtual ~Population() {};
//-----------------------------------------------------------------------------
// cull
/**
 * Culls 90% of the current population
 */
	virtual void cull()=0;
//-----------------------------------------------------------------------------
// newGeneration
/**
 * repopulates a generation with new offspring from previous generations
 * @param factory : PuzzleFactory : factory to create new puzzles
 * @param rep : Reproduction : reproduces puzzles from previous generations
 */
	virtual void newGeneration(PuzzleFactory &, Reproduction &)=0;
//-----------------------------------------------------------------------------
// bestFitness
/**
 * finds the puzzle closest to a solution
 * @return Puzzle& : puzzle closest to a solution
 */
	virtual Puzzle &bestFitness() const =0;
//-----------------------------------------------------------------------------
// bestIndividual
/**
 * finds puzzle with worst solution from the population
 * @return Puzzle& : Puzzle with worst solution
 */
	virtual Puzzle &bestIndividual() const =0;
//-----------------------------------------------------------------------------
// checkFitness
/**
 * gets the fitness of best puzzle in a population
 * @return int : value of best fitness
 */
	virtual int checkFitness() const =0;
//-----------------------------------------------------------------------------
// evalFitness
/**
 * finds the fitnesses of all the puzzles in the population
 * @param fit : Fitness& : strategy to find the fitnesses
 */
	virtual void evalFitness(Fitness &)=0;


protected:

	//size of the population
	int popSize;


};


#endif //OOTECHNIQUES_POPULATION_H
