/*
UCF EGN 3211
FALL 2018
Prof. Sundar Sinnappan
*** Homework 8A ***
by Allan Aquino Vieira

*/

#include <stdio.h>
#include <math.h>

double NRM(double A, double B, double C, double D, double guess);

int main(void)
{
	//main VARIABLE DEFINITIONS
	char prompt[] = {"Finding root for three degree polynomial Ax^3 = Bx^2 + Cx + D"
	"using Newton-Raphson method"};
	long double A =  1.00;
	long double B =  3.00;
	long double C =  -1.00;
	long double D =  -4.00;
	double guess = 1.00;
	printf("\nguess is %Lf\n", guess);
	long double precision = 1/10000000000;
	printf("\nprecision is %Lf\n", precision);

	/*printf("%s\n%s", "Finding root for three degree polynomial Ax^3 = Bx^2 + Cx + D", "using Newton-Raphson method");
	printf("\n%s", "Enter value for the following coeficients");
	
	printf("\nA= ");
	//scanf("%f", &A);
	
	printf("\nB= ");
	//scanf("%f", &B);
	
	printf("\nC= ");
	//scanf("%f", &C);
	
	printf("\nD= ");
	//scanf("%f", &D);
	
	printf("\nInitial root estimate: ");
	//scanf("%f", &guess);*/
	
	double fx;
	double dx;
	
	double ans;
	for(int i = 1; fx <= precision; ++i)
	{
		fx = (double)(A * pow(guess, 3) + B * pow(guess, 2) + C * guess + D);
		printf("\n\nf(x)=%.10f", fx);
		
		dx = (double)(3 * A * pow(guess, 2) + 2 * B * guess + C);
		printf("\ndx/dy=%.10f", dx);
		
		printf("\n(fx/dx)=%.10f", (fx/dx));
		
		guess = (guess - (fx/dx));
		printf("\n%d : guess : %.10f\n", i, guess);
		ans = guess;
	}
	
	printf("\nAproximate solution = %.10f\n\n", ans);
	return 0;
}

double NRM(double A, double B, double C, double D, double guess)
{
	//NRM Variable Definitions
	double fx;
	double dx;
	
	fx = (A * pow(guess, 3) + B * pow(guess, 2) + C * guess + D);
	printf("\nf(x)=%f", fx);
	
	dx = (A * pow(guess, 2) + B * guess + C);
	printf("\ndx/dy=%f", dx);
	
	if(fx > 0.00001 && fx < 0.000001)
	{
		guess = (guess - (fx/dx));
		printf("\nNRI=%f", guess);
		guess = NRM(A, B, C, D, guess);
		
	}
	//else
	{
		//return guess;
	}
}
