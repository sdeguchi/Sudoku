/**----------------------------------------------------------------------------
FileName: SudokuPopulation.cpp
Author: Stephen Deguchi
Student ID#: 1672539
2/24/17
Sub class of population, container class for population of Sudoku puzzles,
 performs all the actions on the puzzles in the current generation
*/
#include "SudokuPopulation.h"
#include <climits>
#include <ctime>
//-----------------------------------------------------------------------------
// Constructor
/**
 * Constructs a population of Sudoku puzzles
 * @param pop: int :size of population
 * @param factory : PuzzleFactory : factory to create new puzzles
 */
SudokuPopulation::SudokuPopulation(int pop, PuzzleFactory &factory) : Population(pop) {

	//seed random number generator
	srand(time(nullptr));

	//get the puzzle to solve and set it in the puzzle factory
	factory.setStartPuzzle();

	//create the first population
	for (int i = 0; i < pop; i++) {

		//create a new puzzle
		Puzzle *temp = factory.createPuzzle();

		//cast the puzzle to a sudoku ponter
		Sudoku *ptr = (Sudoku *) temp;

		//add the puzzle to the priority queue
		pq.push(ptr);

	}

}
//-----------------------------------------------------------------------------
// Destructor
/**
 * Destructor for SudokuPopulation class
 */
SudokuPopulation::~SudokuPopulation() {

//empty and delete all the puzzles in the queue
	while (!pq.empty()) {

		Sudoku *ptr = pq.top();;
		pq.pop();
		delete ptr;
	}
}
//-----------------------------------------------------------------------------
// cull
/**
 * Culls 90% of the current population
 */
void SudokuPopulation::cull() {

	//reduce the population by 90%
	for (int i = (int) (popSize * .9); i > 0; i--) {

		Sudoku *ptr = pq.top();
		pq.pop();
		delete ptr;
	}
}
//-----------------------------------------------------------------------------
// newGeneration
/**
 * repopulates a generation with new offspring from previous generations
 * @param factory : PuzzleFactory : factory to create new puzzles
 * @param rep : Reproduction : reproduces puzzles from previous generations
 */
void SudokuPopulation::newGeneration(PuzzleFactory &fact, Reproduction &rep) {

	//queue to hold previous generation
	queue<Sudoku *> temp;

//move the contents of the previous generation to the temp queue
	while (!pq.empty()) {

		temp.push(pq.top());
		pq.pop();
	}
	//number of puzzles to repopulate
	int rePop = popSize - (int) temp.size();

//repopulate the population
	while (rePop > 0) {

		//create a new puzzle from a member of the previous population
		Puzzle *puz = fact.createPuzzle(rep, *(temp.front()));

		//add the puzzle to the population
		Sudoku *sud = (Sudoku *) puz;
		pq.push(sud);

		//decrease repop
		rePop--;

		//put the member from previous population back in the queue
		Sudoku *current = temp.front();
		temp.pop();
		temp.push(current);
	}
//put the remaining previous generation members back in the queue
	while (!temp.empty()) {
		Sudoku *ptr = temp.front();
		pq.push(ptr);
		temp.pop();
	}

}
//-----------------------------------------------------------------------------
// bestFitness
/**
 * finds the puzzle closest to a solution
 * @return Puzzle& : puzzle closest to a solution
 */
Puzzle &SudokuPopulation::bestFitness() const {

	return *best;
}
//-----------------------------------------------------------------------------
// bestIndividual
/**
 * finds puzzle with worst solution from the population
 * @return Puzzle& : Puzzle with worst solution
 */
Puzzle &SudokuPopulation::bestIndividual() const {

	return *(pq.top());
}
//-----------------------------------------------------------------------------
// checkFitness
/**
 * gets the fitness of best puzzle in a population
 * @return int : value of best fitness
 */
int SudokuPopulation::checkFitness() const {

	return bestFitness().getFitness();
}
//-----------------------------------------------------------------------------
// evalFitness
/**
 * finds the fitnesses of all the puzzles in the population
 * @param fit : Fitness& : strategy to find the fitnesses
 */
void SudokuPopulation::evalFitness(Fitness &fit) {

	//value of fitness of best puzzle
	int bestFit = INT_MAX;

	//pointer to puzzle with best fitness
	best = nullptr;

	//queue to store the evaluated members
	queue<Sudoku *> temp;

	//find the fitness of each member of the population
	while (!pq.empty()) {

		//find fitness of a puzzle
		Sudoku *ptr = pq.top();
		pq.pop();
		ptr->setFitness(fit.howFit(*ptr));

		//put the puzzle in the queue of evaluated puzzles
		temp.push(ptr);

		//find the puzzle with best fitness in the population
		if (ptr->getFitness() < bestFit) {
			bestFit = ptr->getFitness();
			best = ptr;
		}
	}
	//put the population back in the priority queue
	while (!temp.empty()) {
		Sudoku *ptr = temp.front();
		pq.push(ptr);
		temp.pop();
	}


}
