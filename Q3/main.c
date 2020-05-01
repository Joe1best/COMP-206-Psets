#include<math.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include"replace.h"

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
	FILE *tempFile;
	
	//Opens the temp file that will later be replaced with the original file but words are replaced
	tempFile = fopen("temp.txt", "w");

	//Checks whether the file exists in the path given using the fopen() function, this method will attempt to 
	//open the file and will return false if it could not. 
	if (!(fPointer=fopen(filename,"r"))|| tempFile = NULL){
		printf("Error, could not find file in location %s",filename);
	}

	//Opens the input file
	fPointer = fopen(filename,"r");


	//Defining the three word variables
	char *word1 = argv[2];
	char *word2 = argv[3];
	char word[1000];

	//The result of the replace method
	//
	char *result;
	//To read each word in the file, I use the fscanf function, This function will read the file fPointer based 
	//on the type of argument given (string, hence %s) and how long this argument is expected to be (in our case, 
	//max 1000 word length) and it saves the word in the "word" variable
	while (fscanf(fPointer, "%1000s",word) ==1) {
		result = replace(word, word1, word2);
		fputs(result,tempFile);

	}

	fclose(fPointer);
	fclose(tempFile);

	remove(filename);

	rename("temp.txt", path);
}
