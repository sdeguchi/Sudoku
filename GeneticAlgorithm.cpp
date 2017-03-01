/**----------------------------------------------------------------------------
FileName:
Author: Stephen Deguchi
Student ID#: 1672539
2/24/17
Main for O-O Techniques program

 *Input:The program will take two arguments from the command line. The first
 * argument will take an integer that defines the size of the population for
 * the solutions we will use. The second argument will take another integer
 * that sets the limit to the number of generations the program will run
 * through without finding a solution with fitness level of zero.
 * The program will use cin to ask for the values to set the puzzle and scan
 * for integer values of 0-9 until 81 integers have been found.

 *Output:After a solution with a fitness level of zero has been found or
 * the generation limit has been reached, the solution with the lowest
 * fitness will be outputted with its fitness number.
+-------+-------+-------+
| 4 2 3 | 7 5 1 | 9 6 8 |
| 7 5 9 | 6 8 3 | 1 2 4 |
| 1 6 8 | 2 4 9 | 3 5 7 |
+-------+-------+-------+
| 9 4 5 | 3 6 2 | 8 7 1 |
| 8 7 2 | 9 1 5 | 4 3 6 |
| 3 1 6 | 4 7 8 | 2 9 5 |
+-------+-------+-------+
| 5 3 7 | 1 9 4 | 6 8 2 |
| 6 9 1 | 8 2 7 | 5 4 3 |
| 2 8 4 | 5 3 6 | 0 1 9 |
+-------+-------+-------+
Fitness level = 0

 *Usage:	myprog sizeOfPopulation max#ofGenerations

 *Assumptions:	-input from cin will contain compact text of 81 integers 0-9ty
 					-Program has been given valid int arguments for population
 						size and generation limit
 					-size of population and max # of generations to run are a
 						practical size to solve a sudoku puzzle eg. 100 100

 *Description of algorithms and variables:

 	popSize = size of the population genetic algorithm will use to generate
 		a solution to a puzzle
 	gen = max number of generations genetic algorithm will iterate through
 		without finding a solution to a puzzle

 	Genetic ALgorithm creates an initial population of solutions to a puzzle
 	and finds the fitness of them and continues to reproduce populations from
 	the best fit members of a population until a solution to the puzzle has been
 	found, or the maximum number of generations has been reached. The best fit
 	solution and its fitness will be outputted once Genetic Algorithm is
 	finished iterating.

*/
#include "SudokuPopulation.h"


int main(int argc, char *argv[]) {

	//check for correct usage of program
	if (argc != 3) {
		cout << "usage: " << argv[0] << " <populationSize> <max#Generations>";
		exit(1);
	}
	//size of populations to generate
	int popSize = atoi(argv[1]);

	//max number of generations to iterate through
	int gen = atoi(argv[2]);

	//make sure population size is valid
	if (popSize < 1) {
		cout << "input greater population" << endl;
		exit(1);
	}
	//make sure number of generations is valid
	if (gen < 1) {
		cout << "input grater generations" << endl;
		exit(1);
	}

	//factory used by the population to create puzzles
	PuzzleFactory *factory = new SudokuFactory();
	//container for the puzzles for each generation
	Population *pop = new SudokuPopulation(popSize, *factory);
	//creates new offspring from members of a previous generation
	Reproduction *offspring = new SudokuOffspring();
	//strategy used to find a solution to a puzzle
	Fitness *fit = nullptr;

	//check to see what type of strategy to use
	//only one possiblity, so only cast is being made
	SudokuPopulation *sudPtr = dynamic_cast<SudokuPopulation *>(pop);

	//if the cast to a SudokuPopulation* was successfull, the population
	//is a SudokuPopulation and we need a SudokuFitness object
	if (sudPtr != nullptr) {
		fit = new SudokuFitness();
	}

	//evaluate the fitness of the first generation
	pop->evalFitness(*fit);
	
	//keep track of current generations
	int generation = 1;

	//get the best fitness of the first population
	int fitness = pop->checkFitness();

	//iterate the genetic algorithm while a solution has not
	//been found and generation max has not been reached
	while (fitness != 0 && generation != gen) {

		//cull 90% of the population
		pop->cull();

		//repopulate the next generation
		pop->newGeneration(*factory, *offspring);

		//evaluate the fitness of the current generation
		pop->evalFitness(*fit);

		//increase generation
		generation++;

		//find the fitness of the best member
		fitness = pop->checkFitness();

//diagnostic to see the fitness of every 10 generations
		if ((generation + 10) % 10 == 0) {
			if (gen != 10) {
				cout << "Gen= " << generation << endl << "Fitness= " <<
				     pop->bestFitness().getFitness() <<
				     endl << endl << pop->bestFitness() << endl;
			}
		}
	}

//check to see if a solution was found
	if (pop->bestFitness().getFitness() == 0) {
		cout << "Solution found!!" << endl;
	}
		//a solution was not found
	else {
		cout << "Max generations met" << endl;
	}
	//output the fitness, generation, and solution or best puzzle
	// if solution was not found
	cout << "Fitness= " << pop->bestFitness().getFitness() << endl
	     << "Generation= " << generation << endl << pop->bestFitness() << endl;

//clean memory
	delete factory;
	delete fit;
	delete offspring;
	delete pop;

	return 0;
}