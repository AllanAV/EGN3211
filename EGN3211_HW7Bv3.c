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
/*1*/int exportInventoryTXT (FILE *binfilePtr, int structSize, structTools *const structPtr);
/*2*/
/*3*/int addInventory(FILE *binfilePtr, int structSize, structTools *structPtr);
/*4*/
/*5*/int displayInventory(FILE *binfilePtr, int structSize, structTools *const structPtr);
/*0*/int inputToStruct(structTools *const inventoryPtr, int inputFlag);
/*0*/void timeStamp(char timeStampStr[27]);

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
	"9 - EXIT program\n\nSelection: "
	};
	char timeStampStr[27];
	int selection = 0; 
	
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
				exportInventoryTXT(bfPtr, structToolsSize, inventoryPtr);
				break;
			case 2 :
				updateInventory(bfPtr, structToolsSize, inventoryPtr);
				break;
			case 3 :
				addInventory(bfPtr, structToolsSize, inventoryPtr);
				break;
			case 4 :
				
				break;
			case 5 :
				displayInventory(bfPtr, structToolsSize, inventoryPtr);
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
/*1*/
int exportInventoryTXT (FILE *binfilePtr, int structSize, structTools *const structPtr)
{
	//exportInventoryTXT VARIABLE DECLARATIONS
	char timeStampStr[27];
	int freadReturn = 0;
	
	binfilePtr = fopen("hardware.dat","rb+");
		//"rb+" will open binary file read and writer rights
		
		if(binfilePtr == NULL)
		{
			puts("!!*.dat File Could Not Be Open!!");
			return 1;
			//(ERROR 1) File could not be open
		}
	
	FILE *tfPtr;
		tfPtr = fopen("hardware.txt","w+");
		//"rb+" will open binary file read and writer rights
		
		if(tfPtr == NULL)
		{
			puts("!!*.txt File Could Not Be Open!!");
			return 1;
			//(ERROR 1) File could not be open
		}
	
	timeStamp(timeStampStr);
	
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
			fprintf(tfPtr, "%3u\t| %24s\t| %3u\t|  %7.2f\n",
			structPtr->id , structPtr->name, structPtr->qty, structPtr->cost);	
		}
	}
	//printf("\nfreadReturn = %d\n", freadReturn);//TEST PURPUSES
	
	fclose (tfPtr);
	fclose (binfilePtr);
	return 0;
}
/*2*/
int updateInventory(FILE *binfilePtr, int structSize, structTools *structPtr)
{
	//updateInventory VARIABLE DECLARATIONS
	int fseekReturn = 0;
	int freadReturn = 0;
	int fwriteReturn = 0;
	
	inputToStruct(structPtr,0);
	
	binfilePtr = fopen("hardware.dat","rb+");
		//"rb+" will open binary file read and writer rights
		
		if(binfilePtr == NULL)
		{
			puts("!!*.dat File Could Not Be Open!!");
			return 1;
			//(ERROR 1) File could not be open
		}
	
	fseekReturn = fseek(binfilePtr,(structPtr->id * ((unsigned int)structSize)),SEEK_SET);
	printf("\fseekReturn = %d\n", fseekReturn);//TEST PURPUSES
	
	//Output Header
	printf("\t\tCURRENT TOOL INFO\n"
	"%3s\t|%24s\t|%3s\t|%7s\n", 
	"ID", "PRODUCT NAME", "QTY", "COST");
	
	freadReturn = fread(structPtr, structSize, 1, binfilePtr);
	
	//Output Record
	if(freadReturn != 0 && structPtr->id != 0)
	{
		printf("%3u\t| %24s\t| %3u\t|  %7.2f\n",
		structPtr->id+1 , structPtr->name, structPtr->qty, structPtr->cost);
	}
	else
	{
		printf("%3u\t| %24s\t| %3c\t|  %c\n", 
		structPtr->id+1 , "DOES NOT EXIST", ' ', ' ');
	}
	
	fclose (binfilePtr);
	
	binfilePtr = fopen("hardware.dat","rb+");
		//"rb+" will open binary file read and writer rights
		
		if(binfilePtr == NULL)
		{
			puts("!!*.dat File Could Not Be Open!!");
			return 1;
			//(ERROR 1) File could not be open
		}
	
	fseekReturn = fseek(binfilePtr,(structPtr->id * ((unsigned int)structSize)),SEEK_SET);
	printf("\fseekReturn = %d\n", fseekReturn);//TEST PURPUSES
	
	inputToStruct(structPtr,1);
	
	fwriteReturn = fwrite(structPtr, structSize, 1, binfilePtr);
	if(fwriteReturn != 1)//TEST PURPUSES
	{
		printf("\n!!!error!!! Data could not be saved to file \nfwriteReturn = %d\n", fwriteReturn);//TEST PURPUSES
	}
	else
	{
		printf("\n write sucess \nfwriteReturn = %d\n", fwriteReturn);//TEST PURPUSES
	}
	
	fclose (binfilePtr);
	return 0;
}
/*3*/
int addInventory(FILE *binfilePtr, int structSize, structTools *structPtr)
{
	//addInventory VARIABLE DECLARATIONS
	int fseekReturn = 0;
	int fwriteReturn = 0;
	//char usrInput[MAXENTRIES];
	//int usrInputLeng = 0;
	
	inputToStruct(structPtr,2);
	
	binfilePtr = fopen("hardware.dat","rb+");
		//"rb+" will open binary file read and writer rights
		
		if(binfilePtr == NULL)
		{
			puts("!!*.dat File Could Not Be Open!!");
			return 1;
			//(ERROR 1) File could not be open
		}
	
	//inputToStruct(structPtr);
	
	fseekReturn = fseek(binfilePtr,(structPtr->id * ((unsigned int)structSize)),SEEK_SET);
	printf("\fseekReturn = %d\n", fseekReturn);//TEST PURPUSES
	
	fwriteReturn = fwrite(structPtr, structSize, 1, binfilePtr);
	if(fwriteReturn != 1)//TEST PURPUSES
	{
		printf("\n!!!error!!! Data could not be saved to file \nfwriteReturn = %d\n", fwriteReturn);//TEST PURPUSES
	}
	else
	{
		printf("\n write sucess \nfwriteReturn = %d\n", fwriteReturn);//TEST PURPUSES
	}
	
	fclose (binfilePtr);
	return 0;	
}
/*4*/
int deleteInventory()
{
	
	return 0;
}
/*5*/
int displayInventory(FILE *binfilePtr, int structSize, structTools *const structPtr)
{
	//displayInventory VARIABLE DECLARATIONS
	int freadReturn = 0;
	binfilePtr = fopen("hardware.dat","rb+");
		//"rb+" will open binary file read and writer rights
		
		if(binfilePtr == NULL)
		{
			puts("!!*.dat File Could Not Be Open!!");
			return 1;
			//(ERROR 1) File could not be open
		}
	
	
	//Output Header
	printf("%3s\t|%24s\t|%3s\t|%7s\n", "ID", "PRODUCT NAME", "QTY", "COST");
	
	while (!feof(binfilePtr))
	{
		freadReturn = fread(structPtr, structSize, 1, binfilePtr);
		
		if(freadReturn != 0 && structPtr->id != 0)
		{
			printf("%3u\t| %24s\t| %3u\t|  %7.2f\n",
			 structPtr->id+1 , structPtr->name, structPtr->qty, structPtr->cost);
		}
		
	}
	//printf("\nfreadReturn = %d\n", freadReturn);//TEST PURPUSES
	
	fclose (binfilePtr);
	return 0;
}

