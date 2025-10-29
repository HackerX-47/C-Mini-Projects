//contact book program
#include<stdio.h>
#include<string.h>

struct contact

{

    char firstName [ 20 ] ;
    char lastName [ 20 ] ;
    char countryCode [ 5 ] ;
    char contactNumber [ 16 ] ;
    char email [ 50 ] ;

} ;

typedef struct contact Contact ;

void opening ( ) ;
void instructions ( ) ;
void addContact ( Contact *person , FILE *fPtr ) ;
int searchContact ( FILE *fPtr ) ;
void deleteContact ( Contact *person , FILE *fPtr ) ;
void saveToContactBook ( Contact *person , FILE *fPtr ) ;
void displayContactBook ( Contact *person , FILE *fPtr ) ;

enum choices 

{

    EXIT ,
    SEARCH_CONTACT ,
    ADD_CONTACT ,
    DELETE_CONTACT

};

int main ( void ) 

{

    opening ( ) ;

    instructions ( ) ;

    Contact person = { 0 } ;

    FILE *fPtr = NULL ;
    fPtr = fopen ( "contacts.txt" , "w+" ) ;

    if ( fPtr == NULL )
    
    {

        printf ( "No such file exists\n" ) ;

    }

    else
    
    {

        int choice = 0 ;
        printf ( "%s" , "Choice :- " ) ;
        scanf ( "%d" , &choice ) ;
        printf ( "\n" ) ;


        while ( choice != 0 ) 
        
        {
            switch ( choice ) 
            
            {

                case EXIT:

                    {

                        printf("\nProgram Terminating ...\n");
                        break;

                    }

                case SEARCH_CONTACT:

                    {

                        printf("%s\n","You have opted for search contacts");
                        searchContact(fPtr);

                        break;

                    }

                case ADD_CONTACT:

                    {

                        printf("%s\n","You have opted for add contacts");
                        addContact(&person,fPtr);

                        break;

                    }

                case DELETE_CONTACT:

                    {

                        printf("%s\n","You have opted for delete contacts");
                        deleteContact(&person,fPtr);

                        break;

                    }

                default:

                    {

                        printf("\n%s\n","Invalid choice! Please select a valid option"); 
                        instructions();

                        break;

                    }

            }

            if ( choice != 0 )
            {

                printf ( "\n%s" , "Choice :- " ) ;
                scanf ( "%d" , &choice ) ;

            }

        }

    }

    fclose(fPtr);

}

int searchContact ( FILE *fPtr ) 

{

    char searchFirstName [ 20 ] ;
    Contact person ;
    int found = 0 ;
    printf ( "Enter first name to search :- " ) ;
    scanf ( "%19s" , searchFirstName ) ;
    rewind ( fPtr ) ;
    while ( fscanf ( fPtr , "%19s %19s %4s %15s %49s" ,
                person.firstName ,
                person.lastName ,
                person.countryCode ,
                person.contactNumber ,
                person.email) == 5)
    
    {

        if ( strncmp ( searchFirstName , person . firstName , 20 ) == 0 )
        
        {

            printf ( "Contact Found,\n" ) ;
            printf ( "%-19s %-19s %-19s %-19s %-49s\n\n" , "First Name" , "Last Name" , "Country Code" , "Contact Number" , "Email Address" ) ;

            printf ( "%-19s %-19s %-19s %-19s %-49s\n" ,
                person.firstName ,
                person.lastName ,
                person.countryCode ,
                person.contactNumber ,
                person.email ) ;

            found = 1 ;

        }

    }

    if ( !found )
    
    {

        printf ( "No such contact found\n" ) ;

    }

    return found ;

}

void addContact ( Contact *person , FILE *fPtr )

{

    printf ( "First Name :- " ) ;
    scanf ( "%19s" , person -> firstName ) ;

    printf ( "Last Name :- " ) ;
    scanf ( "%19s" , person -> lastName ) ;

    printf ( "Country Code :- " ) ;
    scanf ( "%4s" , person -> countryCode ) ;

    printf ( "Contact Number :- " ) ;
    scanf ( "%15s" , person -> contactNumber ) ;

    printf ( "Email :- " ) ;
    scanf ( "%49s" , person -> email ) ;
    
    fprintf ( fPtr , "%19s %19s %4s %15s %49s\n" ,
        person -> firstName ,
        person -> lastName ,
        person -> countryCode ,
        person -> contactNumber ,
        person -> email ) ;
    
    rewind ( fPtr ) ;

    displayContactBook ( person , fPtr ) ;

}



