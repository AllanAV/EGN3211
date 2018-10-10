/*
UCF EGN 3211
FALL 2018
Prof. Sundar Sinnappan
*** Homework 4B ***
by Allan Aquino Vieira
*/

#include<stdio.h>


//Function Prototypes
void createReserveArray(int originalArray[], int copyArray[], int size);
int compareArray(int originalArray[],int copyArray[], int size);
void printArray(int array[], int size);
void palindromeOrNot(int palindrome); //See comment above function

int main (void)
{
	//Main Local Variables Declaration and Initialization
	int myArray1[] = {1,2,3,2,1};
	int myArray2[] = {1,2,3,4,1};
	int myArray3[] = {1,2,3,3,2,1};
	int myArray4[] = {1,2,3,4,2,1};
	
	int size = 0;
	int palindrome  = 0;
	int copyArray1[] = {0,0,0,0,0};
	int copyArray2[] = {0,0,0,0,0};
	int copyArray3[] = {0,0,0,0,0,0};
	int copyArray4[] = {0,0,0,0,0,0};
	
	for(int i = 0; i <= 4; i++)
	{
		switch(i)
		{
			case 1:
				size = 5;
				createReserveArray(myArray1,copyArray1,size);
				palindrome = compareArray(myArray1,copyArray1,size);
				printArray(myArray1,size);
				//palindromeOrNot(palindrome);
				if(palindrome == 0)
				{
					printf("The Array is a palindrome");
				}
				else
				{
					printf("The Array is not a palindrome");
				}
				printf("\n\n");
				break;
			case 2:
				size = 5;
				createReserveArray(myArray2,copyArray2,size);
				palindrome = compareArray(myArray2,copyArray2,size);
				printArray(myArray2,size);
				//palindromeOrNot(palindrome);
				if(palindrome == 0)
				{
					printf("The Array is a palindrome");
				}
				else
				{
					printf("The Array is not a palindrome");
				}
				printf("\n\n");
				break;
			case 3:
				size = 6;
				createReserveArray(myArray3,copyArray3,size);
				palindrome = compareArray(myArray3,copyArray3,size);
				printArray(myArray3,size);
				//palindromeOrNot(palindrome);
				if(palindrome == 0)
				{
					printf("The Array is a palindrome");
				}
				else
				{
					printf("The Array is not a palindrome");
				}
				printf("\n\n");
				break;
			case 4:
				size = 6;
				createReserveArray(myArray4,copyArray4,size);
				palindrome = compareArray(myArray4,copyArray4,size);
				printArray(myArray4,size);
				//palindromeOrNot(palindrome);
				if(palindrome == 0)
				{
					printf("The Array is a palindrome");
				}
				else
				{
					printf("The Array is not a palindrome");
				}
				printf("\n\n");
				break;
		}
	}
	
	//TESTING PURPUSE
	//printf("Size of myArray1 is %d\n", sizeof(myArray1));
	//printf("Size of element 0 of myArray1 is %d\n", sizeof(myArray1[0]));
	//printf("Number of elements on myArray1 is %d\n\n", sizeof(myArray1)/sizeof(myArray1[0]));
	
	return 0;
}

void createReserveArray(int originalArray[], int copyArray[], int size)
{
	for(int i=0, j=(size-1); i < size; i++, j--)
	{
		copyArray[i] = originalArray[j];
		//TESTING PURPUSE
		//printf("%d | %d\n", copyArray[j], originalArray[i]);
	}
}

int compareArray(int originalArray[],int copyArray[], int size)
{
	//TESTING PURPUSE
	//compareArray Local Variables Declaration and Initialization
	int comparison=0;
	
	for(int i=0; i < size; i++)
	{
		//TESTING PURPUSE
		//printf("originalArray[%d] is %d and copyArray[%d] is %d\n",i,originalArray[i],i,copyArray[i]);
		if(originalArray[i] != copyArray[i])
		{
			comparison += 1;
			//printf("}%d{ ", comparison);
		}
	}
	//TESTING PURPUSE
	//printf("\n%d\n", comparison);
	return comparison;
}

void printArray(int array[], int size)
{
	printf("Array elements are:");
	for(int i=0; i < size; i++)
	{
		printf(" %d", array[i]);
	}
	puts("");
}
/*
Function was not used because Homework 4 Requirements states:
- "These functions should be called from main to perform the necessary operation"
- "return value in the main program to print out the status of the array"
Homework 4 Requirements (1) clearly stated the expected functions 
(2) print out the status of the array is preceded by expectation of "return value" 
suggests that print out the status must take place within main.

Function was intentionally left in the code to demonstrate a more efficient and organized 
method of achieveing the same goal. However the most efficient methor of performing the 
assigned tasks would be including the functionality of the three functions into a 
sigle function.
*/
void palindromeOrNot(int palindrome)
{
	if(palindrome == 0)
				{
					printf("The Array is a palindrome");
				}
				else
				{
					printf("The Array is not a palindrome");
				}
				printf("\n\n");
}
