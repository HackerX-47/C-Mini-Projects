#include<stdio.h>


enum Choice{
    PLAY_GAME,
    ADD_QUESTION,
    EXIT
};
void instructions();
void playGame(FILE *fPtr);
void addQuestion(FILE *fPtr);
void checkAnswer(FILE *fPtr);

int main(void){
    FILE *fPtr=NULL;
    fPtr=fopen("Questions.txt","a+");
    int choice=0;
    scanf("%d",&choice);
    while(choice!=0){
        switch(choice){
            case EXIT:
                {
                    // opted for terminating program
                    break;
                }
            case PLAY_GAME:
                {
                    playGame(fPtr);
                    break;
                }
            case ADD_QUESTION:
                {
                    addQuestion(fPtr);
                    break;
                }
            default:
                {
                    // wrong option opted
                    instructions();
                }
        }
        if(choice!=0){
            scanf("%d",&choice);
        }
    }
    printf("Program terminating ...");
}

void addQuestion(FILE *fPtr){
    rewind(fPtr);
    
}