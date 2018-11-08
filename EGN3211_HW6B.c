/*
UCF EGN 3211
FALL 2018
Prof. Sundar Sinnappan
*** Homework 6B ***
by Allan Aquino Vieira

*/

#include <stdio.h>
#include <stdlib.h>

//Union Definition
union floatingPoint
	{
		float f;
		double d;
		long double x;
	};

int main(void)
{
	//Main Local Variable
	union floatingPoint usrEntry;
	union floatingPoint *uniPtr = &usrEntry;
	usrEntry.f = 234.567;
	
	//while((usrEntry.f >= 0.00) && (usrEntry.f <= 0.00))
	{
		/*FLOAT SECTION*/
		printf("Enter data for type float (enter 0 to exit):");
		usrEntry.f=234.567;
		scanf("%f", &usrEntry.f);
		fflush(stdin);
		
		printf("\nBreakdown of the element in the union\n");
		printf("float %f\n", usrEntry.f);
		printf("double %lf\n", usrEntry.d);
		printf("long double %lf\n\n", usrEntry.x);
		
		printf("Breakdown in hex\n");
		printf("float %x\n", usrEntry.f);
		printf("double %x\n", usrEntry.d);
		printf("long double %x\n\n", usrEntry.x);
		
		/*DOUBLE SECTION*/
		printf("Enter data for type double (enter 0 to exit):");
		usrEntry.d=234.567;
		scanf("%lf", &usrEntry.d);
		fflush(stdin);
		
		printf("\nBreakdown of the element in the union\n");
		printf("float %lf\n", usrEntry.f);
		printf("double %f\n", usrEntry.d);
		printf("long double %Lf\n\n", usrEntry.x);
		
		printf("Breakdown in hex\n");
		printf("float %x\n", usrEntry.f);
		printf("double %x\n", usrEntry.d);
		printf("long double %x\n\n", usrEntry.x);
		
		/*LONG DOUBLE SECTION*/
		printf("Enter data for type long double (enter 0 to exit):");
		usrEntry.x=234.567;
		scanf("%Lf", &usrEntry.x);
		fflush(stdin);
		
		printf("\nBreakdown of the element in the union\n");
		printf("float %f\n", usrEntry.f);
		printf("double %lf\n", usrEntry.d);
		printf("long double %Lf\n\n", usrEntry.x);
		
		printf("Breakdown in hex\n");
		printf("float %x\n", usrEntry.f);
		printf("double %x\n", usrEntry.d);
		printf("long double %x\n\n", usrEntry.x);
		
		
	}
	
	return 0;
}
