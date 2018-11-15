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
	char usrInput[40]= "abcdefghijklmnopqrstuvwxyz 999999999 99999.99";
	int usrInputLeng = 0;
	
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
	printf("Enter tool name, quantity, and cost.\n");
	//gets(usrInput);
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
	return 0;	
}