void deleteContact ( Contact *person , FILE *fPtr ) 

{

    char targetName [ 20 ] ;
    int found = 0 ;

    // Ask which contact to delete
    printf ( "Enter first name of contact to delete :- " ) ;
    scanf ( "%19s" , targetName ) ;

    FILE *tempFile = fopen ( "temp.txt" , "w+" ) ; // temporary file to store remaining contacts

    if ( tempFile == NULL ) 
    
    {

        printf("Error opening temporary file.\n");
        return;

    }

    rewind ( fPtr ) ; // go to start of original file

    // Read all contacts one by one
    while

    ( 
        
        fscanf ( fPtr , "%19s %19s %4s %15s %49s" ,
                    person -> firstName ,
                    person -> lastName ,
                    person -> countryCode ,
                    person -> contactNumber ,
                    person -> email ) == 5  // ensure 5 items read successfully

        ) 
    
    {

        // If name does NOT match, keep it in new file
        if ( strcmp ( person -> firstName , targetName ) != 0 ) 
        
        {

            fprintf ( tempFile, "%19s %19s %4s %15s %49s\n",
                    person -> firstName ,
                    person -> lastName ,
                    person -> countryCode ,
                    person -> contactNumber ,
                    person -> email ) ;

        } 
        
        else 
        
        {

            found = 1 ; // mark that we found a match

        }

    }

    fclose ( tempFile ) ;
    fclose ( fPtr ) ;

    // Replace old contacts file with new one
    remove ( "contacts.txt" ) ;
    rename ( "temp.txt" , "contacts.txt" ) ;

    if ( found )
    
    {

        printf("Contact deleted successfully!\n");

    }
        
    else
    
    {

        printf("No contact found with the name '%s'.\n", targetName);

    }

    // Reopen main file in append+read mode for future operations
    fPtr = fopen("contacts.txt", "a+");

    if ( fPtr == NULL ) 
    
    {

        printf("Error reopening contacts file.\n");

    }

    displayContactBook(person,fPtr);

}

void displayContactBook ( Contact *person , FILE *fPtr ) 

{

    rewind ( fPtr ) ;
    int count = 0 ;
    printf ( "\n\n" ) ;
    printf ( "Contact Book :- \n\n" ) ;
    printf ( "%-19s %-19s %-19s %-19s %-49s\n\n" , "First Name" , "Last Name" , "Country Code" , "Contact Number" , "Email Address" ) ;
    while ( fscanf ( fPtr , "%19s %19s %4s %15s %49s" ,
                  person -> firstName ,
                  person -> lastName ,
                  person -> countryCode ,
                  person -> contactNumber ,
                  person -> email ) == 5)

    {

        printf ( "%-19s %-19s %-19s %-19s %-49s\n" ,
               person -> firstName ,
               person -> lastName ,
               person -> countryCode ,
               person -> contactNumber ,
               person -> email ) ;
        count++ ;
    }

    if ( count == 0 ) 
    
    {

        printf ( "No contacts found.\n" ) ;

    }

}

void instructions() 

{
    
    printf ( "Welcome! This program allows you to store,\n" ) ;
    printf ( "view, search, and delete contacts easily.\n\n" ) ;

    printf ( "Available options:\n" ) ;
    printf ( "  0 - Exit the program\n" ) ;
    printf ( "  1 - Search for an existing contact by first name\n" ) ;
    printf ( "  2 - Add a new contact (first name, last name, country code, number, email)\n" ) ;
    printf ( "  3 - Delete a contact by first name\n\n" ) ;

    printf ( "How to use:\n" ) ;
    printf ( "  -- Run the program — this menu will appear.\n" ) ;
    printf ( "  -- Enter the number corresponding to the action you want to perform.\n" ) ;
    printf ( "  -- Follow on-screen prompts to enter contact details.\n");
    printf ( "  -- Contacts are saved to a file named 'contacts.txt'.\n\n" ) ;

    printf ( "Note:\n" ) ;
    printf ( "  -- The contact list resets each time the program restarts (file is overwritten).\n" ) ;
    printf ( "  -- Enter 0 anytime in choices to exit safely.\n" ) ; 

    printf ( "=====================================\n\n" ) ;

}

void opening ( ) 

{

    printf ( "\n=====================================\n" ) ;
    printf ( "         CONTACT BOOK PROGRAM        \n" ) ;
    printf ( "=====================================\n\n" ) ;

}