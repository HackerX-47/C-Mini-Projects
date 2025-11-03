/*
===============================================================================
                                MINI PROJECT
===============================================================================
Project Title : Sudoku Validator and Player
Language      : C
Author        : Omkar
Description   :
    This mini project is a console-based Sudoku game and validator written 
    in C. It allows the user to play Sudoku by filling numbers into an initially 
    randomized valid Sudoku board. Each move entered by the player is validated 
    in real-time based on Sudoku rules — ensuring that the number does not 
    repeat in the same row, column, or 3×3 subgrid.

Objectives:
    1. To apply concepts of multidimensional arrays, functions, and loops.
    2. To strengthen understanding of modular programming in C using 
       header files and separate function definitions.
    3. To validate Sudoku rules programmatically and handle invalid inputs.
    4. To enhance logical thinking and basic problem-solving using C.

Key Features:
    - Randomly generates a partially filled Sudoku board.
    - Allows user input for filling empty cells.
    - Validates each move dynamically (row, column, and subgrid check).
    - Clean, structured output display for the Sudoku grid.
    - Encourages practice with user-defined functions and modular design.

===============================================================================
*/

#include "sudoku.h"

int main ( void ) 

{

    int sudokuBoard[9][9]={0};
    int row=0;
    int column=0;
    int userFilledCells=1;
    int initialFilledCells=0;
    int totalFilledCells=0;
    int gridRow=0;
    int gridColumn=0;

    starting();
    instructions();

    initialFilledCells=fillSudoku(sudokuBoard);
    totalFilledCells=initialFilledCells+userFilledCells;
    
    for(userFilledCells=1;totalFilledCells<=81;++userFilledCells)
    
    {

        gridRow=0;
        gridColumn=0;

        printf("Sudoku Board :-\n\n");
        displaySudoku(sudokuBoard);
        input(sudokuBoard,row,column,0);
        gridChecker(row,column,&gridRow,&gridColumn);
        
        while
        
        (

            !isRowValid(sudokuBoard,row)||
            !isColumnValid(sudokuBoard,column)||
            !isSubgridValid(sudokuBoard,gridRow,gridColumn)
        
        )

        {

            printf("Invalid Number\n");
            printf("Row Valid: %d\n",isRowValid(sudokuBoard,row));
            printf("Column Valid: %d\n",isColumnValid(sudokuBoard,column));
            printf("Sub Grid Valid: %d\n\n",isSubgridValid(sudokuBoard,gridRow,gridColumn));
            instructions();
            input(sudokuBoard,row,column,1);
        
        }
        printf("Row Valid: %d\n",isRowValid(sudokuBoard,row));
        printf("Column Valid: %d\n",isColumnValid(sudokuBoard,column));
        printf("Sub Grid Valid: %d\n\n",isSubgridValid(sudokuBoard,gridRow,gridColumn));
        printf("Input is correct\n\n");
    
    }

    printf("\nYou won the sudoku game!\n");

}