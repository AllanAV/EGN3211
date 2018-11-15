/*
UCF EGN 3211
FALL 2018
Prof. Sundar Sinnappan
*** Homework 7A ***
by Allan Aquino Vieira
*/

#include <stdio.h>

#define MAXENTRIES 100

//Structure Definition
typedef struct toolStruct
{
	unsigned int id;
	char name[25];
	unsigned int qty;
	float cost;
};

int main (void)
{
	//Main Variables Definition
	struct toolStruct blankTools = {0, "", 0, 0.0};
	//struct toolStruct blankTools = {100, "TEST", 5, 5.0};

	//File Manipulation
	FILE *bfPtr;
	bfPtr = fopen("hardware.dat","wb");
	//"wb" will create binary file and disacard content if file exists
	if(bfPtr == NULL)
	{
		puts("!!*.dat File Could Not Be Open!!");
		return 1;
		//(ERROR 1) File could not be open
	}
	else
	{
		for(int i = 0; i < MAXENTRIES; ++i)
		{
			
			//blankTools.id = (unsigned int)i;//TEST PURPUSES
			//blankTools.qty = (unsigned int)i;//TEST PURPUSES
			//blankTools.cost= (float)i;//TEST PURPUSES
			//printf("\n(%3u) ",(unsigned int)i);//TEST PURPUSES
			printf("%u|%s|%u|%0.2f\n", blankTools.id ,blankTools.name, blankTools.qty, blankTools.cost);
			
			fwrite(&blankTools, sizeof(struct toolStruct), 1, bfPtr);
		}
	fclose (bfPtr);
	}
	
	//TEST PURPUSES
	FILE *tfPtr;
	tfPtr = fopen("hardware.csv","w");
	//"w" will create  file and disacard content if file exists
	if(tfPtr == NULL)
	{
		puts("!!*.csv File Could Not Be Open!!");
		return 2;
		//(ERROR 2) File could not be open
	}
	else
	{
		//Header
		fprintf(tfPtr, "ID,NAME,QUANTITY,COST\n");
		
		for(int i = 0; i < MAXENTRIES; i++)
		{
			/*
			blankTools.id = i;//TEST PURPUSES
			blankTools.qty = (unsigned int)i;//TEST PURPUSES
			blankTools.cost= (float)i;//TEST PURPUSES
			//printf("\n(%3u) ",(unsigned int)i);//TEST PURPUSES
			*/
			fprintf(tfPtr, "%u,%s,%u,%0.2f\n", blankTools.id ,blankTools.name, blankTools.qty, blankTools.cost);
			
		}
	fclose (tfPtr);
	}
	
	
	return 0;
}
