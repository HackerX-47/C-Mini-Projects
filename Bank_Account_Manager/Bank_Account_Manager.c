// Bank Account Manager ‒ Create account, deposit/withdraw, balance inquiry ̶ using structs + filestorage
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct account{
    char accountNumber[11];
    char firstName[31];
    char lastName[31];
    int balance;
};

typedef struct account Account;

enum Options{
    EXIT,
    CREATE_ACCOUNT,
    DELETE_ACCOUNT,
    DEPOSIT,
    WITHDRAW,
    BALANCE_INQUIRY,
};

void createAccount(FILE *fPtr, int createdAccountCounter);
void deleteAccount(FILE *fPtr);
void deposit_OR_withdraw(FILE *fPtr);
void balanceInquiry(FILE *fPtr);

int main(void){

    int createdAccounts=0;
    FILE *fPtr=NULL;

    fPtr=fopen("accounts.txt","w+");

    if(fPtr==NULL){

        // not enough memory available

    }

    else{

        int menuOption=0;
        scanf("%d",&menuOption);

        while(menuOption!=0){

            switch(menuOption){

                case EXIT:

                {

                    // terminate program
                    break;

                }

                case CREATE_ACCOUNT:

                {

                    ++createdAccounts;
                    createAccount(fPtr,createdAccounts);
                    break;
                    
                }
                case DELETE_ACCOUNT:
                {
                    deleteAccount(fPtr);
                    fPtr=fopen("accounts.txt","a+");
                    break;
                }
                case DEPOSIT:
                {
                    deposit_OR_withdraw(fPtr);
                    fPtr=fopen("accounts.txt","a+");
                    break;
                }
                case WITHDRAW:
                {
                    deposit_OR_withdraw(fPtr);
                    fPtr=fopen("accounts.txt","a+");
                    break;
                }
                case BALANCE_INQUIRY:
                {
                    balanceInquiry(fPtr);
                    break;
                }
                default:
                {
                    // invalid menuOption
                }
            }
            if(menuOption!=0){
                scanf("%d",&menuOption);
            }
        }
    }
    // program terminating
}

void createAccount(FILE *fPtr, int createdAccountCounter){
    Account person ;
    sprintf(person.accountNumber,"%010d",createdAccountCounter);
    scanf("%30s",person.firstName);
    scanf("%30s",person.lastName);
    person.balance=0;
    fprintf(fPtr,"%s %s %s %d\n",person.accountNumber,person.firstName,person.lastName,person.balance);
    fflush(fPtr);
}

void deleteAccount(FILE *fPtr){
    Account person;
    char targetStr[11];
    scanf("%10s",targetStr);

    rewind ( fPtr ) ;
    FILE *tempPtr;
    tempPtr=fopen("temp.txt","w+");
    if(tempPtr==NULL){
        // error opening file
    }
    else{

        

        int found=0;
        while

        ( 
            
            fscanf ( fPtr , " %10s %30s %30s %d" ,
                        person.accountNumber ,
                        person.firstName ,
                        person.lastName ,
                        &person.balance 
                    ) == 4  // ensure 5 items read successfully

            ) 
        
        {

            // If name does NOT match, keep it in new file
            if (strcmp(person.accountNumber, targetStr) != 0) 
            
            {

                fprintf ( tempPtr, "%s %s %s %d\n",
                        person . accountNumber ,
                        person . firstName ,
                        person . lastName ,
                        person . balance 
                    ) ;

            } 
            
            else 
            
            {

                found = 1 ; // mark that we found a match

            }

        }

        fclose ( tempPtr ) ;
        fclose ( fPtr ) ;

        // Replace old contacts file with new one
        remove ( "accounts.txt" ) ;
        rename ( "temp.txt" , "accounts.txt" ) ;

        if(found==1){
            // account found, deletion sucessfull
        }
        else{
            // no such contact found
        }

    }
}


void deposit_OR_withdraw(FILE *fPtr){
    FILE *tempPtr;
    tempPtr=fopen("temp.txt","w+");
    if(tempPtr==NULL){
        // not enough memory available
    }
    else{
        Account person;   
        char targetStr[11];
        scanf("%10s",targetStr);
        int success=0;
        rewind(fPtr);


        while

        ( 
            
            fscanf ( fPtr , " %10s %30s %30s %d" ,
                        person.accountNumber ,
                        person.firstName ,
                        person.lastName ,
                        &person.balance 
                    ) == 4  // ensure 5 items read successfully

            ) 
        
        {

            // If name does NOT match, keep it in new file
            if ( strcmp(person.accountNumber, targetStr) != 0 ) 
            
            {

                fprintf ( tempPtr, "%s %s %s %d\n",
                        person . accountNumber ,
                        person . firstName ,
                        person . lastName ,
                        person . balance 
                    ) ;

            } 
            
            else 
            
            {

                int value=0;
                int option=0;
                scanf("%d", &option);
                while (option != 1 && option != 2) {
                    printf("Invalid Option Chosen, Try Again: ");
                    scanf("%d", &option);
                }

                scanf("%d", &value);
                switch (option) {
                    case 1:
                        person.balance += value; // deposit
                        break;

                    case 2:
                        while (person.balance - value < 0) {
                            printf("Insufficient funds. Enter smaller amount: ");
                            scanf("%d", &value);
                        }
                        person.balance -= value;
                        break;
                }

                fprintf(tempPtr,"%s %s %s %d\n",person.accountNumber,person.firstName,person.lastName,person.balance);
                success=1;

            }

        }

        fclose ( tempPtr ) ;
        fclose ( fPtr ) ;

        // Replace old contacts file with new one
        remove ( "accounts.txt" ) ;
        rename ( "temp.txt" , "accounts.txt" ) ;

        if(success==1){
            // account found, operation sucessfull
        }
        else{
            // no such contact found
        }
    }
    
}

void balanceInquiry(FILE *fPtr){
    Account person;
    char targetStr[11];
    scanf("%10s",targetStr);
    int success=0;
    rewind(fPtr);

    while

    ( 
        
        fscanf ( fPtr , " %s %s %s %d" ,
                    person.accountNumber ,
                    person.firstName ,
                    person.lastName ,
                    &person.balance 
                ) == 4  // ensure 5 items read successfully

        ) 
    
    {

        // If name does NOT match, keep it in new file
        if ( strcmp(person.accountNumber, targetStr) == 0 )
        {
            printf("Account Details :- \n");
            printf("Account Number :- %s\n",person.accountNumber);
            printf("First Name :- %s\n",person.firstName);
            printf("Last Name :- %s\n",person.lastName);
            printf("Balance :- %d\n",person.balance);
            success=1;
        }

    }
    if(success==0){
        // no account found
    }
}