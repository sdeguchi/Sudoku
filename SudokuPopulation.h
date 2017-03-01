/**----------------------------------------------------------------------------
FileName: SudokuPopulation.h
Author: Stephen Deguchi
Student ID#: 1672539
2/24/17
Sub class of population, container class for population of Sudoku puzzles,
 performs all the actions on the puzzles in the current generation
*/
#ifndef OOTECHNIQUES_SUDOKUPOPULATION_H
#define OOTECHNIQUES_SUDOKUPOPULATION_H

#include "Population.h"
#include "SudokuFactory.h"
#include "SudokuFitness.h"
#include "Sudoku.h"
#include <set>
#include <queue>
#include <vector>

class SudokuPopulation : public Population {
public:
//-----------------------------------------------------------------------------
// Constructor
/**
 * Constructs a population of puzzles
 * @param pop: int :size of population
 */
	SudokuPopulation(int pop, PuzzleFactory &);
//-----------------------------------------------------------------------------
// Destructor
/**
 * Destructor for SudokuPopulation class
 */
	~SudokuPopulation();
//-----------------------------------------------------------------------------
// cull
/**
 * Culls 90% of the current population
 */
	void cull();
//-----------------------------------------------------------------------------
// newGeneration
/**
 * repopulates a generation with new offspring from previous generations
 * @param factory : PuzzleFactory : factory to create new puzzles
 * @param rep : Reproduction : reproduces puzzles from previous generations
 */
	void newGeneration(PuzzleFactory &, Reproduction &);
//-----------------------------------------------------------------------------
// bestFitness
/**
 * finds the puzzle closest to a solution
 * @return Puzzle& : puzzle closest to a solution
 */
	Puzzle &bestFitness() const;
//-----------------------------------------------------------------------------
// bestIndividual
/**
 * finds puzzle with worst solution from the population
 * @return Puzzle& : Puzzle with worst solution
 */
	Puzzle &bestIndividual() const;
//-----------------------------------------------------------------------------
// evalFitness
/**
 * finds the fitnesses of all the puzzles in the population
 * @param fit : Fitness& : strategy to find the fitnesses
 */
	void evalFitness(Fitness &);
//-----------------------------------------------------------------------------
// checkFitness
/**
 * gets the fitness of best puzzle in a population
 * @return int : value of best fitness
 */
	int checkFitness() const;

protected:
	//container for the population of puzzles
	priority_queue<Sudoku *, vector<Sudoku *>, Sudoku::CmpSudokuPtrs> pq;

	//pointer to the puzzle with the best solution
	Sudoku *best = nullptr;
};


#endif //OOTECHNIQUES_SUDOKUPOPULATION_H
