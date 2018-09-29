/*Nicole Karam Pannaci
EGN 3211-003
HOMEWORK 3B - Creating a game "Guessing the number"*/
//statements needed for this code 
#include<stdio.h>
#include<stdlib.h>
//#include<time.h> was used to generate a random number every time it is run
#include<time.h>
char question(char);

int main() 
{
  //stating all the int
  int number,  digit=10, guess=0;
  /*setting up the random number generator- to check if the code by itself was correct the guess was set up as 1+ rand() % 10; to guess the number faster*/
  srand(time(NULL));
  guess = 5; //1+ rand() % 10;

    //stating the character to continue or break the game 
    char confirm;

    //user input of the first number
    printf("I have a number between 1 and 1000.\nCan you guess my number?\nPlease type your first guess!");
    scanf("%d", &number);
    fflush(stdin);

    //while loop to keep the game running until you win the game
    while(digit)
	{
      /*if statements for bigger, lower, or equal to the guessing number and everytime it is bigger or smaller it forces the user to input a different number which changes the previous input with the new input until it reaches to equal*/
	    if (number < guess)
		{
	    	puts("Too low. Try again");
	    	scanf("%d", &number);
	    	fflush(stdin);
        }
	    else if(number > guess)
		{
	    	puts("Too high. Try again");
        	scanf("%d", &number);
        	fflush(stdin);
     	}
		else 
		{
        	/*this following statement prints AGAIN after you type y or n*/
        	printf("Excellent! You guessed the number!\n Would you like to play again <y or n>? ");
		    scanf("%c", &confirm);
        }
    
		//If statements to break the code or to repeat the game again
        
        if (confirm == 'n')
		{
        	break;
		}
        else if (confirm == 'y')
		{
			printf("\n\n");
            return main();
		}
    }
}

  	

char question ( char letter){
  
}
