// lab3.c - measure execution time of C code

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main ()
{
	const int MaxSize = 100000;
	int i, j, temp;


	// Part one: processing a statically allocated array

	clock_t begin = clock();

	int staticArray[MaxSize];		// declare an array 

	for (i=0; i<MaxSize; i++)		// initialize the array with a
		staticArray[i] = MaxSize-i;	// descending sequence of values

	for (i=0; i<MaxSize-1; i++)		// bubble sort data in the array
		for (j=MaxSize-1; j>i; j--)
			if (staticArray[j-1] > staticArray[j])
			{
				temp = staticArray[j-1];
				staticArray[j-1] = staticArray[j];
				staticArray[j] = temp;
			}

	clock_t end = clock();

	// Part two: processing a dynamically allocated array

	clock_t begin1 = clock();

	int * dynamicArray;		// declare an array 

	dynamicArray = (int*) malloc (MaxSize *sizeof (int));

	for (i=0; i<MaxSize; i++)		// initialize the array with a
		(*(dynamicArray + i)) = MaxSize-i;	// descending sequence of values

	for (i=0; i<MaxSize-1; i++)		// bubble sort data in the array
		for (j=MaxSize-1; j>i; j--)
			if ((*(dynamicArray + j-1)) > (*(dynamicArray + j)))
			{
				temp = (*(dynamicArray + j-1));
				(*(dynamicArray + j-1)) = (*(dynamicArray + j));
				(*(dynamicArray + j)) = temp;
			}			

	clock_t end1 = clock();






	// Display the amount of time used for each part above

	printf("Time used *staticArray*: %lf%s\n",(double)(end-begin)/ CLOCKS_PER_SEC, " Seconds");	
	printf("Time used *dynamicArray*: %lf%s\n",(double)(end1-begin1)/ CLOCKS_PER_SEC, " Seconds");




	return 0;
}
