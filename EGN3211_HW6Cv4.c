/*
UCF EGN 3211
FALL 2018
Prof. Sundar Sinnappan
*** Homework 6C ***
by Allan Aquino Vieira

*/

#include <stdio.h>
#include <stdlib.h>

//Function Prototype
void packCharacter(char source, unsigned int *dataPtr);
void byteRepresentation(unsigned int number);
void byteRepresentationOnString(unsigned int strMaxLen, unsigned int number, char string[strMaxLen]);

int main(void)
{
	//Main Local Variables 
	char char1 = '0';
	char char2 = '0';
	char char3 = '0';
	char char4 = '0';
	char usrInput[4] = {'0','0','0','0'};
	
	unsigned int data = 0;
	unsigned int RepSizeInBits = sizeof(data)*8;
	unsigned int strLenMax = RepSizeInBits/*BINARY*/ + sizeof(data)/*SPACES*/ + 1/*\0*/;
	
	char binaryRep[strLenMax];
	
	
	printf("Enter the first character : ");
	usrInput[0] = getchar();
	fflush(stdin);
	
	printf("Enter the secon character : ");
	usrInput[1] = getchar();
	fflush(stdin);
	
	printf("Enter the third character : ");
	usrInput[2] = getchar();
	fflush(stdin);
	
	printf("Enter the fourth character : ");
	usrInput[3] = getchar();
	fflush(stdin);
	puts("");
	
	
	printf("\nResult before shifting and replacing last 8 bits with %c\n", usrInput[0]);
	byteRepresentation(data);
	byteRepresentationOnString(strLenMax, data, binaryRep);
	//printf("%10u =%s\n",data, binaryRep);
	packCharacter(usrInput[0], &data);
	printf("\nResult after shifting and replacing last 8 bits with %c\n", usrInput[0]);
	byteRepresentation(data);
	byteRepresentationOnString(strLenMax, data, binaryRep);
	//printf("%10u =%s\n",data, binaryRep);
	
	printf("\nResult before shifting and replacing last 8 bits with %c\n", usrInput[1]);
	byteRepresentation(data);
	byteRepresentationOnString(strLenMax, data, binaryRep);
	//printf("%10u =%s\n",data, binaryRep);
	packCharacter(usrInput[1], &data);
	printf("\nResult after shifting and replacing last 8 bits with %c\n", usrInput[1]);
	byteRepresentation(data);
	byteRepresentationOnString(strLenMax, data, binaryRep);
	//printf("%10u =%s\n",data, binaryRep);
	
	printf("\nResult before shifting and replacing last 8 bits with %c\n", usrInput[2]);
	byteRepresentation(data);
	byteRepresentationOnString(strLenMax, data, binaryRep);
	//printf("%10u =%s\n",data, binaryRep);
	packCharacter(usrInput[2], &data);
	printf("\nResult after shifting and replacing last 8 bits with %c\n", usrInput[2]);
	byteRepresentation(data);
	byteRepresentationOnString(strLenMax, data, binaryRep);
	//printf("%10u =%s\n",data, binaryRep);
	
	printf("\nResult before shifting and replacing last 8 bits with %c\n", usrInput[3]);
	byteRepresentation(data);
	byteRepresentationOnString(strLenMax, data, binaryRep);
	//printf("%10u =%s\n",data, binaryRep);
	packCharacter(usrInput[3], &data);
	printf("\nResult after shifting and replacing last 8 bits with %c\n", usrInput[3]);
	byteRepresentation(data);
	byteRepresentationOnString(strLenMax, data, binaryRep);
	//printf("%10u =%s\n",data, binaryRep);
	
	return 0;
}

void byteRepresentationOnString(unsigned int strMaxLen, unsigned int number, char string[strMaxLen])
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
