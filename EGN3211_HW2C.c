/*
UCF EGN 3211
FALL 2018
Prof. Sundar Sinnappan
*** Homework 2C ***
by Allan Aquino Vieira
*/

#include <stdio.h>

//Definitions
#define CLRIN fflush(stdin)

int main (void)
{
	//Constants Declaration and Initiation
	const char QTY_PROMPT[] = "Please enter quantity sold: ";
	const float itemPrice[5] = {2.98, 4.50, 9.98, 4.49, 6.87};
	
	//Local Variable Declaration and Initiation
	int productNumber = 0;
	unsigned int itemQty[5] = {0, 0, 0, 0, 0};
	float itemSales[5] = {0.0, 0.0, 0.0, 0.0, 0.0};
	
	do{
		printf("Please enter the product number between 1 and 5.  -1 to end :");
		scanf("%d", &productNumber);
		CLRIN;
		
		if (productNumber == -1)
		{
			break;
		}
	
		printf("%s", QTY_PROMPT);
		//Do ...While Local Variable Declaration and Initialization
		unsigned int qtyEntry = 0;
		scanf("%u", &qtyEntry); //why this does not work????
		CLRIN;
		
		
		switch (productNumber)
		{	
			case 1:	
				itemQty[productNumber-1] += qtyEntry;
				itemSales[productNumber-1] = itemPrice[productNumber-1] * itemQty[productNumber-1];
				break;
			case 2:
				itemQty[productNumber-1] += qtyEntry;
				itemSales[productNumber-1] = itemPrice[productNumber-1] * itemQty[productNumber-1];
				break;
			case 3:
				itemQty[productNumber-1] += qtyEntry;
				itemSales[productNumber-1] = itemPrice[productNumber-1] * itemQty[productNumber-1];
				break;
			case 4:
				itemQty[productNumber-1] += qtyEntry;
				itemSales[productNumber-1] = itemPrice[productNumber-1] * itemQty[productNumber-1];
				break;
			case 5:
				itemQty[productNumber-1] += qtyEntry;
				itemSales[productNumber-1] = itemPrice[productNumber-1] * itemQty[productNumber-1];
				break;
			default:
				printf("%d is an invalid entry!", productNumber);
				break;
		}
	}while (productNumber != -1);
	
	if(productNumber == -1)
	{
		//If Local Variable Declaration and Initailization
		float totalSales = 0.0;
		
		printf("Product      Qty    Sales\n");
		
		for(int i = 0; i <= 4;i++)
		{
			totalSales += itemSales[i];
			printf("Product %d :  %2u     %.2f\n", i+1, itemQty[i], itemSales[i]);
		}
		printf("\nTotal     :   %.2f", totalSales);
	}
	
	return 0;
}
