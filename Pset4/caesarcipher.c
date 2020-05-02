/*
 * Program to implement a simple calculator
 * *******************************************************
 * * Author                Dept.      Date         Notes
 * *******************************************************
 * * Youssef Bestavros     Physics    Feb 16 2020 @5:15pm Started the assignment
 * * Youssef Bestavros     Physics    Feb 16 2020 @11:00pm Finished the assignment
 * */

//Imported libraries 
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <stdbool.h>

//Main function of the caesar cipher. 
int main(int args, char *argv[]){

	//Checks to see whether offset was inputed by the user. If not prints 
	//error messsage below and exists with code 1.
	if (args != 2){
		printf("Error: usage is ceasarcipher <offset>\n");
		exit(1);
	}
	
	//Creates an array of arbitray length for the message. I chose 399 for 
	//absolutely no reason. 
	char code[399];
	
	//Gets the offset using the atoi method that converts a string to an integer
	int offset=atoi(argv[1]);

	//Boolean for our while loop
	bool detect = true; 

	//While the detect variable is true, keep looping
	while (detect){

		//Detects when to end the loop. Either when their is a new line (\n and \r) or if there is an endline (when 
		//fgets returns NULL). Tjis exists with code(0) when it is done 
		if ((strlen(code) == 1 && (code[0]=='\n' || code[0]=='\r')) || fgets(code,sizeof(code),stdin)==NULL){
			detect = false;
			exit(0);
		}

		//for loop varible 
		int i;

		//Makes sure that the offset is within the alphabetical limit. Shifting by 27 is the same as shifted by 1
		if (offset<0){
			offset = -(abs(offset)%26);
		} else {
			offset = offset%26;
		}
		
		//Some variables initialization for the shift
		int diff;
		int az;
		for (i=0;i<strlen(code)-1;++i){

			//ignore anything that is not in the range of a to z. This will take care of UPPER case, 
			//spaces, punctuation, etc.
			if (code[i]<'a' || code[i]>'z'){
				continue;
			}
			
			//shifts the integer equivalent of the char by the offset
			az = code[i]+offset;
			
			//Below we take care of the integer if it bigger than the integer value of 'z' and when 
			//it is lower than the integer value of 'a'
			if (az<'a'){
				diff = 'a' - az;
	       			code[i] = (char) ('z' - diff + 1); 	
			} else if (az>'z'){
				diff = az - 'z'; 
				code[i] = (char) ('a' + diff - 1);
			} else {
				code[i] = (char) az;
			}
		}	
		printf("%s",code);//prints the message
	}
}



