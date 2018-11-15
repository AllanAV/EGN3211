/*
UCF EGN 3211
FALL 2018
Prof. Sundar Sinnappan
*** Homework 7A ***
by Allan Aquino Vieira
*/

#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <time.h>

#define MAXENTRIES 100

//Structure Definition
typedef struct tools
{
	unsigned int id;
	char name[25];
	unsigned int qty;
	float cost;
} structTools;


//Function Prototype


int main (void)
{
	//Main Variable Declaration
	structTools Inventory = {0, "", 0, 0.0}, *const inventoryPtr = &Inventory;
	int structToolsSize = sizeof(struct tools);
	printf("structToolsSize = %d\n",structToolsSize);//TEST PURPUSES
	
	char mainPrompt[] = {
	"INVENTORY MANAGEMENT SYSTEM\n\nYour choices are:\n"
	"1 - EXPORT a formated text file of invetoried tools (hardware.txt) for printing\n"
	"2 - UPDATE a tool record\n"
	"3 - ADD a new tool record\n"
	"4 - DELETE a tool record\n"
	"5 - DISPLAY a tool record\n"
	"9 - EXIT program\n\nSelection: "
	};
	char timeStampStr[27];
	int selection = 0;
	int sizeOfFileRead = 0; 
	
	//File manipulation
		FILE *bfPtr;
		bfPtr = fopen("hardware.dat","rb+");
		//"rb+" will open binary file read and writer rights
		
		if(bfPtr == NULL)
		{
			puts("!!*.dat File Could Not Be Open!!");
			selection = 9;
			return 1;
			//(ERROR 1) File could not be open
		}
			
	while(selection != 9)
	{
		selection = 0;
		//timeStamp(timeStampStr);//TEST PURPUSES
		printf("%s", mainPrompt);
		scanf("%d", &selection);
		fflush(stdin);
		
		switch(selection)
		{
			case 1 :
				
				break;
			case 2 :
				
				break;
			case 3 :
				
				break;
			case 4 :
				
				break;
			case 5 :
				displayInventory(bfPtr, structToolsSize, inventoryPtr);
				break;
			case 9 :
				fclose (bfPtr);
				break;
			default :
				printf("!!Invalid entry!!\n");
				break;
		}
	};
	
	fclose (bfPtr);
	return 0;
}

int exportInventoryTXT (FILE *binfilePtr, int structSize, structTools *const structPtr)
{
	return 0;
}

int updateInventory()
{
	
	return 0;
}

int addInventory()
{

	return 0;	
}

int deleteInventory()
{
	
	return 0;
}
int displayInventory(FILE *binfilePtr, int structSize, structTools *const structPtr)
{
	//displayInventory Variables
	int freadReturn = 0;
	
	//Output Header
	printf("%3s\t|%24s\t|%3s\t|%7s\n", "ID", "PRODUCT NAME", "QTY", "COST");
	while (!feof(binfilePtr))
	{
		/*
		structPtr->id = 0;
		strcpy(structPtr->name, "");
		structPtr->qty = 0;
		structPtr->cost = 0.0;
		*/
		
		freadReturn = fread(structPtr, structSize, 1, binfilePtr);
		
		if(freadReturn != 0 && structPtr->id != 0)
		{
			printf("%3u\t| %24s\t| %3u\t|  %7.2f\n", structPtr->id , structPtr->name, structPtr->qty, structPtr->cost);
		}
	}
	//printf("\nfreadReturn = %d\n", freadReturn);//TEST PURPUSES
	
	return 0;
}

void timeStamp(char timeStampStr[27])
{
	//timeStamp Varaible Definitions
	time_t timer = 0;
    struct tm* tm_info;

    time(&timer);
    tm_info = localtime(&timer);
    strftime(timeStampStr, 26, "%H:%M:%S %m-%d-%Y ", tm_info);
    timeStampStr[26] = '\0';
    //printf("%s",timeStampStr);//TEST PURPUSES
}


