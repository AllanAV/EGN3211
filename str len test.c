#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tools
{
	unsigned int id;
	char name[25];
	unsigned int qty;
	float cost;
} structTools;

int main (void)
{
	structTools Inventory = {0, "", 0, 0.0}, *const inventoryPtr = &Inventory;
	char usrInput[100]= "abcdefghijklmnopqrstuvwxyz 999999999 99999.99";
	int usrInputLeng = 0;


	//printf("\nSize of int is %d", sizeof(unsigned int));
	//printf("\nSize of flot is %d", sizeof(float));
	//printf("\nSize of \\0 is %d", sizeof('\0'));
	//printf("\nsizeof(float)+sizeof('\\0') is %d", sizeof(float)+sizeof('\0'));
	//printf("\nEnter tool name, quantity, and cost.\n");
	//fscanf(stdin, "%s",structPtr->name);
	//fscanf(stdin, "%s%u%f", structPtr->name, structPtr->qty, structPtr->cost);
	//gets(usrInput);
	/*
	scanf("%s", inventoryPtr->name);
	printf("%s", inventoryPtr->name);
	getchar();
	scanf("%d", inventoryPtr->qty);
	printf("%u", inventoryPtr->qty);
	scanf("%f", inventoryPtr->cost);
	*/
	//printf("\n%s %u %f", inventoryPtr->name, inventoryPtr->qty, inventoryPtr->cost);
	
	
	
	//printf("%s", usrInput);
	usrInputLeng = strlen(usrInput);
	//printf("\nusrInputLeng is %d", usrInputLeng);
	//printf("\nLast elementof usrInput is %d", usrInput[usrInputLeng]);
	//printf("\nLast elementof usrInput is %x", usrInput[usrInputLeng]);
	/*
	for(int i=0; i<=usrInputLeng; ++i)
	{
		printf("\nusrInput[%d]=%c", i, usrInput[i]);
	}
	*/
	//char tmpStrToFloat[sizeof(float) + 1];
	//strcpy(tmpStrToFloat, usrInput)
	
	/*
	int temp = (usrInputLeng - sizeof(float));
	printf("\nSize of temp is %d", temp);
	char *InputPtr = &usrInput[temp];
	printf("\nInventory->cost is %s", InputPtr);
	printf("\n5.99 in hex is %x",5.99);
	printf("\nInventory->cost is %x", atof(InputPtr));
	strcpy(tmpStrToFloat, InputPtr);
	printf("\nInventory->cost is %f", atof(tmpStrToFloat));
	//inventoryPtr->cost = atof(usrInput[temp]);
	//printf("\nInventory->cost is %f", inventoryPtr->cost);
	
	strcpy(tmpStrToFloat, InputPtr);
	*/
	
	/*WORKS*/
	/*
	usrInputLeng = strlen(usrInput);
	printf("\nusrInputLeng is %d", usrInputLeng);
	printf("\nLast elementof usrInput[%d] is %d", usrInputLeng, usrInput[usrInputLeng]);
	
	char tmpStrToFloat[sizeof(float) + 1];
	
	for(int i=0, j=(usrInputLeng - sizeof(float)); j<= usrInputLeng; ++j,++i)
	{
		tmpStrToFloat[i] = usrInput[j];
		printf("\ntmpStrToFloat[%d]=%c\n",i,tmpStrToFloat[i]);
		printf("usrInput[%d]=%c\n",j, usrInput[j]);
	}
	printf("\ntmpStrToFloat is %f", atof(tmpStrToFloat));
	*/
	unsigned int item_id = 0;
	do
	{
		printf("Enter new tool inventory ID (1-100): ");
		scanf("%u", &item_id);
		fflush(stdin);
	}while(item_id < 1 && item_id > 100);
	
	inventoryPtr->id = (unsigned int)(item_id - 1);
	printf("\inventoryPtr->id = %u\n", inventoryPtr->id);//TEST PURPUSES
	
	//current data
	printf("Enter tool name (no spaces), quantity, and cost.\n");
	
	
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
	return 0;	
}
