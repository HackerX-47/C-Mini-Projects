#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

struct question

{

    char question[201];
    char *options[4]; // a,b,c,d,\0
    char answer;

} ;

typedef struct question Question;

enum Choice 

{

    PLAY_GAME,
    ADD_QUESTION,
    EXIT

} ;

void instructions ( ) ;
void playGame ( FILE *fPtr , int addedQuestionCounter ) ;
void addQuestion ( FILE *fPtr ) ;
void preloadQuestions ( FILE *fPtr ) ;

int main ( void ) 

{

    int addCounter = 0 ;
    int choice = 0 ;
    scanf( "%d" , &choice ) ;

    FILE *fPtr = NULL ;
    fPtr = fopen ( "Questions.txt" , "w+" ) ;
    
    while ( choice != 0 )
    
    {

        switch ( choice )
        
        {

            case EXIT :
                
                {

                    // opted for terminating program
                    break ;

                }

            case PLAY_GAME :
                
                {

                    preloadQuestions ( fPtr ) ;
                    playGame ( fPtr , addCounter ) ;
                    break ;

                }

            case ADD_QUESTION :

                {

                    ++addCounter ;
                    addQuestion ( fPtr ) ;
                    break ;

                }

            default :

                {

                    // wrong option opted
                    instructions ( ) ;

                }

        }

        if ( choice != 0 )
        
        {

            scanf ( "%d" , &choice ) ;

        }

    }

    printf ( "Program terminating ..." ) ;

}



void playGame ( FILE *fPtr , int addedQuestionCounter ) 

{

    rewind ( fPtr ) ;
    Question game1 ;

    int totalQuestions = 9 + addedQuestionCounter ;
    srand ( time ( NULL ) ) ;

    int score = 0 ;
    int random [ totalQuestions ] ;

    for ( int i = 0 ; i < totalQuestions ; ++i )
        random [ i ] = -1 ;

    for ( int queCounter = 0 ; queCounter < totalQuestions ; ++queCounter ) 
    
    {

        int j , match ;
        // generate unique random index

        do 
        
        {

            match = 0;
            j = rand() % totalQuestions;

            for (int k = 0 ; k < totalQuestions ; ++k) 
            
            {

                if ( random [ k ] == j ) 
                
                {

                    match = 1 ;
                    break ;

                }

            }

        } 
        
        while ( match == 1 ) ;

        random [ queCounter ] = j ;  // mark used index

        // jump to question j

        rewind ( fPtr ) ;

        char buffer [ 201 ] ;

        for ( int skip = 0 ; skip < j * 6 ; ++skip )
            fgets ( buffer , sizeof ( buffer ) , fPtr ) ;

        // now read question j

        char question [ 201 ] ; 
        fgets ( question , sizeof(question) , fPtr ) ;

        question [ strcspn ( question , "\n" ) ] = '\0' ;
        printf ( "\n%s\n" ,  question ) ;

        for ( int i = 0 ; i < 4 ; ++i ) 
        
        {

            game1 . options [ i ] = malloc ( 101 * sizeof ( char ) ) ;
            fgets ( game1 . options [ i ] , 100, fPtr ) ;
            game1 . options [ i ] [ strcspn ( game1 . options [ i ] , "\n" ) ] = '\0' ;
            printf ( "%c. %s\n" , 'A' + i , game1 . options [ i ] ) ;

        }

        char answer = '\0' , choice = '\0' ;
        fscanf ( fPtr , " %c" , &answer ) ;

        printf ( "Your choice: " ) ;
        scanf ( " %c" , &choice ) ;

        choice = toupper ( choice ) ;

        if ( choice == answer ) 
            ++ score ;

        for ( int i = 0 ; i < 4 ; ++ i )
            free ( game1 . options [ i ] ) ;

    }

    printf ( "\nFinal Score: %d\n" , score ) ; 

}



void addQuestion ( FILE *fPtr )

{

    int c ;
    while ( ( c = getchar ( ) ) != '\n' && c != EOF ) ; // flush input buffer

    Question add = { 0 } ;
    fgets ( add . question , sizeof ( add . question ) , stdin ) ;

    add.question [ strcspn ( add . question , "\n" ) ] = '\0' ; // remove newline
    fprintf ( fPtr , "%s\n" , add . question ) ;

    for ( int i = 0 ; i < 4 ; ++ i )
    
    {

        add . options [ i ] = malloc ( 101 * sizeof ( char ) ) ;   // allocate space
        fgets ( add . options [ i ] , 100 , stdin ) ;             // read full line (including spaces)
        add . options [ i ] [ strcspn ( add . options [ i ] , "\n" ) ] = '\0' ;  // remove trailing newline
    
    }

    for ( int i = 0 ; i < 4 ; ++ i )
    
    {

        fprintf ( fPtr , "%s\n" , add . options [ i ] ) ;

    }

    int c ;
    while ( ( c = getchar ( ) ) != '\n' && c != EOF ) ;  // clear leftover newline

    scanf ( " %c" , &add.answer ) ;
    add . answer = toupper ( add . answer ) ;

    fprintf ( fPtr , "%c\n" , add . answer ) ;
    
    for ( int i = 0 ; i < 4 ; ++ i )
    
    {

        free ( add . options [ i ] ) ;

    }

}

void preloadQuestions ( FILE *fPtr ) 

{

    fprintf
    
    (

        fPtr,

        "What is the capital of India?\n"
        "New Delhi\nMumbai\nKolkata\nChennai\nA\n"

        "Which planet is known as the Red Planet?\n"
        "Earth\nMars\nVenus\nJupiter\nB\n"

        "Who wrote the National Anthem of India?\n"
        "Rabindranath Tagore\nMahatma Gandhi\nBankim Chandra Chatterjee\nJawaharlal Nehru\nA\n"

        "What is the largest ocean in the world?\n"
        "Indian Ocean\nPacific Ocean\nAtlantic Ocean\nArctic Ocean\nB\n"

        "Which is the national animal of India?\n"
        "Lion\nElephant\nTiger\nPeacock\nC\n"

        "Who was the first Prime Minister of India?\n"
        "Mahatma Gandhi\nSardar Patel\nJawaharlal Nehru\nSubhash Chandra Bose\nC\n"

        "Which gas is essential for breathing?\n"
        "Carbon Dioxide\nNitrogen\nOxygen\nHydrogen\nC\n"

        "Which is the smallest continent?\n"
        "Asia\nEurope\nAustralia\nAntarctica\nC\n"

        "How many players are there in a cricket team?\n"
        "9\n10\n11\n12\nC\n"

        "Which is the fastest land animal?\n"
        "Lion\nCheetah\nHorse\nLeopard\nB\n"

    ) ;
    
}