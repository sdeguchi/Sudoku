cmake_minimum_required(VERSION 3.6)
project(ootechniques)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Fitness.h
        GeneticAlgorithm.cpp
        Population.h
        Puzzle.h
        PuzzleFactory.h
        Reproduction.h
        Sudoku.cpp
        Sudoku.h
        SudokuFactory.cpp
        SudokuFactory.h
        SudokuFitness.cpp
        SudokuFitness.h
        SudokuOffspring.cpp
        SudokuOffspring.h
        SudokuPopulation.cpp
        SudokuPopulation.h)

add_executable(ootechniques ${SOURCE_FILES})