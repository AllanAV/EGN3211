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
float StdDev (int data[], int size);
void adjustScores(int data[], int size, float SD);
void bubleSort(int data[], int size);

int main (void)
{
	//Main Local Variables Declaration and Initialization
	int examScores[SIZE] = {80, 82, 90, 95, 90, 87, 92};
	float sigma = 0.0;
	
	printf("Exam scores:");
	for(int i = 0; i< SIZE; i++)
	{
		printf(" %d", examScores[i]);
	}
	puts("");
	
	sigma = StdDev (examScores, SIZE);
	
	printf("\nStandard deviation: %.4f\n", sigma);
	
	adjustScores(examScores, SIZE, sigma);
	
	printf("\nAdjusted exam scores:");
	for(int i = 0; i< SIZE; i++)
	{
		printf(" %d", examScores[i]);
	}
	puts("");
	
	bubleSort(examScores, SIZE);
	
	printf("\nSorted exam scores:");
	for(int i = 0; i< SIZE; i++)
	{
		printf(" %d", examScores[i]);
	}
	
	return 0; 
}

float StdDev (int data[], int size)
{
	//Function Local Variables Declaration and Initialization
	int sum = 0;
	int localArray[size];
	float mean = 0;
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
	mean = ((float) sum)/size;
	//Output for testing purpuses
	//printf("\nMean is %.4f\n", mean);
	
	sum = 0;
	/*
	Mean of the Squared Differences. 
	*/
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
	SD = sqrt(((float)sum)/size);
	
	return SD;
}

void adjustScores(int data[], int size, float SD)
{
	for(int i = 0; i< SIZE; i++)
	{
		data[i] +=((int)round(SD));
		
		if (data[i] > 100)
		{
			data[i] = 100;
			//Output for testing purpuses
			//printf(" ovr");
		}
	}
}

void bubleSort(int data[], int size)
{
	//Function Local Variables Declaration and Initialization
	int swap = 0;
	
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
