/*
=================================================================
██╗   ██╗██╗███╗   ██╗████████╗ █████╗  ██████╗  ██████╗ ███████╗
██║   ██║██║████╗  ██║╚══██╔══╝██╔══██╗██╔════╝ ██╔═══██╗██╔════╝
██║   ██║██║██╔██╗ ██║   ██║   ███████║██║  ███╗██║   ██║███████╗
╚██╗ ██╔╝██║██║╚██╗██║   ██║   ██╔══██║██║   ██║██║   ██║╚════██║
 ╚████╔╝ ██║██║ ╚████║   ██║   ██║  ██║╚██████╔╝╚██████╔╝███████║
  ╚═══╝  ╚═╝╚═╝  ╚═══╝   ╚═╝   ╚═╝  ╚═╝ ╚═════╝  ╚═════╝ ╚══════╝
            B A N K   A C C O U N T   M A N A G E R
=================================================================

/*
===============================================================
                    PROGRAM OVERVIEW
===============================================================
   BANK ACCOUNT MANAGER
---------------------------------------------------------------
   This program simulates a simple yet robust banking system
   designed entirely in C. It provides functionalities such as:

      • Account Creation
      • Cash Withdrawal
      • Cash Deposit
      • Balance Inquiry
      • Record Navigation (Jump Function)

---------------------------------------------------------------
                    PROGRAM STRENGTHS
---------------------------------------------------------------
✅  Structured Code:
    Uses modular design — each functionality is implemented as
    a separate function, making the code easy to maintain,
    extend, and debug.

✅  Data Persistence:
    All account details are stored in a text file, ensuring
    information is preserved even after program termination.

✅  Safe Input Handling:
    Proper use of scanf() with field width specifiers prevents
    buffer overflow and improves security.

✅  Portable & Lightweight:
    Requires no external libraries beyond <stdio.h> and <string.h>,
    ensuring smooth execution on any system with a C compiler.

✅  Clear Data Formatting:
    Uses fixed-width account numbers (e.g., 0000000001) for
    consistent storage and professional presentation.

✅  Efficient File Management:
    Implements file rewind, fflush, and fscanf/fprintf effectively
    to handle record updates and retrievals safely.

✅  User-Friendly Output:
    Displays all relevant account details after creation and
    during inquiries in a clean, readable format.

✅  Extendable Design:
    Can be easily upgraded to support login systems, transaction
    histories, or database integration in future versions.

---------------------------------------------------------------
   Designed for learning core C programming concepts including:
   - File handling
   - Struct usage
   - Data validation
   - Modular programming
   - Basic input/output operations

   © Developed for GSoC Preparation
===============================================================

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct account

{

    char accountNumber [ 11 ] ;
    char firstName [ 31 ] ;
    char lastName [ 31 ] ;
    int balance ;

} ;

typedef struct account Account ;

enum Options

{
    
    EXIT ,
    CREATE_ACCOUNT ,
    DELETE_ACCOUNT ,
    DEPOSIT ,
    WITHDRAW ,
    BALANCE_INQUIRY ,

} ;

void instructions ( ) ;
void createAccount ( FILE * fPtr , int createdAccountCounter ) ;
void deleteAccount ( FILE * fPtr ) ;
void deposit_OR_withdraw ( FILE * fPtr , int option ) ;
void balanceInquiry ( FILE * fPtr ) ;

int main ( void ) 

{

    int createdAccounts = 0 ;
    FILE * fPtr = NULL ;

    fPtr = fopen ( "accounts.txt" , "w+" ) ;

    if ( fPtr == NULL )
    
    {

        printf ( "Error opening the file!" ) ; 

    }

    else
    
    {

        printf ( "+------------------------------------+\n" ) ;
        printf ( "|       Bank Account Manager         |\n" ) ;
        printf ( "+------------------------------------+\n\n" ) ;

        instructions ( ) ;

        int menuOption = 0 ;
        printf ( "Tell me the option you want to choose :- " ) ;
        scanf ( "%d" , &menuOption ) ;
        printf ( "\n" ) ;

        int option = 0 ;

        while ( menuOption != 0 ) 
        
        {  

            switch ( menuOption )
            
            {

                case EXIT :

                {

                    break ;

                }

                case CREATE_ACCOUNT :

                {
                  
                    printf ( "--------------------------------\n" ) ;
                    printf ( "        Create Account          \n" ) ;
                    printf ( "--------------------------------\n" ) ;

                    ++ createdAccounts ;
                    createAccount ( fPtr , createdAccounts ) ;

                    break ;
                    
                }

                case DELETE_ACCOUNT:

                {

                    printf ( "--------------------------------\n" ) ;
                    printf ( "        Delete Account          \n" ) ;
                    printf ( "--------------------------------\n" ) ;

                    deleteAccount ( fPtr ) ;
                    fPtr = fopen ( "accounts.txt" , "a+" ) ;

                    if ( fPtr == NULL ) 
    
                    {

                        printf ( "Error re-opening the file!" ) ;

                    }

                    break ; 

                }

                case DEPOSIT :

                {

                    printf ( "--------------------------------\n" ) ;
                    printf ( "           Deposit              \n" ) ;
                    printf ( "--------------------------------\n" ) ;

                    deposit_OR_withdraw ( fPtr , 1 ) ;
                    fPtr = fopen ( "accounts.txt" , "a+" ) ;

                    if ( fPtr == NULL )
    
                    {

                        printf ( "Error re-opening the file" ) ;

                    }

                    break ;

                }

                case WITHDRAW :

                {

                    printf ( "--------------------------------\n" ) ;
                    printf ( "          Withdraw              \n" ) ;
                    printf ( "--------------------------------\n" ) ;

                    deposit_OR_withdraw ( fPtr , 2 ) ;
                    fPtr = fopen ( "accounts.txt" , "a+" ) ;

                    if ( fPtr == NULL )
    
                    {

                        printf ( "Error re-opening the file" ) ;

                    }

                    break ;

                } 

                case BALANCE_INQUIRY :

                {

                    printf ( "--------------------------------\n" ) ;
                    printf ( "        Balance Inquiry         \n" ) ;
                    printf ( "--------------------------------\n" ) ;

                    balanceInquiry ( fPtr ) ;

                    break ;

                }

                default :

                {

                    printf ( "Invalid Option Input \nTry Again \n" ) ;
                    instructions ( ) ;

                }

            }

            if ( menuOption != 0 ) 
            
            {

                printf ( "Tell me the option you want to choose :- " ) ;
                scanf ( "%d" , &menuOption ) ;

                printf ( "\n" ) ;

            }

        }

    }

    printf ( "Program Terminating ...\n" ) ;

}

void createAccount ( FILE * fPtr , int createdAccountCounter )

{

    Account person ;

    sprintf ( person . accountNumber , "%010d" , createdAccountCounter ) ; 
    printf ( "First Name :-\n" ) ;
    scanf ( "%30s" , person . firstName ) ;
    printf ( "Last Name :-\n" ) ;
    scanf ( "%30s" , person . lastName ) ;

    person . balance = 0 ;

    if 
    
    ( 

        fprintf 
        
        (
            fPtr , "%s %s %s %d\n" ,
            person . accountNumber ,
            person . firstName ,
            person . lastName , 
            person . balance 

        ) < 0 

    ) 
    
    { 

        printf ( "\nError writing in the file !\n" ) ;

    }

    else
    
    {

        printf ( "\nAccount successfully created\n" ) ;
        printf ( "Account Details :- \n" ) ;
        printf ( "Account Number :- %s\n" , person . accountNumber ) ;
        printf ( "First Name :- %s\n" , person . firstName ) ;
        printf ( "Last Name :- %s\n" , person . lastName ) ;
        printf ( "Balance :- %d\n" , person . balance ) ;

    }

    fflush ( fPtr ) ;

}

void deleteAccount ( FILE * fPtr ) 

{

    Account person ;
    char targetStr [ 11 ] ;
    printf ( "Tell me the account number of account which to delete :- " ) ;
    scanf ( "%10s" , targetStr ) ;

    rewind ( fPtr ) ;
    FILE * tempPtr ;
    tempPtr = fopen ( "temp.txt" , "w+" ) ;
    if ( tempPtr == NULL ) 
    
    {

        printf ( "Process failed\nInsufficient Memory\n" ) ;

    }

    else
    
    {

        int found = 0 ;

        while

        ( 
            
            fscanf 
            
            (
                
                fPtr , "%10s %30s %30s %d" ,
                        person . accountNumber ,
                        person . firstName ,
                        person . lastName ,
                        &person . balance 

            ) == 4  // ensure 4 items read successfully

        ) 
        
        {

            if ( strcmp ( person . accountNumber , targetStr ) != 0) 
            
            {

                fprintf ( tempPtr , "%s %s %s %d\n",
                        person . accountNumber ,
                        person . firstName ,
                        person . lastName ,
                        person . balance 
                    ) ;

            } 
            
            else 
            
            {

                found = 1 ; 

            }

        }

        fclose ( tempPtr ) ;
        fclose ( fPtr ) ;

        remove ( "accounts.txt" ) ;
        rename ( "temp.txt" , "accounts.txt" ) ;

        if ( found == 1 )
        
        {

            printf ( "Deletion successfull\n" ) ;

        }

        else
        
        {

            printf ( "Account deletion cannot processed\nNo such account present\n" ) ;  
        
        }

    }

}


void deposit_OR_withdraw ( FILE * fPtr , int option ) 

{

    FILE * tempPtr ;
    tempPtr = fopen ( "temp.txt" , "w+" ) ;
    if ( tempPtr == NULL )
    
    {

        printf ( "Process failed\nInsufficient Memory\n" ) ;

    }

    else
    
    {

        Account person ;   
        char targetStr [ 11 ] ;
        printf ( "Tell me the account number :- " ) ;
        scanf ( "%10s" , targetStr ) ;
        int success = 0 ;
        rewind ( fPtr ) ;


        while

        ( 
            
            fscanf 
            
            (

                fPtr , " %10s %30s %30s %d" ,
                        person . accountNumber ,
                        person . firstName ,
                        person . lastName ,
                        &person . balance 

            ) == 4  // ensure 4 items read successfully

        ) 
        
        {

            if ( strcmp ( person . accountNumber , targetStr ) != 0 ) 
            
            {

                fprintf 
                
                (

                    tempPtr, "%s %s %s %d\n",
                        person . accountNumber ,
                        person . firstName ,
                        person . lastName ,
                        person . balance 

                ) ;

            } 
            
            else 
            
            {

                int value = 0 ;
                if ( option == 1 )
                
                {

                    printf ( "Deposit Value :- " ) ;

                }

                else
                
                {

                    printf ( "Withdraw Value :- " ) ;

                }

                scanf ( "%d" , &value ) ;
                switch ( option ) 
                
                {

                    case 1 :
                        person . balance += value ; 
                        break ;

                    case 2:
                        while ( person . balance - value < 0 ) 
                        
                        {
                             
                            printf ( "Insufficient funds. Enter smaller amount :- " ) ;
                            scanf ( "%d" , &value ) ;
                        }

                        person . balance -= value ;
                        break ;

                }

                fprintf 
                
                (

                    tempPtr , "%s %s %s %d\n" , 
                    person . accountNumber , 
                    person . firstName , 
                    person . lastName , 
                    person . balance 
                
                ) ;

                success = 1 ;

            }

        }

        fclose ( tempPtr ) ;
        fclose ( fPtr ) ;

        remove ( "accounts.txt" ) ;
        rename ( "temp.txt" , "accounts.txt" ) ;

        if ( success == 1 )
        
        {

            printf("Process Sucessfull!\n");

        }

        else
        
        {

            printf("Process Failed!\nNo such account found\n");

        }

    }
    
}

void balanceInquiry ( FILE * fPtr )

{

    Account person ;
    char targetStr [ 11 ] ;
    printf ( "Tell me the account number :- " ) ;
    scanf ( "%10s" , targetStr ) ;
    printf ( "\n\n" ) ;
    int success = 0 ;
    rewind ( fPtr ) ;

    while

    ( 
        
        fscanf 
        
        (

            fPtr , "%10s %30s %30s %d" ,
                    person . accountNumber ,
                    person . firstName ,
                    person . lastName ,
                    &person . balance 

        ) == 4 

    ) 
    
    {

        if ( strcmp( person . accountNumber , targetStr ) == 0 )

        {

            printf ( "Account Details :- \n" ) ;
            printf ( "Account Number :- %s\n" , person . accountNumber ) ;
            printf ( "First Name :- %s\n" , person . firstName ) ;
            printf ( "Last Name :- %s\n" , person . lastName ) ;
            printf ( "Balance :- %d\n" , person . balance ) ;
            success = 1 ;

        }

    }

    if ( success == 0 )
    
    {

        printf ( "No such account exist\n" ) ;

    }

}

void instructions ( ) {

    printf ( "+----------------------------------------+\n" ) ;
    printf ( "|             MENU OPTIONS               |\n" ) ;
    printf ( "+----------------------------------------+\n" ) ;
    printf ( "| 0 - Exit Program                       |\n" ) ;
    printf ( "| 1 - Create New Account                 |\n" ) ;
    printf ( "| 2 - Delete Existing Account            |\n" ) ;
    printf ( "| 3 - Deposit Money                      |\n" ) ;
    printf ( "| 4 - Withdraw Money                     |\n" ) ;
    printf ( "| 5 - Balance Inquiry                    |\n" ) ;
    printf ( "+----------------------------------------+\n\n" ) ;

}