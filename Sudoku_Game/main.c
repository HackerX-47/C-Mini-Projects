
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

