/*
UCF EGN 3211
FALL 2018
Prof. Sundar Sinnappan
*** Homework 6A ***
by Allan Aquino Vieira
https://github.com/AllanAV/EGN3211/blob/master/EGN3211_HW6A.c
*/

#include <stdio.h>
#include <stdlib.h>

//Union Definition
union integer
	{
		char c;
		short s;
		int i;
		long b;
	};

int main (void)
{
	//Main Local Variable
	union integer integer;
	
	while(integer.c != '0')
	{
	/*CHAR SECTION*/
	printf("Enter data for type char (enter 0 to exit):");
	scanf("%c", &integer.c);
	fflush(stdin);
	
	if(integer.c == '0')
	{
		break;
	}
	
	printf("\nBreakdown of the element in the union\n");
	printf("char %c\n", integer.c);
	printf("short %hd\n", integer.s);
	printf("int %d\n", integer.i);
	printf("long %ld\n\n", integer.b);
	
	printf("Breakdown in hex\n");
	printf("char %x\n", integer.c);
	printf("short %x\n", integer.s);
	printf("int %x\n", integer.i);
	printf("long %x\n\n", integer.b);
	
	/*SHORT SECTION*/
	printf("Enter data for type short (enter 0 to exit):");
	scanf("%hd",&integer.s);
	fflush(stdin);
	
	if(integer.s == (short)0)
	{
		break;
	}
	
	printf("\nBreakdown of the element in the union\n");
	printf("char %c\n", integer.c);
	printf("short %hd\n", integer.s);
	printf("int %d\n", integer.i);
	printf("long %ld\n\n", integer.b);
	
	printf("Breakdown in hex");
	printf("char %x\n", integer.c);
	printf("short %x\n", integer.s);
	printf("int %x\n", integer.i);
	printf("long %x\n\n", integer.b);
	
	/*INT SECTION*/
	printf("Enter data for type int (enter 0 to exit):");
	scanf("%d",&integer.i);
	fflush(stdin);
	
	if(integer.s == (int)0)
	{
		break;
	}
	
	printf("\nBreakdown of the element in the union\n");
	printf("char %c\n", integer.c);
	printf("short %hd\n", integer.s);
	printf("int %d\n", integer.i);
	printf("long %ld\n\n", integer.b);
	
	printf("Breakdown in hex");
	printf("char %x\n", integer.c);
	printf("short %x\n", integer.s);
	printf("int %x\n", integer.i);
	printf("long %x\n\n", integer.b);
	
	/*LONG SECTION*/
	printf("Enter data for type long (enter 0 to exit):");
	scanf("%ld",&integer.b);
	fflush(stdin);
	
	if(integer.s == (long)0)
	{
		break;
	}
	
	printf("\nBreakdown of the element in the union\n");
	printf("char %c\n", integer.c);
	printf("short %hd\n", integer.s);
	printf("int %d\n", integer.i);
	printf("long %ld\n\n", integer.b);
	
	printf("Breakdown in hex");
	printf("char %x\n", integer.c);
	printf("short %x\n", integer.s);
	printf("int %x\n", integer.i);
	printf("long %x\n\n", integer.b);
	
	}
	
	return 0;
}
