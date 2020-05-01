#include<math.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include"replace.c"

int main(int argc, char *argv[]){
	//Checks that the number of arguments given to the command line is correct. Else it prints the error message
	//below, along with an exit code of 1
	if (argc!=4){
		printf("You need to give this function arguments of type [FILENAME/PATH TO FILENAME] [WORD1] [WORD2]");
		exit(1);
	}	
	//File pointer
	char *filename = argv[1];
	
	FILE *fPointer; 

	//Checks whether the file exists in the path given using the fopen() function, this method will attempt to 
	//open the file and will return false if it could not. 
	if (!(fPointer=fopen(filename,"r"))){
		printf("Error, could not find file in location %s",filename);
	}

	//Opens the file
	fPointer = fopen(filename,"r");

	char word[1000];

	//To read each word in the file, I use the fscanf function, This function will read the file fPointer based 
	//on the type of argument given (string, hence %s) and how long this argument is expected to be (in our case, 
	//max 1000 word length) and it saves the word in the "word" variable
	while (fscanf(fPointer, "%1000s",word) ==1) {
		
	}
}
