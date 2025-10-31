/*
---------------------------------------------
Program : Dynamic Quiz Game
Author  : Omkar
Date    : October 2025
---------------------------------------------
Description:
A fully dynamic quiz game in C that allows users to:
 - Play a quiz with preloaded questions.
 - Add their own custom questions.
 - Randomize questions each time the quiz is played.

Each question contains 4 options and one correct answer.
Data is stored in "Questions.txt" for reading and writing.
---------------------------------------------
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>


/*
--------------------------------------------------------------------------------
structure to store questions, respective 4 options and 1 answer to each question
--------------------------------------------------------------------------------
*/
struct question

{

    char question[201]; // stores the question
    char *options[4]; // array of pointers stores the four options of each question
    char answer; // stores a char value index of answer i.e., A / B / C / D

} ;

typedef struct question Question;

/*
--------------------------
Enum for user menu choices
--------------------------
*/
enum Choice 

{

    EXIT, // choice = 0
    PLAY_GAME, // choice= 1
    ADD_QUESTION // choice = 2
    

} ;

// Function Declarations
void instructions ( ) ;                                   // displays the instructions to play the game
void playGame ( FILE *fPtr , int addedQuestionCounter ) ; // playGame function prototype , which handles process of playing the game
void addQuestion ( FILE *fPtr ) ;                         // addQuestion function prototype , which handles process of adding new questions in the game
void preloadQuestions ( FILE *fPtr ) ;                    // preloadQuestions function prototype , which loads the 10 fixed questions in the game
void playGameInstructions();                              // playGameInstructions show how to play the game
void addQuestionInstructions();                           // addQuestionInstructions show how to add question in game

// starting of main function body
int main ( void ) 

{

    int addCounter = 0 ; // counter which counts the number of added questions
    int choice = 0 ; // variable which stores the value of choice opted by the user

    FILE *fPtr = NULL ; // fPtr which handles the processes related to file Questions.txt
    fPtr = fopen ( "Questions.txt" , "w+" ) ; // fPtr opens up the file

    printf ( "+---------------------------------------+\n" ) ;
    printf ( "|           Dynamic Quiz Game           |\n" ) ;
    printf ( "+---------------------------------------+\n\n" ) ;

    instructions ( ) ;

    printf ( "CHOICE :- " ) ;
    scanf( "%d" , &choice ) ;
    printf("\n");

    
    
    while ( choice != 0 )
    
    {

        switch ( choice )
        
        {

            case EXIT :
                
                {

                    break ;

                }

            case PLAY_GAME :
                
                {

                    printf ( "--------------------------------\n" ) ;
                    printf ( "          Game Begins           \n" ) ;
                    printf ( "--------------------------------\n" ) ;
                    preloadQuestions ( fPtr ) ;
                    playGame ( fPtr , addCounter ) ;
                    break ;

                }

            case ADD_QUESTION :

                {

                    printf ( "--------------------------------\n" ) ;
                    printf ( "         Add Questions          \n" ) ;
                    printf ( "--------------------------------\n" ) ;
                    ++addCounter ;
                    addQuestion ( fPtr ) ;
                    break ;

                }

            default :

                {

                    printf ( "Invalid Choice \nTry Again \n" ) ;

                }

        }

        instructions ( ) ;

        if ( choice != 0 )
        
        {

            printf ( "\nCHOICE :- " ) ;
            scanf ( "%d" , &choice ) ;

        }

    }

    printf ( "Program terminating ...\n\n" ) ;

}



void playGame ( FILE *fPtr , int addedQuestionCounter ) 

