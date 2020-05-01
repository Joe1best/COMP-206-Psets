#include<math.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include"replace.h"

int main(int argc, char *argv[]){
	//Checks that the number of arguments given to the command line is correct. Else it prints the error message
	//below, along with an exit code of 1
	if (argc!=4){
		printf("You need to give this function arguments of type [FILENAME/PATH TO FILENAME] [WORD1] [WORD2]\n");
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
	if (!(fPointer=fopen(filename,"r"))|| tempFile == NULL){
		printf("Error, could not find file in location %s\n",filename);
		exit(1);
	}

	//Opens the input file
	fPointer = fopen(filename,"r");


	//Defining the three word variables
	char *word1 = argv[2];
	char *word2 = argv[3];

	//The result of the replace method	
	char *result;
	//To read each word in the file, I read every character in the file using fgetc(). Until I detect that the 
	//character is not an alphabet, I concatenate this character to the variable "word" forming a word in the
	//file. Once the word is done (detect a space or any other character than an alphabet), I use the replace
	//function and write that in the new file. 
	char word[1000]="";
	char c;
	int cond=0;
	while ((c=fgetc(fPointer)) !=EOF ) {
		//If the character is an alphabet (capital or lower case) (I check it using the ASCII value)
		if ((c>=65 && c<=90) || (c>=97 && c<=122)){	
			//Concatenate the character to the string word 
			strncat(word,&c,1);
		//If it is not an alphabet (a space, a tab, an enter, or any other symbols).
		} else {
			
			
			//Take care of the condition if the beginning of the file just starts with 
			//a weird character or the fact that there could be multiple spaces 
			if (strlen(word) >= 1 ){
				//Uses the replace function in replace.c
				result = replace(word,word1,word2);
				fputs(result,tempFile);
			}

			//Reset the word in order to start filling up the next one in the array
			word[0] = '\0';
			
			//Puts the character that is not an alphabet in the file 
			fputc(c,tempFile);
		}
	}
	
	//Closes both files
	fclose(fPointer);
	fclose(tempFile);

	//Remove the old file
	remove(filename);
	
	//Rename the temp one to the old filename
	rename("temp.txt", filename);
}
