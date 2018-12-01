/*
UCF EGN 3211
FALL 2018
Prof. Sundar Sinnappan
*** Homework 8A ***
by Allan Aquino Vieira
https://github.com/AllanAV/EGN3211/blob/master/EGN3211_HW8Av3.c
*/

#include <stdio.h>
#include <math.h>

int main(void)
{
	//main VARIABLE DEFINITIONS
	char prompt[] = {"Finding root for three degree polynomial Ax^3 = Bx^2 + Cx + D"
	"using Newton-Raphson method"};
	double A =  1.00;
	double B =  3.00;
	double C =  -1.00;
	double D =  -4.00;
	double guess = 1.00;
		//printf("\nguess=%.10f\n", guess);
	double precision = 0.000000001;
		//printf("\nprecision=%.10f\n", precision);

	printf("%s", "Enter value for the following coeficients\n");
	
	printf("A= ");
	scanf("%f", &A);
	
	printf("B= ");
	scanf("%f", &B);
	
	printf("C= ");
	scanf("%f", &C);
	
	printf("D= ");
	scanf("%f", &D);
	
	printf("Initial root estimate: ");
	scanf("%f", &guess);
	
	double fx;
	double dx;
	int i=1;
	double ans;
	
	do
	{
		printf("\n%3d : Estimate : %.10f", i, guess);
		
		//printf("\n%d ***********************************", i);
		fx = (A*guess*guess*guess+B*guess*guess+C*guess+D);
		//printf("\nf(x)=%.10g", fx);
		//printf(" > %.10g", precision);
		
		dx = (3.0*A*guess*guess+2.0*B*guess+C);
		//printf("\ndx/dy=%.10f", dx);
		
		double fxDx = fx/dx;
		//printf("\n(fx/dx)=%.10f", fxDx);
		
		guess = (guess - fxDx);
		//printf("\nguess=%.10f\n", guess);
		ans = guess;
		
		
		
		++i;
		
	}while(fabs(fx)>= precision);
	
	printf("\n\nAproximate solution = %.10f\n\n", guess);
	return 0;
}

