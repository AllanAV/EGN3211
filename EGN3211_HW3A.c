/*
UCF EGN 3211
FALL 2018
Prof. Sundar Sinnappan
*** Homework 3A ***
by Allan Aquino Vieira
*/

#include<stdio.h>
#include<math.h>

//Functions Prototype
float quadratic_calculation (float x);

int main(void)
{
	//Local Variable Declaration and Initialization
	float input = 0.0;
	float output = 0.0;
	
	printf("This program evaluates x^2 + 5x + 6\n\n");
	printf("*** Note: Invalid values will terminate the program  ***\n\n");
	
	do
	{
		printf("Enter a decimal value between -100.0 and 100.0 :");
		scanf("%f",&input);
		
		if(input > -100.0 && input < 100.0)
		{
			output = quadratic_calculation (input);
		
			printf("f(%.4f) = %.4f\n\n", input, output);
		
		}else
		{
			printf("%.3f is invalid. Good bye", input);
		}
	
	}while(input > -100.0 && input < 100.0);
	
	return 0;
}

float quadratic_calculation (float x)
{
	//Function Local Variables Declaration and Initialization 
	float result = 0.0;
	
	//x^2 + 5x + 6
	result = ((float) pow(x,2)) + 5*x + 6;
	
	return result;
}
