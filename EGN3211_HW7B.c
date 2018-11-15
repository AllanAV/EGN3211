/*
UCF EGN 3211
FALL 2018
Prof. Sundar Sinnappan
*** Homework 7A ***
by Allan Aquino Vieira
*/

#include <stdio.h>
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
float exportToolsTXT (const structTools * pointerToStruct);

void addTool (FILE *ponterToFile, structTools * pointerToStruct, unsigned int SizeOfStruct);

void displayTool (structTools * pointerToStruct);
void timeStamp(char timeStampStr[27]);

int main (void)
{
	//Main Variable Declaration
	structTools Inventory, *const inventoryPtr = &Inventory;
	unsigned int structToolsSize = sizeof(struct tools);
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
			return 10;
			//(ERROR 10) File could not be open
		}
		else
		{
			sizeOfFileRead = fread(inventoryPtr, structToolsSize, 1, bfPtr);
			if(sizeOfFileRead == 1)
			{
				printf("\nsizeOfFileRead = %d\n", sizeOfFileRead);//TEST PURPUSES
			}
			
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
				exportToolsTXT (inventoryPtr);
				break;
			case 2 :
				// updateTool (inventoryPtr, bfPtr);
				break;
			case 3 :
				addTool (bfPtr, inventoryPtr, structToolsSize);
				break;
			case 4 :
				// deleteTool (inventoryPtr, bfPtr);
				break;
			case 5 :
				displayTool (inventoryPtr);
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

float exportToolsTXT (const structTools * srcPtr)
{
	//exportToolsTXT Variables
	char timeStampStr[27];
	
	//File manipulation of TXT
	FILE *tfPtr;
	tfPtr = fopen("hardware.txt","w");
	//"w" will create  file and disacard content if file exists
	if(tfPtr == NULL)
	{
		puts("!!hardware.txt File Could Not Be Open!!");
		return 1.0;
		//(ERROR 1.0) TXT file could not be open
	}
	else
	{
		timeStamp(timeStampStr);
		//TXT File Output Header
		fprintf(tfPtr, "INVENTORY at %s\n", timeStampStr);
		fprintf(tfPtr, "%3s\t|%24s\t|%3s\t|%7s\n", "ID", "PRODUCT NAME", "QTY", "COST");
		
		for(int i = 0; i <= MAXENTRIES; i++)
		{
			fprintf(tfPtr, "%3u\t| %24s\t| %3u\t|  %7.2f\n", srcPtr->id , srcPtr->name, srcPtr->qty, srcPtr->cost);	
		}
	fclose (tfPtr);
	//puts("!!hardware.txt created!!");//TEST PURPUSES
	}
	return 1.0;
}

void updateTool (structTools * srcPtr, FILE *bfPtr)
{
	
}

void addTool (FILE *bfPtr, structTools * srcPtr, unsigned int structSize)
{
	//addToolTXT Variable Declatations
	char temp[40];
	unsigned int item_id = 0;
	unsigned int item_qty = 0;
	float item_cost = 0.0;
	char item_name[25];
	item_name[24] = '\0';
	
	do
	{
		printf("Enter new tool inventory ID (1-100): ");
		scanf("%u", &item_id);
		fflush(stdin);
	}while(item_id < 1 && item_id < 1);

	srcPtr->id = (unsigned int)(item_id  - 1);
	printf("\nsrcPtr->id = %u\n", srcPtr->id);//TEST PURPUSES
	
	int fseekReturn = fseek(bfPtr, (long int)((srcPtr->id) * structSize), SEEK_SET);
	if(fseekReturn != 0)
	{
		puts("\n!!!fseek error!!!\n\n");
	}
	else
	{
		puts("\nfseek sucess");
		printf("fseekReturn = %d\n", fseekReturn);//TEST PURPUSES
	}
	//current data
	printf("Enter tool name (no spaces), quantity, and cost.\n");
	//scanf("%23s%u%f",item_name, &item_qty, &item_cost);
	fscanf(stdin, "%s",srcPtr->name);
	//fscanf(stdin, "%23s%u%f", srcPtr->name, srcPtr->qty, srcPtr->cost);
	fflush(stdin);
	
	
	int fwriteReturn = fwrite(srcPtr, structSize, 1, bfPtr);
	if(fwriteReturn != 1)//TEST PURPUSES
	{
		printf("\n!!!writeing to file error!!! \nfwriteReturn = %d\n", fwriteReturn);//TEST PURPUSES
	}
	else
	{
		printf("\n write sucess \nfwriteReturn = %d\n", fwriteReturn);//TEST PURPUSES
	}
	printf("fwriteReturn = %d\n", fwriteReturn);//TEST PURPUSES
	
}

void deleteTool (structTools * srcPtr, FILE *bfPtr)
{
}
void displayTool (structTools * srcPtr)
{
	//displayToolTXT Variables
	
	//TXT File Output Header
		printf("\n%3s\t|%24s\t|%3s\t|%7s\n", "ID", "PRODUCT NAME", "QTY", "COST");
		
		for(int i = 0; i <= MAXENTRIES; ++i)
		{
			printf("%3u\t| %24s\t| %3u\t|  %7.2f\n", srcPtr->id , srcPtr->name, srcPtr->qty, srcPtr->cost);	
		}
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


