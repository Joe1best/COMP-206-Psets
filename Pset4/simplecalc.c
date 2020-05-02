/*
Program to implement a simple calculator
*******************************************************
* Author                Dept.      Date         Notes
*******************************************************
* Youssef Bestavros     Physics    Feb 16 2020  Started the assignment
*/

//Importing libraries
#include <stdio.h>
#include <stdlib.h>

#define MIN_REQUIRED 4

//Main method
int main(int argc, char *argv[])
{
	//Checks to see if the number of arguments is respected
	if (argc != MIN_REQUIRED){
		printf("Error: usage is simplecalc <x> <op> <y>\n");
		exit(1);
	}
	
	//Type casting the two inputs into integers.
	int x = atoi(argv[1]);
	int y = atoi(argv[3]);
	char *op = argv[2];
	int result;
	
	//The different cases for each operator. 
	switch(*op){
		case '*' :
			result = x*y;
			printf("%d\n",result);
			exit(0);
		case '/' :
			result =x/y;
			printf("%d\n",result);
			exit(0);
		case '+' :
			result = x+y;
			printf("%d\n",result);
			exit(0);
		case '-' : 
			result = x-y;
			printf("%d\n",result);
			exit(0);
		default  : 
			printf("%c is not a valid operator \n", *op);
			exit(2);	
	}

}

