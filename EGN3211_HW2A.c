/*
UCF EGN 3211
FALL 2018
Prof. Sundar Sinnappan
*** Homework 2A ***
by Allan Aquino Vieira
*/

#include<stdio.h>

//Definitions
#define CLRIN fflush(stdin)

int main (void)
{
	//Local Variable Declarations and Initiations
	unsigned int entries = 1;
	int sum = 0;
	
	
	printf("Please enter number of values to be entered :");
	scanf("%u", &entries);
	CLRIN;
	
	for(unsigned int i = 1; i<= entries; i++)
	{
		//Loop Local Variable Declarations and Initiations
		int input = 0;
		
		printf("Please enter #%d :",i);
		scanf("%d", &input);
		CLRIN;
		
		sum += input;
	}
	
	printf("The total is %d",sum);
}
