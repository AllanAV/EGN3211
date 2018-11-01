/*
UCF EGN 3211
FALL 2018
Prof. Sundar Sinnappan
*** Homework 5A ***
by Allan Aquino Vieira
*/

#include <stdio.h>
#define LNGSTWRD 10
#define ALPHABET 26

/***FUNCTIONS PROTOTYPE***/
void makeLower(const char * srcPtr, char *targPtr);
void strBblSort(int arrSize, int arr[]);
void wrdLgthCnt(int lngth, const char *srcPtr, int table[2][LNGSTWRD]);
void ltrCnt(int strLen, const char srcArr[], int ltrTable[2][ALPHABET]);

int main(void)
{
	/****main LOCAL VARIABLES****/
	int A2a = ('a'-'A');
		
	char myString[] = "The quick Brown Fox jumps over the Lazy Dog and the !##! LAZY DOG is still sleeping";
	char myStringLtrs[100];
	/****Pointers****/
	char *srcStrPtr = myString;
	char *tarStrPtr = myStringLtrs;
	/*
	char testStr[] = "ThIs #$&|";//TESTING PURPOSES
	char testStrLtrs[25];//TESTING PURPOSES
	//Pointers
	char *srcStrPtr = testStr;//TESTING PURPOSES
	char *tarStrPtr = testStrLtrs;//TESTING PURPOSES
	*/
	int strLen = 0;
	
	/*!!! 1st ROW MUST BE OUTPUT AS CHAR !!!*/
	/*!!! 2nd ROW MUST BE OUTPUT AS INT !!!*/
	int ltrFrqcy[2][ALPHABET];
	int ltrFrqcyRws = (sizeof(ltrFrqcy)/sizeof(int)/2);
	//printf("%d\n",ltrFrqcyRws);//TESTING PURPOSES
		for(int i=0; i <= ALPHABET-1; i++ )
		{
			ltrFrqcy[0][i]=(int)('a'+i);
			ltrFrqcy[1][i]= 0;
			//printf("%3c | %d\n",ltrFrqcy[0][i], ltrFrqcy[1][i]);//TESTING PURPOSES
		}
	
	int wrldLgth[2][LNGSTWRD];
	int WrldLgthRws = (sizeof(wrldLgth)/sizeof(int)/2);
		for(int i=0 ; i < WrldLgthRws; i++)
		{ 
			wrldLgth[0][i]= (1+i);
			wrldLgth[1][i]= 0;
			//printf("wrldLgth[0][%d]=%2d | wrldLgth[1][%d]=%2d\n", i, wrldLgth[0][i], i, wrldLgth[1][i]);//TESTING PURPOSES
		}
	
	makeLower(srcStrPtr, tarStrPtr);
	
	/****Dtrmn nbr lttrs in lwr chr array****/
	for(int i = 0; tarStrPtr[i] != '\0'; i++)
	{
		//printf("tarStrPtr[%d]=\t char %c\t dec %3d\t @ %x\n", i, *(tarStrPtr+i), tarStrPtr[i], &tarStrPtr[i]);//TESTING PURPOSES
		strLen = (i+1);
	}
	//printf("tarStrPtr[%d]=\t char %c\t dec %3d\t @ %x\n", strLen, (tarStrPtr+(strLen)), *(tarStrPtr+(strLen)), (tarStrPtr+strLen));//TESTING PURPOSES
	
	printf("Original text:\n%s\n\n",srcStrPtr);
		
	printf("Leters only:\n%s\n\n",tarStrPtr);
	
	wrdLgthCnt(strLen, tarStrPtr, wrldLgth);
	
	ltrCnt(strLen, tarStrPtr, ltrFrqcy);
	
	/**Formating Output**/
	printf("Letter\t| Count\n");
	for(int i = 0; i<ALPHABET; i++)
	{
		printf("%3c\t| %3d\n",ltrFrqcy[0][i], ltrFrqcy[1][i]);
	}
	
	printf("\nWord \nlength\t| Occurrences\n");
	for(int i = 0; i<LNGSTWRD;i++)
	{
		printf("%4d\t| %6d\n",wrldLgth[0][i], wrldLgth[1][i]);
	}
	
	return 0;
}

/***FUNCTIONS***/

void makeLower(const char * srcPtr, char *targPtr)
{
	/**makeLower LOCAL VARIABLES**/
	int A2a = ('a'-'A');
	
	for(int i=0, j=0; srcPtr[i]!='\0'; i++, j++)
	{
		//printf("%d\t%d\t", i,j);//TESTING PURPOSES
		//printf("%c\t(%x)\n", srcPtr[i], &srcPtr[i]);//TESTING PURPOSES
		
		if((srcPtr[i] >= 'a' && srcPtr[i] <= 'z') || srcPtr[i] == ' ')
		{
			targPtr[j] = srcPtr[i];
		}
		else if(srcPtr[i] >= 'A' && srcPtr[i] <= 'Z')
		{
			targPtr[j] = (srcPtr[i] + A2a);
		}
		else
		{
			j=j-1;
		}
		
		/**Fixing Multiple Spaces**/
		if(targPtr[j]==' ' && targPtr[j-1]==' ')
		{
			j=j-1;
		}
		/**String terminator**/
		targPtr[j+1]='\0';
		//printf("%c\t(%x)\n", targPtr[j], &targPtr[j]); //TESTING PURPOSES
	}
}

void wrdLgthCnt(int lngth, const char *srcPtr , int table[2][LNGSTWRD])
{
	for(int i=0, j=0; i < lngth;i++,j++)
	{
		//printf("%x (%c)(%d)\n", srcPtr+i, *(srcPtr+i),*(srcPtr+i));//TESTING PURPOSES
		if((*(srcPtr+i+1)) == ((char)32))
		{
			table[1][j] = ++table[1][j];
			//printf("i=%2d\nj=%2d\nWord length %d occurs %d\n", i, j, table[0][j], table[1][j]);//TESTING PURPOSES
		}
		else if((*(srcPtr+i)) == ((char)32))
		{
			j=-1;
			//printf("j=%2d\n",j);//TESTING PURPOSES
		}
		else if ((*(srcPtr+i+1)) == NULL)
		{
			table[1][j] = ++table[1][j];
			//printf("i=%2d\nj=%2d\nWord length %d occurs %d\n", i, j, table[0][j], table[1][j]);//TESTING PURPOSES
		}
	}
}

void ltrCnt(int strLen, const char srcArr[], int ltrTable[2][ALPHABET])
{
	for(int i = 0; i <= strLen; i++)
	{
		if('a' <= srcArr[i] && srcArr[i] <= 'z')
		{
			int tmp = ((int)srcArr[i] -97);
			ltrTable[1][(tmp)] = ++ltrTable[1][tmp];
			//printf("(%c)%d-97=%d\n",srcArr[i] ,(int)srcArr[i], ((int)srcArr[i]-97));//TESTING PURPOSES
			//printf("ltrTable[0][%d] is %c repeats %d\n", tmp, ltrTable[0][tmp], ltrTable[1][tmp]);//TESTING PURPOSES
		}
	}
}
