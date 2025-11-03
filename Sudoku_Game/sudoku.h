/*
===============================================================================
                                HEADER FILE
===============================================================================
File Name     : sudoku.h
Purpose       : To declare all functions and global includes used in the
                Sudoku Validator and Player program.

Description   :
    This header file contains all the function prototypes, global includes,
    and necessary definitions for the Sudoku game. It ensures modularity
    and clean separation between declaration and implementation.

Contents:
    - Function declarations for initialization, validation, and display.
    - Standard library includes for I/O, randomization, and time handling.

===============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void starting ( ) ;
void instructions ( ) ;
int fillSudoku ( int sudoku[9][9] ) ;
void input ( int sudoku[9][9] , int row , int column , int invalid ) ;
int isRowValid ( int sudoku[9][9] , int row ) ;
int isColumnValid (int sudoku[9][9] ,int column ) ;
void gridChecker ( int row , int column , int *gridRow , int *gridColumn ) ;
int isSubgridValid ( int sudoku[9][9] , int startRow , int startColumn ) ;
void displaySudoku ( int sudoku[9][9] ) ;

