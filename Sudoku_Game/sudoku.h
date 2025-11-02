

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void instructions();
int fillSudoku(int sudoku[9][9]);
void input(int sudoku[9][9],int row,int column,int invalid);
int isRowValid(int sudoku[9][9],int row);
int isColumnValid(int sudoku[9][9],int column);
void gridChecker(int row,int column, int gridRow, int gridColumn);
int isSubgridValid(int sudoku[9][9],int startRow,int startColumn);
void displaySudoku(int sudoku[9][9]);

