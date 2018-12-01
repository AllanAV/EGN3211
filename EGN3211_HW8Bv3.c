/*
UCF EGN 3211
FALL 2018
Prof. Sundar Sinnappan
*** Homework 8B ***
by Allan Aquino Vieira
https://github.com/AllanAV/EGN3211/blob/master/EGN3211_HW8Bv3.c
*/

#include <stdio.h>
#include <math.h>

#define DECIMAL 12

//FUNCTIONS PROTOTYPE
double function(double A, double B, double C, double D, double x);

int main(void)
{
	//main VARIABLE DEFINITIONS
	double A =  1.00;
	double B =  3.00;
	double C =  -1.00;
	double D =  -4.00;
	double left = 1.00;
	double f_left = 0.00;
		//printf("\nleft = %f | ", left);
	double right = 2.00;
	double f_right = 0.00;
		//printf("right = %lf | ", right);
	double precision = (1.0/10000000000.0);
		//printf("precision is %.12f\n", precision);
	double mid = (right - left)/2.0;
	double f_mid= 0.00;
	int i = 0;

	
	printf("Finding root for three degree polynomial Ax^3+Bx^2+Cx+D\nusing Bisection method\n");
	
	printf("\n%s", "Enter value for the following coeficients in decimal form (e.g. 1.0)\n");
	printf("A= ");
	scanf("%f", &A);
	
	printf("B= ");
	scanf("%f", &B);
	
	printf("C= ");
	scanf("%f", &C);
	
	printf("D= ");
	scanf("%f", &D);
	
	printf("Initial root interval:\n");
	printf("Left boundry: ");
	scanf("%f", &left);
	printf("Right boundry: ");
	scanf("%f", &right);
	
	
	//printf("\n%10s | %10s | %10s | %10s | %10s | %10s\n","LEFT", "MID", "RIGHT","F(LEFT)", "F(MID)", "F(RIGHT)");//TEST PURPOSES
	do
	{
		++i;
		mid = left+((right - left)/2.0);
		//printf("\nRH - LH is %.10f > %.10f", (right - left), precision);//TEST PURPOSES
		//printf("\n\n mid is %.10f ", mid);//TEST PURPOSES
		
		f_left = function(A, B, C, D, left);
		//printf("f(left) = %f",f_left);
		f_right = function(A, B, C, D, right);
		//printf("f(right) = %f",f_right);
		f_mid = function(A, B, C, D, mid);
		//printf("f(mid) = %.10f",f_mid);
		
		//printf("\n\n%d",i-1);//TEST PURPOSES
		//printf("\n%.10f | %.10f |%.10f | ",left, mid, right);//TEST PURPOSES
		//printf("\n%13.10f | %13.10f |%13.10f ",f_left, f_mid, f_right);//TEST PURPOSES
		
		if((f_mid > 0 && f_left < 0)  || (f_mid < 0 && f_left > 0))
		{//DIFFERENT SIGNS
			//printf("\n\t\t\t\t  >>>");
			right = mid;
		}
		else
		{
			//printf("\n\t\t\t\t  <<<");
			left = mid;
		}
		
		printf("\n%3d : New interval : [%.10f .. %.10f]",i , left, right);
		
		//printf("\n%.10f | %.10f |%.10f | ",left, mid, right);//TEST PURPOSES
		//printf("\n%13.10f | %13.10f |%13.10f ",f_left, f_mid, f_right);//TEST PURPOSES
		
		
		
	}while (((right - left)>precision)&&((right - left) > ((-1.0)*precision-1)));
	
	printf("\n\nApproximate solution = %.10f", mid);
	
	return 0;	
}

double function(double A, double B, double C, double D, double x)
{
	//function VARIABLE DEFINITIONS
	double answer = 0;
	
	answer = (A * x * x * x + B * x * x + C * x + D);
	
	return answer;
}