{

    playGameInstructions();
    rewind ( fPtr ) ;
    Question game1 ;

    int totalQuestions = 10 + addedQuestionCounter ;
    srand ( time ( NULL ) ) ;

    int score = 0 ;
    int random [ totalQuestions ] ;

    for ( int i = 0 ; i < totalQuestions ; ++i )
    
    {

        random [ i ] = -1 ;

    }

    for ( int queCounter = 0 ; queCounter < totalQuestions ; ++queCounter ) 
    
    {

        int j = 0 , match = 0 ;

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

        

        rewind ( fPtr ) ;

        char buffer [ 201 ] ;

        // jump to question j
        for ( int skip = 0 ; skip < j * 6 ; ++skip )
        
        {

            fgets ( buffer , sizeof ( buffer ) , fPtr ) ;

        }
        

        char question [ 201 ] ; 
        fgets ( question , sizeof ( question )  , fPtr ) ;

        question [ strcspn ( question , "\n" ) ] = '\0' ;
        printf ( "\n%s\n" ,  question ) ;

        for ( int i = 0 ; i < 4 ; ++ i ) 
        
        {

            game1 . options [ i ] = malloc ( 101 * sizeof ( char ) ) ;
            if ( game1 . options [ i ] == NULL )
            
            {

                printf ( "Not enough memory available." ) ;

            }
            
            else
            
            {

            fgets ( game1 . options [ i ] , 100, fPtr ) ;
            game1 . options [ i ] [ strcspn ( game1 . options [ i ] , "\n" ) ] = '\0' ;
            printf ( "%c. %s\n" , 'A' + i , game1 . options [ i ] ) ;

            }

        }

        char answer = '\0' , choice = '\0' ;
        fscanf ( fPtr , " %c" , &answer ) ;

        printf ( "\nYour choice: " ) ;
        scanf ( " %c" , &choice ) ;

        choice = toupper ( choice ) ;

        while( choice != 'A' && choice != 'B' && choice != 'C' && choice != 'D' )
    
        {

        printf ( "Invalid Answer\n" ) ;

        printf ( "Answer ( i.e., A , B , C , D ) :- " ) ;
        scanf ( " %c" , &choice ) ;

        choice = toupper ( choice ) ;

        }

        if ( choice == answer ) 
        
        {
            
            printf ( "Correct Answer \n\n" ) ;
            ++ score ;
        
        }

        else 

        {

            printf ( "Wrong Answer \n\n" ) ;

        }

        for ( int i = 0 ; i < 4 ; ++ i )
        
        {

            free ( game1 . options [ i ] ) ;

        }

    }

    printf ( "\nFinal Score: %d out of %d questions\n" , score, totalQuestions ) ; 

}



void addQuestion ( FILE *fPtr )

{

    addQuestionInstructions ( ) ;

    int c ;
    while ( ( c = getchar ( ) ) != '\n' && c != EOF ) ; // flush input buffer

    Question add = { 0 } ;

    printf ( "Question :- " ) ;
    fgets ( add . question , sizeof ( add . question ) , stdin ) ;
    add.question [ strcspn ( add . question , "\n" ) ] = '\0' ; // remove newline

    fprintf ( fPtr , "%s\n" , add . question ) ;

    for ( int i = 0 ; i < 4 ; ++ i )
    
    {

        add . options [ i ] = malloc ( 101 * sizeof ( char ) ) ;   // allocate space
        if ( add . options [ i ] == NULL )
            
        {
                
            printf ( "Not enough memory available." ) ;

        }
            
        else
            
        {

            printf ( "Option %d :- " , ( i + 1 ) ) ;
            fgets ( add . options [ i ] , 100 , stdin ) ;              // read full line (including spaces)
            add . options [ i ] [ strcspn ( add . options [ i ] , "\n" ) ] = '\0' ;  // remove trailing newline
    
        }

    }

    for ( int i = 0 ; i < 4 ; ++ i )
    
    {

        fprintf ( fPtr , "%s\n" , add . options [ i ] ) ;

    }

    printf ( "Answer ( i.e., A , B , C , D ) :- " ) ;
    scanf ( " %c" , &add.answer ) ;

    add . answer = toupper ( add . answer ) ;

    while( add . answer != 'A' && add . answer != 'B' && add . answer != 'C' && add . answer != 'D' )
    
    {

        printf ( "Invalid Answer\n" ) ;

        printf ( "Answer ( i.e., A , B , C , D ) :- " ) ;
        scanf ( " %c" , &add.answer ) ;

        add . answer = toupper ( add . answer ) ;

    }

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

void instructions ( ) 

{

    printf ( "Enter one of the following choices:\n" ) ;
    printf ( "0 - Exit the program\n" ) ;
    printf ( "1 - Play the quiz game\n" ) ;
    printf ( "2 - Add a new question\n\n" ) ;

}

void playGameInstructions ( )

{

    printf ( "\n---------------------------------------------\n" ) ;
    printf ( "        HOW TO PLAY THE QUIZ GAME\n" ) ;
    printf ( "---------------------------------------------\n" ) ;
    printf ( "1. The quiz consists of preloaded and added questions.\n" ) ;
    printf ( "2. Each question has 4 options - A, B, C, and D.\n" ) ;
    printf ( "3. Type the letter (A, B, C, or D) for your chosen answer.\n" ) ;
    printf ( "4. The quiz automatically randomizes question order each time.\n" ) ;
    printf ( "5. Your final score will be shown at the end.\n\n" ) ;

}

void addQuestionInstructions ( )

{

    printf ( "\n---------------------------------------------\n" ) ;
    printf ( "         HOW TO ADD NEW QUESTIONS\n" ) ;
    printf ( "---------------------------------------------\n" ) ;
    printf ( "1. Enter a question when prompted.\n" ) ;
    printf ( "2. Then enter four options (one per line).\n" ) ;
    printf ( "3. After all options, specify the correct answer (A/B/C/D).\n" ) ;
    printf ( "4. Added questions are stored temporarily during this session.\n" ) ;
    printf ( "   (They reset if you restart the program.)\n\n" ) ;

}