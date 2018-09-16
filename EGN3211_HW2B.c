/*
UCF EGN 3211
FALL 2018
Prof. Sundar Sinnappan
*** Homework 2B ***
by Allan Aquino Vieira
*/

#include <stdio.h>

//Definitions
#define CLRIN fflush(stdin)

int main (void)
{
	//Local Variable Declaration & Initiation
	int factorial = 1;
	
	do{
			
		printf("Please enter number between 1 and 10 for factorial calculation (-1 to end) :");
		scanf("%d", &factorial);
		CLRIN;
		
		//Loop Local Variable Declaration & Initiation
		int sum = factorial;
		
		if(factorial != -1)
		{
		
			for(unsigned int i = 1;i<= (factorial - 1);i++)
			{
				sum *= (factorial - i);
			}
			
			printf("factorial for %u is %u\n\n", factorial, sum);
		}
		
	}while(factorial != -1);
	
	return 0;
}
