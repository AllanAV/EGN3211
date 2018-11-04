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
union data
	{
		char c;
		short s;
		int i;
		long b;
	};
 int main (void)
{
	//Main Local Variable
	union data userEntry;
	userEntry.c = '8';
	
	while(userEntry.c != '0')
	{
	/*CHAR SECTION*/
	printf("Enter data for type char (enter 0 to exit):");
	scanf("%c", &userEntry.c);
	fflush(stdin);
	
	if(userEntry.c == '0')
	{
		break;
	}
	
	printf("\nBreakdown of the element in the union\n");
	printf("char %c\n", userEntry.c);
	printf("short %hd\n", userEntry.s);
	printf("int %d\n", userEntry.i);
	printf("long %ld\n\n", userEntry.b);
	
	printf("Breakdown in hex\n");
	printf("char %x\n", userEntry.c);
	printf("short %x\n", userEntry.s);
	printf("int %x\n", userEntry.i);
	printf("long %x\n\n", userEntry.b);
	
	/*SHORT SECTION*/
	printf("Enter data for type short (enter 0 to exit):");
	scanf("%hd",&userEntry.s);
	fflush(stdin);
	
	if(userEntry.s == (short)0)
	{
		break;
	}
	
	printf("\nBreakdown of the element in the union\n");
	printf("char %c\n", userEntry.c);
	printf("short %hd\n", userEntry.s);
	printf("int %d\n", userEntry.i);
	printf("long %ld\n\n", userEntry.b);
	
	printf("Breakdown in hex");
	printf("char %x\n", userEntry.c);
	printf("short %x\n", userEntry.s);
	printf("int %x\n", userEntry.i);
	printf("long %x\n\n", userEntry.b);
	
	/*INT SECTION*/
	printf("Enter data for type int (enter 0 to exit):");
	scanf("%d",&userEntry.i);
	fflush(stdin);
	
	if(userEntry.s == (int)0)
	{
		break;
	}
	
	printf("\nBreakdown of the element in the union\n");
	printf("char %c\n", userEntry.c);
	printf("short %hd\n", userEntry.s);
	printf("int %d\n", userEntry.i);
	printf("long %ld\n\n", userEntry.b);
	
	printf("Breakdown in hex");
	printf("char %x\n", userEntry.c);
	printf("short %x\n", userEntry.s);
	printf("int %x\n", userEntry.i);
	printf("long %x\n\n", userEntry.b);
	
	/*LONG SECTION*/
	printf("Enter data for type long (enter 0 to exit):");
	scanf("%ld",&userEntry.b);
	fflush(stdin);
	
	if(userEntry.s == (long)0)
	{
		break;
	}
	
	printf("\nBreakdown of the element in the union\n");
	printf("char %c\n", userEntry.c);
	printf("short %hd\n", userEntry.s);
	printf("int %d\n", userEntry.i);
	printf("long %ld\n\n", userEntry.b);
	
	printf("Breakdown in hex");
	printf("char %x\n", userEntry.c);
	printf("short %x\n", userEntry.s);
	printf("int %x\n", userEntry.i);
	printf("long %x\n\n", userEntry.b);
	
	}
	
	return 0;
}
