/*
 * NumbersToLetters.c
 *
 *  Created on: Sep 24, 2017
 *      Author: ndu2784
 *
 */

#include <stdlib.h>
//includes standard library header file
#include <stdio.h>
//includes standard input and output header file
#include <string.h>

int main(int argc, char **argv){

	typedef struct{
		char *c;
	}String;
	//defines a data structure called String that holds a char array
	

	String *ones;
	ones = (String*) malloc(20 * sizeof(String));
	//declares and allocates memory for String array
	ones[0].c = "Zero";
	ones[1].c = "One";
	ones[2].c = "Two";
	ones[3].c = "Three";
	ones[4].c = "Four";
	ones[5].c = "Five";
	ones[6].c = "Six";
	ones[7].c = "Seven";
	ones[8].c = "Eight";
	ones[9].c = "Nine";
	ones[10].c = "Ten";
	ones[11].c = "Eleven";
	ones[12].c = "Twelve";
	ones[13].c = "Thirteen";
	ones[14].c = "Fourteen";
	ones[15].c = "Fifteen";
	ones[16].c = "Sixteen";
	ones[17].c = "Seventeen";
	ones[18].c = "Eighteen";
	ones[19].c = "Nineteen";
	//initializes char arrays at each index of String Array

	String *tens;
	tens = (String*) malloc(10 * sizeof(String));
	//declares and allocates memory for String array
	tens[0].c = "Zero";
	tens[1].c = "Ten";
	tens[2].c = "Twenty";
	tens[3].c = "Thirty";
	tens[4].c = "Forty";
	tens[5].c = "Fifty";
	tens[6].c = "Sixty";
	tens[7].c = "Seventy";
	tens[8].c = "Eighty";
	tens[9].c = "Ninety";
	//initializes char arrays at each index of String Array

	int leftOfPoint = 0;
	int rightOfPoint = 0;
	//declared integers to hold each side of decimal point

	char OutputString[100] = "";
	//final string to be output

	char OutputCheck[100] = "";
	//final string in check version

	printf("Enter value within range of 000.00 to 999.99 to be converted to text: ");
	scanf("%d.%d",  &leftOfPoint, &rightOfPoint);
	//asks user to input value to be converted to string
	//scanf sets left and right sides of decimal to respective variables declared above

	if(leftOfPoint > 999 || leftOfPoint < 0){
		printf("Incorrect Input");
		return(1);
	}
	//checks for inproper input
	if(rightOfPoint > 99 || rightOfPoint < 0){
		printf("Incorrect Input");
		return(1);
	}
	//checks for inproper input

	int hundredsPlace = leftOfPoint/100;
	int tensPlace;
	int onesPlace;

	if((leftOfPoint - hundredsPlace*100) < 20){
		tensPlace = (leftOfPoint-hundredsPlace*100);

	}
	else {
	tensPlace = (leftOfPoint-hundredsPlace*100)/10;
	onesPlace = (leftOfPoint-hundredsPlace*100-tensPlace*10);
	}

	int tenthsPlace = (rightOfPoint/10);
	int hundrethsPlace = (rightOfPoint - tenthsPlace*10);
	//finds 0-9 value of each decimal place

	if(leftOfPoint > 99){
		strcat(OutputString, ones[hundredsPlace].c);
		strcat(OutputString, " Hundred ");
	}
	//checks for 100s place and concats text conversion of number to output string

	if(leftOfPoint > 10){
	strcat(OutputString, tens[tensPlace].c);
	strcat(OutputString, " ");
	}
	//checks for 10s place and concats text conversion of number to output string

	if(leftOfPoint >= 0 && tensPlace > 19){
	strcat(OutputString, ones[onesPlace].c);
	strcat(OutputString, " ");
	}
	//checks for 1s place and concats text conversion of number to output string

	strcpy(OutputCheck, OutputString);
	//copies OutputCheck to OutputString before concating right values to OutputString

	strcat(OutputString, "Point ");
	//concats string point

	strcat(OutputString, ones[tenthsPlace].c);
	strcat(OutputString, " ");
	//concats tenths place

	strcat(OutputString, ones[hundrethsPlace].c);
	strcat(OutputString, " ");
	//concats hundreths place


	printf("\nNumber to Text Conversion: ");
	printf("%s\n\n", OutputString);
	//prints final output

	printf("Number to Text Check Format: ");
	printf("%sAnd %d/100", OutputCheck, rightOfPoint);
		//prints final output

	return(0);
}


