#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int computer(int score);



// Simulates user by entering random numbers
int user(int score)
{
    int i=rand() %2+1; // Random number Alternative
    printf("We're at %d User adds %d\n",score,i);
    return(i);
}


void game(void)
{
    // makes use of the computer's internal clock to control the choice of the seed
    srand(time(NULL));
    
    int i = 0;
    int score = 0;
    int choice = 0; //0 for computer to start first 1 for user to star first
    
    printf("Who says first 20 \n \n");
    
    if (choice) { 
        score = user(score);
    }
    else {
        score = computer(score);
    }
    
   
    while (score <= 20) {
        score += user(score);

        if (score>=20) {
            printf("USER WINS !!\n ");
            break;
        }
        score += computer(score);
        if (score>=20) {
            printf("COMPUTER WINS !! \n ");
            break;
        }
    }  
}




int computer(int score)
{

    //comp wants to say: 2, 5, 8, 11, 14, 17, 20
    int i;
    int diff = 20 - score; 
    if (score+2==2 || score+2==5 || score+2==8 || score+2==11 || score+2==14|| score+2==17 || score+2==20)
    {
        i = 2;
    }

    else if (score+1==2 || score+1==5 || score+1==8 || score+1==11 || score+1==14|| score+1==17 || score+1==20)
    {
        i = 1;
    }

    printf("We're at %d Computer adds %d\n",score,i);
    return(i); 
}






int main(void)
{
    game();
    return(0);
}
