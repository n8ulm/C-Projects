/*
 * FibonacciSequence.c
 *
 *  Created on: Sep 17, 2017
 *      Author: ndu2784
 */

#include <stdio.h>
//includes stdio header file in order to access standard
//input output functions
#include <stdlib.h>
//include stdlib header file in order to access standard functions

int main(int argc, char **argv) {
//:Fibonacci Sequence Homework Assignment 1

	FILE *FibonacciFile = fopen("MyFibonacci.txt", "w");
//Declare and Initialize FILE object, file path given, will create new file.
//set to write to the file

	if (NULL == FibonacciFile) {
		printf("File not opened\n");
		return (1);
	}
//checks for null pointer, alerts user

	int Iterations;
//int declared to set number of iterations defined by user input
	int PerLine;
//int declared to set number of outputs per line

	printf("Enter number(int) of Fibonacci numbers to be output: ");
	scanf("%d", &Iterations);
//prompts user for int; sets Iterations to input value.

	printf("\nEnter number(int) of Fibonacci numbers output per line: ");
	scanf("%d", &PerLine);
//prompts user for int; sets PerLine to input value.

	int FibonacciSequence[100];
	FibonacciSequence[0] = 0;
	FibonacciSequence[1] = 1;
	//Int array declared to hold Fibonacci sequence, first 2 indices initialized to set start point of sequence

	for (int i = 2; i < Iterations; i++) {
		FibonacciSequence[i] = FibonacciSequence[i - 1]
				+ FibonacciSequence[i - 2];
	}
	//Generates Fibonacci sequence by using F(n) = F(n-1) 11+ F(n-2) (counting from 0 of course)
	//Sets value to the i-th location in FibonacciSequence int array

	int count = 0;
	while (count != Iterations ) {
		for(int j = 0; j < PerLine; j++){
			if(count == Iterations){
				break;
			}
			//if statement ensures that values in the FiboSeq array indexed beyond the Iterations value will not be printed
			fprintf(FibonacciFile, "%-4d", FibonacciSequence[count++]);
			//count increases only when a number is printed out
		}
		fprintf(FibonacciFile, "\n");
	}
//The while loop allows the right number of iterations to be ran in order to print the desired number of FiboNumbers in total
	//The for loop allows the right number of FiboNumbers per line by breaking out of the for loop to trigger the next line

	fclose(FibonacciFile);

	return (0);
}
