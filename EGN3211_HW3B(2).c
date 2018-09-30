/*
UCF EGN 3211
FALL 2018
Prof. Sundar Sinnappan
*** Homework 3B ***
by Allan Aquino Vieira
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Functions Prototyping
int userInput (int select);
int genRand(void);

//Global Variable Declaration and Initialization
	//Configure Minimum and Maxmum Parameters for Random Number 
	int randFloor = 1;
	int randCeling = 1000;

int main(void)
{	
	//Main Local Variable Declaration and Initialization
	char selection = 'y';
	
	while (selection != 'n')
	{	
		//While Loop Local Variable Declaration and Initialization
		int guess = -1;
		int randomNumber = genRand();
		
		printf("I have a number between %d and %d.\n", randFloor, randCeling);
		puts("Can you guess my number?");
		printf("Please type your first guess :");	
		
		do
		{
			guess = userInput (1);
			
			if(guess < randomNumber)
			{
				puts("Too low. Try again.");
			}
			else if (guess > randomNumber)
			{
				puts("Too high. Try again.");
			}
			else
			{
				puts("Excelent! You guessed the number!");
				printf("Would you like to play again (y or n)?");
				//Store An INT Into A CHAR Variable 
				selection = userInput (2);
				puts("");
			}
		}while(guess != randomNumber);
		
		guess = -1;
	}
	
	return 0;
}

/*
genRand Function Used To Generate a Time Based Seed Random Number
*/
int genRand(void)
{
	//Ramdom Number Generator Seeding
	srand(time(NULL));
	
	int randomNumber = randFloor + (rand() % randCeling);
	
	//Output for Testing
	//printf("The random numbeer is %d\n\n", randomNumber);
	
	return randomNumber;
}

int userInput (int select)
{
	//Imput Function Variable Declaration and Initialization
	int userEntry = 0;
	int repeat = 1;
	
	switch(select)
	{
		/*
		CASE 1
		Receives a Numerical Entry 
		Entry Used In Number Guessing Section
		*/
		case 1:
			scanf("%d",&userEntry);
			fflush(stdin);
			break;
		/*
		CASE 2 
		Receives Alpha Character And Checks For Entry Validity 
		Entry Used In The Repeat Selection 
		*/
		case 2:
			do
			{	
				//Store a CHAR Into An INT Variable
				scanf("%c",&userEntry);
				fflush(stdin);
				
				//Output For Testing Purposes
				//printf("\nDO >>> %c <<<\n", userEntry);
				
				switch(userEntry)
				{
					case 'Y':
					case 'y':
						//Output For Testing Purposes
						//puts("CASE Y");
						userEntry = 'y';
						repeat = 0;
						break;
					case 'N':
					case 'n':
						//Output For Testing Purposes
						//puts("CASE N");
						userEntry = 'n';
						repeat = 0;
						break;
					default:
						printf("%c is not a valid entry.\nWould you like to play again (y or n)?", userEntry);
						repeat = 1;
						break;
				}
			}while(repeat);
			
			break;
	}
	return userEntry;
}
