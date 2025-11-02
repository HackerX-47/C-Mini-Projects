/*

🧩 Project Overview

The goal is to check if a given Sudoku grid (9×9) is valid according to Sudoku rules:

- Each row must contain digits 1–9 exactly once.
- Each column must contain digits 1–9 exactly once.
- Each 3×3 subgrid must contain digits 1–9 exactly once.

*/

/*

void instructions();
int fillSudoku(int sudoku[9][9],int n);
int input(int sudoku[9][9],int row,int column);
int isRowValid(int sudoku[9][9],int row);
int isColumn(int sudoku[9][9],int column);
void gridChecker(int row,int column, int gridRow, int gridColumn);
int isSubgridValid(int sudoku[9][9],int startRow,int startColumn);
void displaySudoku(int sudoku[9][9]);

*/

// i will take in 35-40 filled cells
// fillSudoku place the value of filled cells in the second argument variable
#include "sudoku.h"

int main(void){

    int sudokuBoard[9][9]={0};
    int row=0;
    int column=0;
    int inputValue=0;
    int userFilledCells=1;
    int initialFilledCells=0;
    int totalFilledCells=0;
    int gridRow=0;
    int gridColumn=0;

    instructions();
    initialFilledCells=fillSudoku(sudokuBoard);
    totalFilledCells=initialFilledCells+userFilledCells;
    
    for(userFilledCells=1;totalFilledCells<=81;++userFilledCells){
        gridRow=0;
        gridColumn=0;
        displaySudoku(sudokuBoard);
        input(sudokuBoard,row,column,0);
        gridChecker(row,column,gridRow,gridColumn);
        while(
            !isRowValid(sudokuBoard,row)||
            !isColumnValid(sudokuBoard,column)||
            !isSubgridValid(sudokuBoard,gridRow,gridColumn)
        )
        {
            input(sudokuBoard,row,column,1);
        }
        // valid now onwards
    }
    // player won, program terminating
}

