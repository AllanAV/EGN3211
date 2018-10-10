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
#define SIZE 7

//Function Prototypes
float StdDev (float data[], int size);
void adjustScores(float data[], int size, float SD);
void bubleSort(float data[], int size);

int main (void)
{
	//Main Local Variables Declaration and Initialization
	float examScores[SIZE] = {80, 82, 90, 95, 90, 87, 92};
	float sigma = 0.0;
	
	printf("Exam scores:");
	for(int i = 0; i< SIZE; i++)
	{
		printf(" %.0f", examScores[i]);
	}
	puts("");
	
	sigma = StdDev (examScores, SIZE);
	
	printf("\nStandard deviation: %.4f\n", sigma);
	
	adjustScores(examScores, SIZE, sigma);
	
	printf("\nAdjusted exam scores:");
	for(int i = 0; i< SIZE; i++)
	{
		printf(" %.0f", examScores[i]);
	}
	puts("");
	
	bubleSort(examScores, SIZE);
	
	printf("\nSorted exam scores:");
	for(int i = 0; i< SIZE; i++)
	{
		printf(" %.0f", examScores[i]);
	}
	
	return 0; 
}

float StdDev (float data[], int size)
{
	//Function Local Variables Declaration and Initialization
	float sum = 0;
	float localArray[size];
	float mean = 0.0;
	float SD  = 0.0;
	
	/*
	Array Elements Summation
	*/
	for(int i = 0; i < size; i++)
	{
		localArray[i] = data[i];
		sum += data[i];
		//Output for testing purpuses
		//printf(" %d", sum);
	}
	
	/*
	Score Mean Calculation
	*/
	mean = sum/((float)size);
	//Output for testing purpuses
	//printf("\nMean is %.4f\n", mean);
	
	/*
	Mean of the Squared Differences. 
	*/
	sum = 0.0;
	//Output for testing purpuses
	//printf("Mean of the squared diferences:");
	for(int i = 0; i < size; i++)
	{
		localArray[i] = pow((data[i] - mean),2);
		//Output for testing purpuses
		//printf(" %d", data[i]);
		sum += localArray[i];
	}
	//Output for testing purpuses
	//printf("\nSum of the square diferences: %d", sum);
	
	/*
	Standard Deviation. 
	*/
	SD = sqrt(sum/((float)size));
	
	return SD;
}

void adjustScores(float data[], int size, float SD)
{
	for(int i = 0; i< SIZE; i++)
	{
		data[i] += SD;//round(SD));
		
		if (data[i] > 100)
		{
			data[i] = 100.0;
			//Output for testing purpuses
			//printf(" ovr");
		}
	}
}

void bubleSort(float data[], int size)
{
	//Function Local Variables Declaration and Initialization
	float swap = 0;
	
	while(size != 0)
	{
		for(int i = 0; i < (size - 1); i++)
		{
			if(data[i] > data[i+1]) 
			{
				swap = data[i];
				data[i] = data[i+1];
				data[i+1] = swap;
			}
		}
		size--;
	}
}
