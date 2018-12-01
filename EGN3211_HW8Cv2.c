/*
UCF EGN 3211
FALL 2018
Prof. Sundar Sinnappan
*** Homework 8B ***
by Allan Aquino Vieira

*/

#include <stdio.h>
#include<stdlib.h>

//FUNCTIONS PROTOTYPES
void displayMatrix(int equations, int variables, float matrix[equations][variables]);
void solution(int equations, int variables, float matrix[equations][variables], int var);
void elementInputMatrix(int equations, int variables, float matrix[equations][variables], char varLtr);

int main (void)
{
	//main VARIABLE DECLARATION
	int equations=3, variables=3, var=0;
	char varLtr = 'x';
	
	printf("Enter number of equatons to solve: ");
	scanf("%d", &equations);
	fflush(stdin);
	printf("Enter number of variables in equations: ");
	scanf("%d", &variables);
	fflush(stdin);
	printf("Enter letter for first variable in equations: ");
	scanf("%c", &varLtr);
	fflush(stdin);
	
	var=variables;
	++variables;//Accounting for equations solution
	
	//main VARIABLE DECLARATION
	float matrix[equations][variables]; 
	float *matrixPtr = matrix;
	
	matrix[0][0]=2.0;	matrix[0][1]=4.0;	matrix[0][2]=6.0;	matrix[0][3]=22.0;
	matrix[1][0]=3.0;	matrix[1][1]=8.0;	matrix[1][2]=5.0;	matrix[1][3]=27.0;
	matrix[2][0]=-1.0;	matrix[2][1]=1.0;	matrix[2][2]=2.0;	matrix[2][3]=02.0;
	
	elementInputMatrix(equations, variables, matrix, varLtr);
	
	displayMatrix(equations, variables, matrix);
	
	solution(equations, variables, matrix, var);
	
	
	
	return 0;
}

void elementInputMatrix(int equations, int variables, float matrix[equations][variables], char varLtr)
{
	//displayMatrix VARIABLE DEFINITIONS
	int maker=(variables-2);
	
	printf("\nEnter the coefficients for the linear equation\n"
	"Ax + By + Cz + ... = S\n");
	
	for(int i=0, j=0; i<equations; ++i,j=0)
	{
		for(;j<variables;++j)
		{
			if(j<(maker+1))
			{
				printf("\nCoeficient for %c on Equation %d: ", varLtr+j, i+1);
			}
			if(j==maker+1)
			{
				printf("\nSolution for Equation %d: ", i+1);
			}
			scanf("%f", &matrix[i][j]);
			fflush(stdin);
			
		}
		printf("\n");
	}
}

void displayMatrix(int equations, int variables, float matrix[equations][variables])
{
	//displayMatrix VARIABLE DEFINITIONS
	int maker = (variables-2);
	
	for(int i=0, j=0; i<equations; ++i,j=0)
	{
		for(;j<variables; ++j)
		{
			printf("%7.3f\t",matrix[i][j]);
			if(j==maker)
			{
				printf("|\t");
			}
		}
		printf("\n");
	}
}

/*****************************************************************
solution() function was taken and altered from: 
www.sanfoundry.com/c-program-implement-gauss-jordan-elimination/
*****************************************************************/
void solution(int equations, int variables, float a[equations][variables], int var)
{
	//solution VARIABLE DEFINITIONS
	int k, i, j, c = (int)'x';
	float l;
	
	//displayMatrix(equations, variables, a);
 
    for (k=0;k<var;++k )
    {
        for (i=0;i<=var;++i )
        {
            l = a[i][k];
 
            for (j=0;j<=var;++j)
            {
                if (i!=k)
                a[i][j]=(a[k][k]*a[i][j])-(l*a[k][j]);
            }
        }
    }
 
    printf( "\nThe Solutions:\n" );
 
    for (i=0;i<var;++i)
    {
        printf( "\n%c = %7.3f\n", c + i, a[i][var] / a[i][i] );
    }
}
