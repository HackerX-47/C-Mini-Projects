#include "sudoku.h"

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

void instructions();
int fillSudoku(int sudoku[9][9]){
    int i=0;
    int j=0;
    int gridRow=0;
    int gridColumn=0;
    int filledCellsCounter=0;
    int tries=0;

    // n= number of initially filled cells

    srand(time(NULL));

    int n=25+rand()%(10);

    for(filledCellsCounter;filledCellsCounter<n;++filledCellsCounter){

        tries=0;
        i=rand()%9;
        j=rand()%9;

        while(sudoku[i][j]!=0){

            i=rand()%9;
            j=rand()%9;

        }

        sudoku[i][j]=1+rand()%9;
        gridChecker(i,j,gridRow,gridColumn);
        while(
            !isRowValid(sudoku,i)||
            !isColumnValid(sudoku,j)||
            !isSubgridValid(sudoku,gridRow,gridColumn)&&
            tries<50
        ){
            sudoku[i][j]=1+rand()%9;
            ++tries;
        }
    }
    return n;
}
void input(int sudoku[9][9],int row,int column,int invalid){
    if(!invalid){
        scanf("%d",&row);
        while(row<1||row>9){
            scanf("%d",&row);
        }
        scanf("%d",&column);
        while(column<1||column>9){
            scanf("%d",&column);
        } 
    }
    scanf("%d",&sudoku[row-1][column-1]);
    while(sudoku[row-1][column-1]<1||sudoku[row-1][column-1]>9){
        scanf("%d",&sudoku[row-1][column-1]); 
    }
}
int isRowValid(int sudoku[9][9],int row){
    int success=1;
    for(int y=0;y<9;++y){
        for(int j=y+1;j<9;++j){
            if(sudoku[row][y]!=0){
                if(sudoku[row][y]==sudoku[row][j]){
                    return 0;
                }
            }
        }
    }
    return 1;
}
int isColumnValid(int sudoku[9][9],int column){
    for(int x=0;x<9;++x){
        for(int i=x+1;i<9;++i){
            if(sudoku[x][column]!=0){
                if(sudoku[x][column]==sudoku[i][column]){
                    return 0;
                }
            }
        }
    }
    return 1;
}
void gridChecker(int row,int column, int gridRow, int gridColumn);
int isSubgridValid(int sudoku[9][9],int startRow,int startColumn){
    int array[9];
    int x=0;
    for(int i=startRow;i<(3+startRow);++i){
        for(int j=startColumn;j<(3+startColumn);++j){
            array[x++]=sudoku[i][j];
        }
    }
    for(int i=0;i<9;++i){
        for(int j=i+1;j<9;++j){
            if(array[i]!=0){
                if(array[i]==array[j]){
                    return 0;
                }
            }
        }
    }
    return 1;
}
void displaySudoku(int sudoku[9][9]);