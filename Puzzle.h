/**----------------------------------------------------------------------------
FileName: Puzzle.h
Author: Stephen Deguchi
Student ID#: 1672539
2/24/17
Abstract class for a puzzle that the genetic algorithm will try to solve
*/
#ifndef OOTECHNIQUES_PUZZLE_H
#define OOTECHNIQUES_PUZZLE_H
#include <iostream>
#include <climits>
using namespace std;

class Puzzle{
//-----------------------------------------------------------------------------
// operator<<
/**
 * Overload the << operator for the Puzzle class
 * Prints out a puzzle
 * @param output : ostream
 * @param puz : Puzzle& : the puzzle to print
 * @return ostream output
 */
	friend ostream& operator<<(ostream& output,const Puzzle& puz){

		puz.OStreamHelper(output, puz);
		return output;
	}
//-----------------------------------------------------------------------------
// operator<<
/**
 * Overload the >> operator for the Puzzle class
 * takes an input to set the values for a puzzle
 * @param input : istream
 * @param puz : Puzzle : puzzle to set the values for
 * @return istream input
 */
	friend istream& operator>>(istream& input, Puzzle& puz){
		cout<<"Enter values: "<<endl;

		//string for values of puzzle
		string in="";

		//get 81 values of puzzle
		while(1){
			char c;
			cin.get(c);
			if(isdigit(c)){
				in.push_back(c);
				if(in.length()==81){
				break;

				}
			}

		}
		//flush out last lines of sudoku puzzle input
		cin.ignore(INT_MAX,'\n');
		cin.ignore(INT_MAX,'\n');

		puz.IStreamHelper(in, puz);

		return input;
	}
public:
//-----------------------------------------------------------------------------
// setFix
/**
 * sets a fixed values for a puzzle
 * @param idx : int : index to set fixed value for
 */
	virtual void setFix(int)=0;
//-----------------------------------------------------------------------------
// setValue
/**
 * sets a value in the puzzle at a given position
 * @param value : int : value to set position to
 * @param idx : int : position to set value of
 */
	virtual void setValue(int,int)=0;
//-----------------------------------------------------------------------------
// getVal
/**
 * gets the values for a puzzle
 * @return int* : pointer to array of values
 */
	virtual int* getVal()=0;
//-----------------------------------------------------------------------------
// getFix
/**
 * gets the fixed values for a puzzle
 * @return bool* : pointer to array of fixed positions
 */
	virtual bool* getFix()=0;
//-----------------------------------------------------------------------------
// getFitness
/**
 * gets the fitness of the puzzle
 * @return int : fitness number of the puzzle
 */
	virtual int getFitness()const=0;
//-----------------------------------------------------------------------------
// setFitness
/**
 * sets the fitness for a puzzle
 * @param fitness : int : fitness for the puzzle
 */
	virtual void setFitness(int)=0;
protected:
//-----------------------------------------------------------------------------
// OStreamHelper
/**
 * helper function for ostream function, prints out the puzzle
 * @param output : ostream
 * @param puz : Puzzle : the puzzle to print out
 * @return ostream output
 */
	virtual void OStreamHelper(ostream&,const Puzzle&)const=0;
//-----------------------------------------------------------------------------
// IStreamHelper
/**
 * helper function for istream function, sets values for a puzzle
 * @param string : val : values for puzzle
 * @param puz : Puzzle : the puzzle to set the values for
 * @return istream input
 */
	virtual void IStreamHelper(string, Puzzle&)=0;

};



#endif //OOTECHNIQUES_PUZZLE_H
