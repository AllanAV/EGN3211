/*
UCF EGN 3211
FALL 2018
Prof. Sundar Sinnappan
*** Homework 6B ***
by Allan Aquino Vieira

*/

#include <stdio.h>
#include <stdlib.h>

#define x86Str 36

//Function Prototype
void packCharacter(char source, unsigned int *dataPtr);
void byteRepresentation(unsigned int number);

int main(void)
{
	//Main Local Variables 
	char char1 = '0';
	char char2 = '0';
	char char3 = '0';
	char char4 = '0';
	unsigned int data = 0;
	unsigned int RepSizeInBits = sizeof(data)*8;
	printf("\n%u\n", RepSizeInBits);
	char binaryRep[(RepSizeInBits+4+1)];
	
	printf("Enter the first character : ");
	char1 ='K';// getchar();
	fflush(stdin);
	
	printf("Enter the secon character : ");
	char2 ='L';// getchar();
	fflush(stdin);
	
	printf("Enter the third character : ");
	char3 ='M';// getchar();
	fflush(stdin);
	
	printf("Enter the fourth character : ");
	char4 ='N';// getchar();
	fflush(stdin);
	puts("");
	
	
	printf("\nResult before shifting and replacing last 8 bits with %c\n", char1);
	byteRepresentation(data);
	byteRepresentationOnString(data, binaryRep);
	printf("%10u =%s\n",data, binaryRep);
	packCharacter(char1, &data);
	printf("\nResult after shifting and replacing last 8 bits with %c\n", char1);
	byteRepresentation(data);
	byteRepresentationOnString(data, binaryRep);
	printf("%10u =%s\n",data, binaryRep);
	
	printf("\nResult before shifting and replacing last 8 bits with %c\n", char2);
	byteRepresentation(data);
	byteRepresentationOnString(data, binaryRep);
	printf("%10u =%s\n",data, binaryRep);
	packCharacter(char2, &data);
	printf("\nResult after shifting and replacing last 8 bits with %c\n", char2);
	byteRepresentation(data);
	byteRepresentationOnString(data, binaryRep);
	printf("%10u =%s\n",data, binaryRep);
	
	printf("\nResult before shifting and replacing last 8 bits with %c\n", char3);
	byteRepresentation(data);
	byteRepresentationOnString(data, binaryRep);
	printf("%10u =%s\n",data, binaryRep);
	packCharacter(char3, &data);
	printf("\nResult after shifting and replacing last 8 bits with %c\n", char3);
	byteRepresentation(data);
	byteRepresentationOnString(data, binaryRep);
	printf("%10u =%s\n",data, binaryRep);
	
	printf("\nResult before shifting and replacing last 8 bits with %c\n", char4);
	byteRepresentation(data);
	byteRepresentationOnString(data, binaryRep);
	printf("%10u =%s\n",data, binaryRep);
	packCharacter(char4, &data);
	printf("\nResult after shifting and replacing last 8 bits with %c\n", char4);
	byteRepresentation(data);
	byteRepresentationOnString(data, binaryRep);
	printf("%10u =%s\n",data, binaryRep);
	
	return 0;
}

void byteRepresentationOnString(unsigned int number, char string[x86Str])
{
	//byteRepresentationOnString Varaibles
	unsigned int mask = 1<<31;
	
	for(int i = 31, j = 0; i >= 0; --i, ++j)
	{
		if (((j+1)%9) == 0)
		{
			string[j] = ' ';
			++j;
			//printf(" ");//TEST PURPOSES
		}
		
		if((mask&number))
		{
			string[j] = '1';
			//printf("T");//TEST PURPOSES
		}
		else
		{
			string[j] = '0';
			//printf("F");//TEST PURPOSES
		}
		string[j+1] = '\0';
		
		mask >>= 1;
	}
}

void byteRepresentation(unsigned int number)
{
	//byteRepresentation Varaibles
	unsigned int mask = 1<<31;
	
	printf("%10u =", number);
	
	for(int i = 31; i >= 0; --i)
	{
		if((mask&number))
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
		mask >>= 1;
		if ((i%8) == 0)
		{
			printf(" ");
		}
	}
	puts("");
	
}

void packCharacter(char letter, unsigned int *dataPtr)
{
	*dataPtr <<= 8;
	//printf("\n%u ^ %c",*dataPtr, letter);//TEST PURPOSES
	*dataPtr ^= (unsigned int)letter;
	//printf(" = %u\n",*dataPtr);//TEST PURPOSES
}
