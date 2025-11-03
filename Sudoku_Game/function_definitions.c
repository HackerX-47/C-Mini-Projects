#include "sudoku.h"

void starting(){
    printf("\n========================================\n");
    printf("         WELCOME TO SUDOKU GAME         \n");
    printf("========================================\n\n");
}

void instructions(){
    printf("Rules:\n");
    printf("1. You'll see a partially filled Sudoku grid.\n");
    printf("2. Enter row (1-9), column (1-9), and a value (1-9).\n");
    printf("3. A move is valid only if it doesn't repeat\n");
    printf("   in the same row, column, or 3x3 subgrid.\n");
    printf("4. 0 means an empty cell.\n\n");
}


int fillSudoku(int sudoku[9][9])

{

    int i=0;
    int j=0;
    int gridRow=0;
    int gridColumn=0;
    int filledCellsCounter=0;
    int tries=0;

    srand(time(NULL));

    int n=25+rand()%(10);

    for(filledCellsCounter;filledCellsCounter<n;++filledCellsCounter)
    
    {

        tries=0;
        i=rand()%9;
        j=rand()%9;

        while(sudoku[i][j]!=0)
        
        {

            i=rand()%9;
            j=rand()%9;

        }

        sudoku[i][j]=1+rand()%9;
        gridChecker(i,j,&gridRow,&gridColumn);

        while
        
        (

            !isRowValid(sudoku,i)||
            !isColumnValid(sudoku,j)||
            !isSubgridValid(sudoku,gridRow,gridColumn)&&
            tries<50

        )
        
        {

            sudoku[i][j]=1+rand()%9;
            ++tries;
        
        }

    }

    return n;

}


void input(int sudoku[9][9],int row,int column,int invalid)

{

    if(!invalid)
    
    {
        printf("Tell me the row number you want to move :- ");
        scanf("%d",&row);
        while(row<1||row>9)
        
        {

            printf("\nInvalid Input, Try again\nRow number :- ");
            scanf("%d",&row);

        }

        printf("Tell me the row number you want to move :- ");
        scanf("%d",&column);
        while(column<1||column>9)
        
        {

            printf("\nInvalid Input, Try again\nColumn number :- ");
            scanf("%d",&column);

        } 

    }

    while(sudoku[row-1][column-1]!=0 && !invalid) 
    
    {
        printf("Invalid Location Choosed\nTry Again\n");

        printf("Tell me the row number you want to move :- ");
        scanf("%d",&row);
        while(row<1||row>9)
        
        {

            printf("\nInvalid Input, Try again\nRow number :- ");
            scanf("%d",&row);

        }

        printf("Tell me the row number you want to move :- ");
        scanf("%d",&column);
        while(column<1||column>9)
        
        {

            printf("\nInvalid Input, Try again\nColumn number :- ");
            scanf("%d",&column);

        }

    }

    printf("Tell me the value you want to input :- ");
    scanf("%d",&sudoku[row-1][column-1]);
    while(sudoku[row-1][column-1]<1||sudoku[row-1][column-1]>9)
    
    {

        printf("\nInvalid Input, Try again\nValue :- ");
        scanf("%d",&sudoku[row-1][column-1]); 

    }
    printf("\n");
}


int isRowValid(int sudoku[9][9],int row)

{

    int success=1;

    for(int y=0;y<9;++y)
    
    {

        for(int j=y+1;j<9;++j)
        
        {

            if(sudoku[row][y]!=0)
            
            {

                if(sudoku[row][y]==sudoku[row][j])
                
                {

                    return 0;

                }

            }

        }

    }

    return 1;

}


int isColumnValid(int sudoku[9][9],int column)

{

    for(int x=0;x<9;++x)
    
    {

        for(int i=x+1;i<9;++i)
        
        {

            if(sudoku[x][column]!=0)
            
            {

                if(sudoku[x][column]==sudoku[i][column])
                
                {
                
                    return 0;
                
                }

            }

        }

    }

    return 1;

}


void gridChecker(int row,int column, int *gridRow, int *gridColumn)

{

    *gridRow = (row / 3) * 3;
    *gridColumn = (column / 3) * 3;

}


int isSubgridValid(int sudoku[9][9],int startRow,int startColumn)

{

    int array[9];
    int x=0;

    for(int i=startRow;i<(3+startRow);++i)
    
    {

        for(int j=startColumn;j<(3+startColumn);++j)
        
        {

            array[x++]=sudoku[i][j];

        }

    }

    for(int i=0;i<9;++i)
    
    {

        for(int j=i+1;j<9;++j)
        
        {

            if(array[i]!=0)
            
            {

                if(array[i]==array[j])
                
                {

                    return 0;

                }

            }

        }

    }

    return 1;

}


void displaySudoku(int sudoku[9][9]) 

{

    printf("\n+---------+---------+---------+\n");

    for (int i = 0; i < 9; ++i) 
    
    {

        printf("|");

        for (int j = 0; j < 9; ++j) 
        
        {

            if (sudoku[i][j] == 0)

            {

                printf("   ");

            }

            else

            {

                printf(" %d ", sudoku[i][j]);

            }

            if ((j + 1) % 3 == 0)
            
            {
             
                printf("|");
            
            }

        }

        printf("\n");

        if ((i + 1) % 3 == 0)
        
        {

            printf("+---------+---------+---------+\n");
        
        }

    }

    printf("\n");

}