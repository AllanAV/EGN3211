/*
UCF EGN 3211
FALL 2018
Prof. Sundar Sinnappan
*** Homework 7B ***
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
/*LN 094*/int outputInventory (FILE *binfilePtr, int structSize, structTools *const structPtr, int outputFlag);
/*LN 227*/int changeInventory(FILE *binfilePtr, int structSize, structTools *structPtr, int changeModeFlag);
/*LN 284*/int inputToStruct(structTools *const inventoryPtr, int inputFlag);
/*LN 362*/void timeStamp(char timeStampStr[27]);

int main (void)
{
	//Main Variable Declaration
	FILE *bfPtr;
	
	structTools Inventory = {0, "", 0, 0.0}, *const inventoryPtr = &Inventory;
	int structToolsSize = sizeof(struct tools);
	//printf("structToolsSize = %d\n",structToolsSize);//TEST PURPUSES
	char mainPrompt[] = {
	"INVENTORY MANAGEMENT SYSTEM\n\nYour choices are:\n"
	"1 - EXPORT a formated text file of invetoried tools (hardware.txt) for printing\n"
	"2 - UPDATE a tool record\n"
	"3 - ADD a new tool record\n"
	"4 - DELETE a tool record\n"
	"5 - DISPLAY a tool record\n"
	"6 - DISPLAY all tool records\n"
	"9 - EXIT program\n\nSelection: "
	};
	char timeStampStr[27];
	int selection = 0; 
	
	while(selection != 9)
	{
		selection = 0;
		//timeStamp(timeStampStr);//TEST PURPUSES
		printf("\n%s", mainPrompt);
		scanf("%d", &selection);
		fflush(stdin);
		
		switch(selection)
		{
			case 1 ://EXPORT TXT
				outputInventory(bfPtr, structToolsSize, inventoryPtr,0);;
				break;
			case 2 : //UPDATE
				changeInventory(bfPtr, structToolsSize, inventoryPtr,1);
				break;
			case 3 ://ADD
				changeInventory(bfPtr, structToolsSize, inventoryPtr,1);
				break;
			case 4 ://DELETE
				changeInventory(bfPtr, structToolsSize, inventoryPtr,0);
				break;
			case 5 ://DISPLAY ONE
				outputInventory(bfPtr, structToolsSize, inventoryPtr,1);
				break;
			case 6://DISPLAY ALL
				outputInventory(bfPtr, structToolsSize, inventoryPtr,2);
				break;
			case 9 :
				//fclose (bfPtr);
				break;
			default :
				printf("!!Invalid entry!!\n");
				break;
		}
	};
	//fclose (bfPtr);
	return 0;
}
/*O*/
int outputInventory(FILE *binfilePtr, int structSize, structTools *const structPtr, int outputFlag)
{
	/******************************************************** 
	outputInventory function can be used any time record(s) 
	must be output the outputFlag value define the output
	method:
	0 - ALL records output as .txt file (hardware.txt)
	1 - SINGLE record output to SCREEN
	2 - ALL records output to SCREEN
	********************************************************/
	
	//outputInventory VARIABLE DECLARATIONS
	char timeStampStr[27];
	int fseekReturn = 0;
	int freadReturn = 0;
	int record_id = 0;
	int noRecords = 0;
	
	binfilePtr = fopen("hardware.dat","rb+");
		//"rb+" will open binary file read and writer rights
		
		if(binfilePtr == NULL)
		{
			puts("!!*.dat File Could Not Be Open!!");
			return 1;
			//(ERROR 1) File could not be open
		}
		
	if(outputFlag == 0)
	{//ALL RECORDS TO TXT
		FILE *tfPtr;
			tfPtr = fopen("hardware.txt","w+");
			//"w+" will create user readable file, disacards content if file exists
			
			if(tfPtr == NULL)
			{
				puts("!!*.txt File Could Not Be Open!!");
				return 1;
				//(ERROR 1) File could not be open
			}
		
		timeStamp(timeStampStr);
		noRecords = 0;
		
		//TXT File Output Header
			fprintf(tfPtr, "\t\tINVENTORY at %s\n", timeStampStr);
			fprintf(tfPtr, "%3s\t|%24s\t|%3s\t|%7s\n",
			 "ID", "PRODUCT NAME", "QTY", "COST");
		while (!feof(binfilePtr))
		{
			freadReturn = fread(structPtr, structSize, 1, binfilePtr);
			
			//printf("\nfreadReturn = %d\n", freadReturn);//TEST PURPUSES
			
			if(freadReturn != 0 && structPtr->id != 0)
			{
				++noRecords;
				fprintf(tfPtr, "%3u\t| %24s\t| %3u\t|  %7.2f\n",
				structPtr->id , structPtr->name, structPtr->qty, structPtr->cost);	
			}
		}
		if(noRecords == 0)
		{
			fprintf(tfPtr, "%3c\t| %24s\t| %3c\t|  %c\n", 
			' ' , "NO RECORDS FOUND", ' ', ' ');
		}
		//printf("\nfreadReturn = %d\n", freadReturn);//TEST PURPUSES
		
		fclose (tfPtr);
	}
	else if(outputFlag == 1)
	{//SINGLE RECORD
		
		inputToStruct(structPtr,0);
		//printf("\nstructPtr->id = %u\n", structPtr->id);//TEST PURPUSES
		
		fseekReturn = fseek(binfilePtr,(structPtr->id * ((unsigned int)structSize)),SEEK_SET);
		
		//printf("\fseekReturn = %d\n", fseekReturn);//TEST PURPUSES
		
		record_id = structPtr->id;
		
		//Output Header
		printf("\t\tCURRENT TOOL INFO\n"
		"%3s\t|%24s\t|%3s\t|%7s\n", 
		"ID", "PRODUCT NAME", "QTY", "COST");
		
		freadReturn = fread(structPtr, structSize, 1, binfilePtr);
		//printf("\nfreadReturn = %d\n", freadReturn);//TEST PURPUSES
		
		//Output One Record
		if(freadReturn != 0 && structPtr->id != 0)
		{
			printf("%3u\t| %24s\t| %3u\t|  %7.2f\n",
			structPtr->id+1 , structPtr->name, structPtr->qty, structPtr->cost);
		}
		else
		{
			structPtr->id = record_id;
			//printf("\nstructPtr->id = %3u\n", structPtr->id);//TEST PURPUSES
			printf("%3u\t| %24s\t| %3c\t|  %c\n", structPtr->id+1 , "DOES NOT EXIST", ' ', ' ');
		}
	}
	else if(outputFlag == 2)
	{//ALL RECORDS TO SCREEN
		noRecords = 0;
		//Output Header
		printf("%3s\t|%24s\t|%3s\t|%7s\n",
		 "ID", "PRODUCT NAME", "QTY", "COST");
		
		while (!feof(binfilePtr))
		{
			freadReturn = fread(structPtr, structSize, 1, binfilePtr);
			
			if(freadReturn != 0 && structPtr->id != 0)
			{
				printf("%3u\t| %24s\t| %3u\t|  %7.2f\n",
				 structPtr->id+1 , structPtr->name, structPtr->qty, structPtr->cost);
				 ++noRecords;
			}
		}
		if(noRecords == 0)
		{
			printf("%3c\t| %24s\t| %3c\t|  %c\n", 
			' ' , "NO RECORDS FOUND", ' ', ' ');
		}
		//printf("\nfreadReturn = %d\n", freadReturn);//TEST PURPUSES
		
		fclose (binfilePtr);
	}
	fclose (binfilePtr);
	return 0;
}
/*C*/
int changeInventory(FILE *binfilePtr, int structSize, structTools *structPtr, int changeModeFlag)
{
	/******************************************************** 
	changeInventory function can be used to CHANDE or DELETE 
	any record.This is feature is defined by the 
	changeModeFlag value:
	0 - DELETE
	1 - CHANGE with user input
	********************************************************/
	
	//addInventory VARIABLE DECLARATIONS
	int fseekReturn = 0;
	int fwriteReturn = 0;
	
	inputToStruct(structPtr,0);
	
	binfilePtr = fopen("hardware.dat","rb+");
		//"rb+" will open binary file read and writer rights
		
		if(binfilePtr == NULL)
		{
			puts("!!*.dat File Could Not Be Open!!");
			return 1;
		}
	
	fseekReturn = fseek(binfilePtr,(structPtr->id * ((unsigned int)structSize)),SEEK_SET);
	//printf("\fseekReturn = %d\n", fseekReturn);//TEST PURPUSES
	
	if (changeModeFlag == 0)
	{//DELETE
		strcpy(structPtr->name, "");
		structPtr->qty = 0;
		structPtr->cost = 0.0;
		printf("\nTool ID %3u has been deleted!", structPtr->id+1);
		structPtr->id = 0;
		//printf("%3u\t| %24s\t| %3u\t|  %7.2f\n",structPtr->id+1 , structPtr->name, structPtr->qty, structPtr->cost);//TEST PURPUSES
	}
	else if  (changeModeFlag == 1)
	{//CHANGE
		inputToStruct(structPtr,1);
		//printf("\n%3u\t| %24s\t| %3u\t|  %7.2f\n",		structPtr->id+1 , structPtr->name, structPtr->qty, structPtr->cost);
	}
	
	fwriteReturn = fwrite(structPtr, structSize, 1, binfilePtr);
	/*if(fwriteReturn != 1)//TEST PURPUSES
	{
		printf("\n!!!error!!! Data could not be saved to file \nfwriteReturn = %d\n", fwriteReturn);//TEST PURPUSES
	}
	else
	{
		printf("\n write sucess \nfwriteReturn = %d\n", fwriteReturn);//TEST PURPUSES
	}*/
	
	fclose (binfilePtr);
	return 0;	
}
/*I*/
int inputToStruct(structTools *const inventoryPtr, int inputFlag)
{
	/******************************************************** 
	inputToStruct function can be used any time user input 
	is needed for structure ID only, for NAME, QUANITIY and 
	COST only or for all strucure elements. This is defined 
	by the inputFlag value:
	0 - structure ID only
	1 - structure NAME, QUANITIY and COST only
	2 - structure ID, NAME, QUANITIY and COST.
	********************************************************/
	
	//inputToStruct VARIABLE DECLARATIONS
	char usrInput[44]= "abcdefghijklmnopqrstuvwx 999999999 99999.99";//Max input accepted
	int usrInputLeng = 0;
	unsigned int item_id = 0;
	
	//Taking structure id
	if(inputFlag == 0 || inputFlag ==  2)
	{
		do
		{
			printf("Enter new tool inventory ID (1-100): ");
			scanf("%u", &item_id);
			fflush(stdin);
		}while(item_id < 1 && item_id > 100);
		
		inventoryPtr->id = (unsigned int)(item_id - 1);
		//printf("\ninventoryPtr->id = %u\n", inventoryPtr->id);//TEST PURPUSES
	}
	//Taking structure NAME, QUANITIY and COST
	if(inputFlag == 1 || inputFlag ==  2)
	{
		printf("Enter tool Name Quantity and Cost (separated by spaces only).\n");
		gets(usrInput);
		usrInputLeng = strlen(usrInput);
		
		for(int i=usrInputLeng, spcDtctd=2; i>=0 && spcDtctd > 0; --i)
		{
			//printf("\ni=%d spcDtctd=%d",i ,spcDtctd);//TEST PURPOSES
			if(usrInput[i-1]== ' ')
			{
				//printf("\nSPACE");//TEST PURPOSES
				switch(spcDtctd)
				{
					case 2:
						//float portion of input
						inventoryPtr->cost = atof(&usrInput[i]);
						usrInput[i-1] = '\0';
						--spcDtctd;
						//printf("\ninventoryPtr->cost=%f",inventoryPtr->cost);//TEST PURPOSES
						break;
					case 1:
						//unsigned integet portion of input
						usrInput[i-1] = '\0';
						char *tempPtr;
						//long temp = strtoul(&usrInput[i], &temp, 10);
						inventoryPtr->qty = ((unsigned int)strtoul(&usrInput[i], &tempPtr, 10));//temp;
						--spcDtctd;
						//printf("\ninventoryPtr->qty = %u",inventoryPtr->qty);//TEST PURPOSES
						
						//String portion of input
						if((i-1) > 24)
						{
							usrInput[24] = '\0';
						}
						strcpy(inventoryPtr->name,usrInput);
						//printf("\ninventoryPtr->name = %s",inventoryPtr->name);//TEST PURPOSES
						break;
				}
			}
		}
		fflush(stdin);
	}
	return 0;
}
/*T*/
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


