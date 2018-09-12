/*
UCF EGN 3211
FALL 2018
Prof. Sundar Sinnappan

*** Homework 1A ***
by Allan Aquino Vieira
*/

#include<stdio.h>

//Definitions
#define CLEAR fflush(stdin)

int main (void)
{
	//Local Variable Declarations and Initiations
	unsigned int entries = 1;
	int sum = 0;
	
	
	printf("Please enter number of values to be entered :");
	scanf("%u", &entries);
	CLEAR;
	
	for(unsigned int i = 1; i<= entries; i++)
	{
		//Loop Local Variable Declarations and Initiations
		int input = 0;
		
		printf("Please enter #%d :",i);
		scanf("%d", &input);
		CLEAR;
		
		sum += input;
	}
	
	printf("The total is %d",sum);
}
