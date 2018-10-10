/*
UCF EGN 3211
FALL 2018
Prof. Sundar Sinnappan
*** Homework 4A ***
by Allan Aquino Vieira
*/

#include<stdio.h>
#include<math.h>

//Definitions
#define SIZE 7 // ERROR
//int SCR_SZE =  7;

//Function Prototype
float StandardDeviation (int examScores[], int SIZE);
//int Appaly_Curve ();

int main (void)
{
	//Main Local Variable Declaration and Initialization
	int examScores[SIZE] = {80, 82, 90, 95, 90, 87, 92};
	float stdDev = 0.00;
 	
 	printf("Exam scores:");
 	
 	for(int i = 0; i <= 7; i++)
 	{
 		printf(" %d", examScores[i]);
	}
	printf("\n");
 	
 	stdDev = StandardDeviation(examScores,7);
 	
 	
 	return 0;
}

float StandardDeviation (int data[], int SIZE)
{
	//StandatdDeviation Function Local Variable Declaration and Initialization
	int sum = 0;
	
	for (int i =0; i <= SIZE; i++)
	{
		sum += data[i];
		printf("%d ",sum);
	}
	
	float sigma = sqrt(1/SIZE);
	return sigma;
}