int inputToStruct(structTools *const inventoryPtr, int inputFlag)
{
	/******************************************************** 
	inputToStruct can be used any time user input is needed
	for structure ID only, for NAME, QUANITIY and COST only
	or for all strucure elements. This is defined by the 
	inputFlag value:
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
		printf("\ninventoryPtr->id = %u\n", inventoryPtr->id);//TEST PURPUSES
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
						printf("\ninventoryPtr->cost=%f",inventoryPtr->cost);
						break;
					case 1:
						//unsigned integet portion of input
						usrInput[i-1] = '\0';
						char *tempPtr;
						//long temp = strtoul(&usrInput[i], &temp, 10);
						inventoryPtr->qty = ((unsigned int)strtoul(&usrInput[i], &tempPtr, 10));//temp;
						--spcDtctd;
						printf("\ninventoryPtr->qty = %u",inventoryPtr->qty);
						
						//String portion of input
						if((i-1) > 24)
						{
							usrInput[24] = '\0';
						}
						//int nameleng = ((i-1)*sizeof(char));
						strcpy(inventoryPtr->name,usrInput);
						//memcpy(inventoryPtr->name,usrInput,nameleng);
						printf("\ninventoryPtr->name = %s",inventoryPtr->name);
						break;
				}
			}
		}
		fflush(stdin);
	}
	return 0;
}

/*0*/
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


